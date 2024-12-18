#pub.py
import cv2
import numpy as np
import time
import threading
from threading import Thread
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, String
import pyzbar.pyzbar as pyzbar
# from pymycobot.myagv import MyAgv

# 전역 변수와 잠금 객체 정의
line_frame = None
offset = 0
# yellow_detected = False
udp_run = True
motor_running = True 
frame_lock = threading.Lock()
offset_lock = threading.Lock()
qr_data = None

# Camera matrix and distortion coefficients from your calibration
# mtx = np.array([[359.0743755, 0., 323.86664756],
#                 [0., 358.50277042, 282.06423693],
#                 [0., 0., 1.]])  # Camera matrix

# dist = np.array([-0.34726127,  0.11351076, -0.00775499, -0.00529497, -0.01801306])  # Distortion coefficients

class VideoProcessingThread(Thread):
    def __init__(self, width):
        Thread.__init__(self)
        self.width = width
        self.vid = cv2.VideoCapture(0)
        # self.vid.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
        # self.vid.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)
        self.vid.set(cv2.CAP_PROP_FPS, 15)
        self.vid.set(cv2.CAP_PROP_BUFFERSIZE, 5)
        # self.myagv = myagv
        
    def run(self):
        global line_frame, offset, yellow_detected, udp_run, motor_running, qr_data

        while udp_run:
            for _ in range(5):
                self.vid.grab()
            ret, new_frame = self.vid.retrieve()
            if not ret:
                continue
            new_frame = cv2.resize(new_frame, (self.width, int(self.width * 0.75)))
            height, width, _ = new_frame.shape

            # 라인 감지용 프레임 분리
            with frame_lock:
                line_frame = new_frame[height * 3 // 5:, :].copy()

            # 빨간색 감지 및 오프셋 계산
            img_hsv = cv2.cvtColor(line_frame, cv2.COLOR_BGR2HSV)
            lower_red1 = np.array([0, 50, 50])
            upper_red1 = np.array([10, 255, 255])
            lower_red2 = np.array([170, 50, 50])
            upper_red2 = np.array([180, 255, 255])

            mask1 = cv2.inRange(img_hsv, lower_red1, upper_red1)
            mask2 = cv2.inRange(img_hsv, lower_red2, upper_red2)
            mask = mask1 + mask2

            kernel = np.ones((2, 2), np.uint8)
            mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
            mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)

            # 윤곽선 감지
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            if contours:
                max_contour = max(contours, key=cv2.contourArea)
                if cv2.contourArea(max_contour) > 1000:
                    cv2.drawContours(line_frame, [max_contour], -1, (0, 255, 0), 2)
                    x, y, w, h = cv2.boundingRect(max_contour)
                    cv2.rectangle(line_frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
                    M = cv2.moments(max_contour)
                    if M["m00"] != 0:
                        cx = int(M["m10"] / M["m00"])
                        cy = int(M["m01"] / M["m00"])
                        cv2.circle(line_frame, (cx, cy), 10, (0, 255, 0), -1)

                        with offset_lock:
                            # frame_center = (width * 5 // 6 - width // 6) // 2 + width // 6
                            offset = cx - width // 2
                            # offset = cx - frame_center
                        print(f"Calculated offset: {offset}")
            else:

                print("no find line")
                motor_running = False
                # self.myagv.stop()
                # time.sleep(0.2)
                # with offset_lock:
                offset = -900
                if offset == -900:
                    print(f'offset is 900, stop!!!')
                    motor_running = False
            

            #yellow detection
            # lower_yellow = np.array([20, 100, 100])  
            # upper_yellow = np.array([30, 255, 255])  
            # yellow_mask = cv2.inRange(img_hsv, lower_yellow, upper_yellow)
            # yellow_detected = np.any(yellow_mask > 0)
            # if yellow_detected:
            #     print("Yellow color detected! Stopping AGV")
            #     motor_running = False
            #     continue

            # QR 코드 인식
            with frame_lock:
                qr_frame = new_frame.copy()
            decoded_objects = pyzbar.decode(qr_frame)
            for obj in decoded_objects:   
                qr_data = obj.data.decode('utf-8')
                print(f"Detected QR Code: {qr_data}")
                # cv2.rectangle(qr_frame, (x,y),(x+w, y+h),(0,255,0),2)
                # if decoded_objects == qr_data:
                #     motor_running = True 
                cv2.rectangle(qr_frame, (obj.rect.left, obj.rect.top), (obj.rect.left + obj.rect.width, obj.rect.top + obj.rect.height), (0, 255, 0), 2)

                motor_running = True #origin is True    
                                   
            # show line detection & QR code
            cv2.imshow('Line Detection', line_frame)
            cv2.imshow('QR Code Scanner', qr_frame)
            
            
            if cv2.waitKey(1) == ord('q'):
                udp_run = False
                break

        self.vid.release()
        cv2.destroyAllWindows()

class OffsetPublisher(Node):
    def __init__(self):
        super().__init__('offset_publisher')
        self.publisher_ = self.create_publisher(Int32, 'offset_topic', 10)
        self.timer = self.create_timer(0.1, self.publish_offset)
        self.get_logger().info("Offset Publisher Node Started.")

    def publish_offset(self):
        global offset
        if udp_run:
            with offset_lock:
                offset_msg = Int32()
                offset_msg.data = offset
                self.publisher_.publish(offset_msg)
                self.get_logger().info(f"Published offset: {offset_msg.data}")            

class QRCodePublisher(Node):
    def __init__(self):
        super().__init__('qr_pub')
        self.publisher_ = self.create_publisher(String, 'qr_data', 10)
        self.timer = self.create_timer(0.5, self.publish_qr_data)
        self.get_logger().info("QR Code Publisher Started")
        qr_data = None

    def publish_qr_data(self):
        global qr_data
        if qr_data:
            self.publisher_.publish(String(data=qr_data))
            self.get_logger().info(f"Published QR data: {qr_data}")
            qr_data = None  # 중복 발행 방지를 위해 데이터 초기화

# class YellowPublisher(Node):
#     def __init__(self):
#         super().__init__('yellow_publisher')
#         self.publisher_ = self.create_publisher(String, 'yellow_detected', 10)
#         self.timer = self.create_timer(0.5, self.publish_yellow_status)
#         self.get_logger().info("Yellow Color Publisher Started.")

#     def publish_yellow_status(self):
#         global yellow_detected
#         if yellow_detected:
#             self.publisher_.publish(String(data="Yellow detected!"))
#             self.get_logger().info("Published Yellow detection message.")

def main(args=None):
    # ROS2 초기화
    rclpy.init(args=args)

    # myagv = MyAgv('/dev/ttyAMA2', 115200)

    # Video Processing Thread 시작 및 VideoCapture 객체 공유
    video_thread = VideoProcessingThread(width=400)
    # video_thread = VideoProcessingThread(myagv)
    video_thread.start()

    # Offset Publisher Node 및 QR Code Publisher Node 생성
    offset_publisher = OffsetPublisher()
    qr_code_publisher = QRCodePublisher()
    # yellow_publisher = YellowPublisher()

    try:
        while rclpy.ok() and udp_run:
            # 각 노드를 개별적으로 spin_once()하여 타이머 콜백을 실행
            rclpy.spin_once(offset_publisher, timeout_sec=0.1)
            rclpy.spin_once(qr_code_publisher, timeout_sec=0.1)
            # rclpy.spin_once(yellow_publisher, timeout_sec=0.1)

    except KeyboardInterrupt:
        pass
    finally:
        video_thread.join()
        offset_publisher.destroy_node()
        qr_code_publisher.destroy_node()
        # yellow_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
