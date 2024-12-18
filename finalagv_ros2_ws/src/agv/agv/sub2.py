#sub.py
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String, Int32
from geometry_msgs.msg import Twist
from threading import Thread, Lock
from pymycobot.myagv import MyAgv
import time

# 전역 변수 및 잠금 객체 정의
motor_running = False  # motor_running을 False로 초기화하여 데이터가 수신될 때만 모터 작동
udp_run = True
qr_data = None
detected_data = None
offset = 0
offset_lock = Lock()
teleop_data = None
# yellow_detected = False

#teleop subscriber 클래스 -teleop데이터 수신
class TeleopSubscriber(Node):
    def __init__(self):
        super().__init__('teleop_subscriber')
        self.subscription = self.create_subscription(
            Twist,
            '/cmd_vel',  
            self.listener_callback,
            10
        )
        self.get_logger().info("Teleop Subscriber Node Started.")

    def listener_callback(self, msg):
        global teleop_data, motor_running
        teleop_data = str(int(msg.linear.x))  
        motor_running = True  
        self.get_logger().info(f"Received teleop data: {teleop_data}")
		
# QR Subscriber 클래스
class QRSubscriber(Node):
    def __init__(self):
        super().__init__('qr_subscriber')
        self.subscription = self.create_subscription(
            String,
            'qr_data',
            self.listener_callback,
            10
        )
        self.get_logger().info("QR Subscriber Node Started.")

    def listener_callback(self, msg):
        global qr_data, detected_data, motor_running
        qr_data = msg.data
        detected_data = msg.data
        motor_running = True 
        self.get_logger().info(f"Received QR data: {qr_data}")

# Offset Subscriber 클래스
class OffsetSubscriber(Node):
    def __init__(self):
        super().__init__('offset_subscriber')
        self.subscription = self.create_subscription(
            Int32,
            'offset_topic',
            self.listener_callback,
            10
        )
        self.get_logger().info("Offset Subscriber Node Started.")

    def listener_callback(self, msg):
        global offset, motor_running
        with offset_lock:
            offset = msg.data
        motor_running = True  
        self.get_logger().info(f"Received offset: {offset}")

# Yellow Subscriber 클래스
# class YellowSubscriber(Node):
#     def __init__(self):
#         super().__init__('yellow_subscriber')
#         self.subscription = self.create_subscription(
#             String,
#             'yellow_detected',
#             self.listener_callback,
#             10
#         )
#         self.get_logger().info("Yellow Subscriber Node Started.")

#     def listener_callback(self, msg):
#         global yellow_detected, motor_running
#         if msg.data == "Yellow detected!":
#             yellow_detected = True
#             motor_running = False 
#             self.get_logger().info("Yellow color detected. Motor stopped.")
#         else:
#             yellow_detected = False
        

# AGV 제어 스레드 클래스
class AgvControlThread(Thread):
    def __init__(self, myagv):
        Thread.__init__(self)
        self.myagv = myagv

    def run(self):
        global motor_running, udp_run, qr_data, detected_data, offset, teleop_data
        while udp_run:
            # Yellow color detection
            # if yellow_detected:
            #     print("Yellow color detected! Stopping AGV.")
            #     # self.myagv.stop()  # 모터 정지
            #     # motor_running = False
            #     time.sleep(3)
            #     # self.myagv.clockwise_rotation(1, 0.5)
            #     #self.myagv.go_ahead(1, 0.1)
            #     #time.sleep(3)
            #     yellow_detected = False  # 중복 처리 방지
            #     continue

            # QR 데이터 우선 처리
            if motor_running and qr_data ==  teleop_data:
                if qr_data == '1' and teleop_data == '1':
                    time.sleep(2)
                    print("QR detect '1'. AGV turn left.")
                    self.myagv.go_ahead(1, 1)
                    time.sleep(2)
                    self.myagv.counterclockwise_rotation(1, 2)
                    time.sleep(2)
                elif qr_data == '2' and teleop_data == '2':
                    time.sleep(2)
                    print("QR detect '2'. AGV turn left.")
                    self.myagv.go_ahead(1, 1)
                    time.sleep(2)
                    self.myagv.counterclockwise_rotation(1, 2)
                    time.sleep(2)
                elif qr_data == '3' and teleop_data == '3':
                    time.sleep(2)
                    print("QR detect '3'. AGV turn left.")
                    self.myagv.go_ahead(1, 0.5)
                    time.sleep(2)
                    self.myagv.counterclockwise_rotation(1, 2)
                    time.sleep(2)
                
                # QR 데이터 초기화 및 모터 정지
                qr_data = None
                detected_data = None 
                motor_running = False

            # QR 데이터가 '4'일 경우 처리
            # elif motor_running and qr_data == '4':
            #     print("QR 코드 데이터가 '4'입니다. 모터 정지 후 180도 회전.")
            #     self.myagv.stop()  # 모터 정지
            #     time.sleep(1)  # 정지 상태 유지
            #     self.myagv.clockwise_rotation(1, 3.5)
            #     time.sleep(180)
            #     self.myagv.go_ahead(1, 0.2)  # 180도 회전
            #     qr_data = None  # QR 데이터 초기화
            
            # QR 데이터가 없을 경우, Offset 데이터 처리
            elif motor_running and offset:
                with offset_lock:
                    current_offset = offset
                
                if 800 > current_offset > 55:
                    print(f'Object is {current_offset} pixels to the right. Moving AGV left')
                    self.myagv.clockwise_rotation(5, 0.4)
                elif -800 < current_offset < -55:
                    print(f'Object is {-current_offset} pixels to the right. Moving AGV right')
                    self.myagv.counterclockwise_rotation(5, 0.4)
                elif -55 <= current_offset <= 55:
                    print(f'Object is {current_offset} pixels aligned. go forward AGV.')
                    self.myagv.go_ahead(1, 0.1)
                    

                else:
                    self.myagv.stop()
                    time.sleep(5)
                    self.myagv.clockwise_rotation(1, 3.5)
                    self.myagv.stop()
                
                motor_running = False  
            
            time.sleep(0.2)

def main(args=None):
    # ROS2 초기화
    rclpy.init(args=args)

    # MyAgv 인스턴스 생성
    myagv = MyAgv('/dev/ttyAMA2', 115200)

    # Subscriber 노드 생성
    qr_subscriber = QRSubscriber()
    offset_subscriber = OffsetSubscriber()
    teleop_subscriber = TeleopSubscriber()
    # yellow_subscriber = YellowSubscriber()

    # AGV 제어 스레드 시작
    agv_control_thread = AgvControlThread(myagv)
    agv_control_thread.start()

    # MultiThreadedExecutor 사용
    executor = MultiThreadedExecutor()
    executor.add_node(qr_subscriber)
    executor.add_node(offset_subscriber)
    executor.add_node(teleop_subscriber)
    # executor.add_node(yellow_subscriber)

    try:
        executor.spin()
    finally:
        qr_subscriber.destroy_node()
        offset_subscriber.destroy_node()
        teleop_subscriber.destroy_node()
        # yellow_subscriber.destroy_node()
        rclpy.shutdown()
        agv_control_thread.join()

if __name__ == '__main__':
    main()

