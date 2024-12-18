import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String, Int32, Bool
from geometry_msgs.msg import Twist
from threading import Thread, Lock
from pymycobot.myagv import MyAgv
import time


class SharedState:
    """AGV의 공유 상태를 관리하는 클래스"""
    def __init__(self):
        self.offset = 0
        self.qr_data = None
        self.teleop_data = None
        self.yellow_line_detected = False
        self.motor_running = False
        self.lock = Lock()

    def update(self, key, value):
        with self.lock:
            setattr(self, key, value)

    def get(self, key):
        with self.lock:
            return getattr(self, key)


class TeleopSubscriber(Node):
    def __init__(self, shared_state):
        super().__init__('teleop_subscriber')
        self.shared_state = shared_state
        self.subscription = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.listener_callback,
            10
        )
        self.get_logger().info("Teleop Subscriber Node Started.")

    def listener_callback(self, msg):
        self.shared_state.update('teleop_data', str(int(msg.linear.x)))
        self.shared_state.update('motor_running', True)
        self.get_logger().info(f"Received teleop data: {msg.linear.x}")


class QRSubscriber(Node):
    def __init__(self, shared_state):
        super().__init__('qr_subscriber')
        self.shared_state = shared_state
        self.subscription = self.create_subscription(
            String,
            'qr_data',
            self.listener_callback,
            10
        )
        self.get_logger().info("QR Subscriber Node Started.")

    def listener_callback(self, msg):
        self.shared_state.update('qr_data', msg.data)
        self.shared_state.update('motor_running', True)
        self.get_logger().info(f"Received QR data: {msg.data}")


class OffsetSubscriber(Node):
    def __init__(self, shared_state):
        super().__init__('offset_subscriber')
        self.shared_state = shared_state
        self.subscription = self.create_subscription(
            Int32,
            'offset_topic',
            self.listener_callback,
            10
        )
        self.get_logger().info("Offset Subscriber Node Started.")

    def listener_callback(self, msg):
        self.shared_state.update('offset', msg.data)
        self.shared_state.update('motor_running', True)
        self.get_logger().info(f"Received offset: {msg.data}")


class YellowLineSubscriber(Node):
    def __init__(self, shared_state):
        super().__init__('yellow_line_subscriber')
        self.shared_state = shared_state
        self.subscription = self.create_subscription(
            Bool,
            'yellow_line_detected',
            self.listener_callback,
            10
        )
        self.get_logger().info("Yellow Line Subscriber Node Started.")

    def listener_callback(self, msg):
        self.shared_state.update('yellow_line_detected', msg.data)
        if msg.data:
            self.get_logger().info("Yellow line detected. Stopping AGV.")


class AgvControlThread(Thread):
    def __init__(self, myagv, shared_state):
        super().__init__()
        self.myagv = myagv
        self.shared_state = shared_state

    def run(self):
        while True:
            yellow_detected = self.shared_state.get('yellow_line_detected')
            if yellow_detected:
                print("Yellow line detected. Waiting...")
                time.sleep(2)
                self.shared_state.update('yellow_line_detected', False)
                continue

            motor_running = self.shared_state.get('motor_running')
            if motor_running:
                self.handle_qr_code()
                self.handle_offset()

            time.sleep(0.2)

    def handle_qr_code(self):
        qr_data = self.shared_state.get('qr_data')
        teleop_data = self.shared_state.get('teleop_data')

        if qr_data == teleop_data:
            try:
                if qr_data == '1':
                    print("Executing CORNERING for QR data 1")
                    self.myagv.go_ahead(5, 2)
                    self.myagv.clockwise_rotation(5, 2.5)
                elif qr_data == '2':
                    print("Executing BACKWARD for QR data 2")
                    self.myagv.go_ahead(5, 2)
                    self.myagv.clockwise_rotation(5, 2.5)
                elif qr_data == '3':
                    print("Executing BACKWARD for QR data 3")
                    self.myagv.go_ahead(5, 2.5)
                    self.myagv.clockwise_rotation(5, 2.5)

                self.shared_state.update('qr_data', None)
                self.shared_state.update('motor_running', False)
            except Exception as e:
                print(f"Error during QR handling: {e}")

    def handle_offset(self):
        offset = self.shared_state.get('offset')
        try:
            if 800 > offset > 50:
                print(f"Offset {offset}: Moving left")
                self.myagv.clockwise_rotation(5, 0.2)
            elif -800 < offset < -50:
                print(f"Offset {offset}: Moving right")
                self.myagv.counterclockwise_rotation(5, 0.2)
            elif -50 <= offset <= 50:
                print(f"Offset {offset}: Aligned. Stopping AGV.")
                self.myagv._mesg(128 + 8, 128, 128)
            else:
                self.myagv.stop()

            self.shared_state.update('motor_running', False)
        except Exception as e:
            print(f"Error during offset handling: {e}")


def main(args=None):
    rclpy.init(args=args)

    shared_state = SharedState()
    myagv = MyAgv('/dev/ttyAMA2', 115200)

    qr_subscriber = QRSubscriber(shared_state)
    offset_subscriber = OffsetSubscriber(shared_state)
    teleop_subscriber = TeleopSubscriber(shared_state)
    yellow_line_subscriber = YellowLineSubscriber(shared_state)

    agv_control_thread = AgvControlThread(myagv, shared_state)
    agv_control_thread.start()

    executor = MultiThreadedExecutor()
    executor.add_node(qr_subscriber)
    executor.add_node(offset_subscriber)
    executor.add_node(teleop_subscriber)
    executor.add_node(yellow_line_subscriber)

    try:
        executor.spin()
    finally:
        qr_subscriber.destroy_node()
        offset_subscriber.destroy_node()
        teleop_subscriber.destroy_node()
        yellow_line_subscriber.destroy_node()
        rclpy.shutdown()
        agv_control_thread.join()


if __name__ == '__main__':
    main()
