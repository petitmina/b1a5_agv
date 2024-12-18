import cv2
import numpy as np
import time
import threading
from threading import Thread
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import Int32, String, Bool
import pyzbar.pyzbar as pyzbar


class VideoProcessingThread(Thread):
    def __init__(self, width):
        super().__init__()
        self.width = width
        self.vid = cv2.VideoCapture(0)
        self.line_frame = None
        self.offset = 0
        self.qr_data = None
        self.yellow_detected = False
        self.udp_run = True
        self.offset_lock = threading.Lock()
        self.frame_lock = threading.Lock()

    def run(self):
        while self.udp_run:
            try:
                ret, new_frame = self.vid.read()
                if not ret:
                    print("Failed to read from camera")
                    time.sleep(0.1)
                    continue

                new_frame = cv2.resize(new_frame, (self.width, int(self.width * 0.75)))
                height, width, _ = new_frame.shape

                # 프레임의 하단 부분만 라인 감지용으로 사용
                with self.frame_lock:
                    self.line_frame = new_frame[height * 3 // 5 :, :].copy()

                self.detect_red_line(width)
                self.detect_yellow_line()
                self.detect_qr_code(new_frame)

                # 결과 화면 표시
                cv2.imshow("Line Detection", self.line_frame)
                cv2.imshow("QR Code Scanner", new_frame)

                # 'q'를 누르면 종료
                if cv2.waitKey(10) == ord('q'):
                    self.udp_run = False
            except Exception as e:
                print(f"Error during video processing: {e}")
                break

        self.vid.release()
        cv2.destroyAllWindows()

    def detect_red_line(self, width):
        img_hsv = cv2.cvtColor(self.line_frame, cv2.COLOR_BGR2HSV)
        lower_red1 = np.array([0, 50, 50])
        upper_red1 = np.array([10, 255, 255])
        lower_red2 = np.array([170, 50, 50])
        upper_red2 = np.array([180, 255, 255])

        mask1 = cv2.inRange(img_hsv, lower_red1, upper_red1)
        mask2 = cv2.inRange(img_hsv, lower_red2, upper_red2)
        mask = mask1 + mask2

        kernel = np.ones((5, 5), np.uint8)
        mask_red = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        mask_red = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)

        contours, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if contours:
            max_contour = max(contours, key=cv2.contourArea)
            if cv2.contourArea(max_contour) > 1000:
                M = cv2.moments(max_contour)
                if M["m00"] != 0:
                    cx = int(M["m10"] / M["m00"])
                    with self.offset_lock:
                        self.offset = cx - width // 2
                    print(f"Calculated offset: {self.offset}")
        else:
            with self.offset_lock:
                self.offset = -900
            print("No red line detected")

    def detect_yellow_line(self):
        img_hsv = cv2.cvtColor(self.line_frame, cv2.COLOR_BGR2HSV)
        lower_yellow = np.array([22, 100, 100])
        upper_yellow = np.array([28, 255, 255])
        mask_yellow = cv2.inRange(img_hsv, lower_yellow, upper_yellow)

        kernel = np.ones((5, 5), np.uint8)
        mask_yellow = cv2.morphologyEx(mask_yellow, cv2.MORPH_CLOSE, kernel)
        mask_yellow = cv2.morphologyEx(mask_yellow, cv2.MORPH_OPEN, kernel)

        self.yellow_detected = mask_yellow.any()

    def detect_qr_code(self, frame):
        decoded_objects = pyzbar.decode(frame)
        for obj in decoded_objects:
            self.qr_data = obj.data.decode('utf-8')
            print(f"Detected QR Code: {self.qr_data}")
            (x, y, w, h) = obj.rect
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)


class OffsetPublisher(Node):
    def __init__(self, video_thread):
        super().__init__('offset_publisher')
        self.video_thread = video_thread
        self.publisher_ = self.create_publisher(Int32, 'offset_topic', 10)
        self.timer = self.create_timer(0.1, self.publish_offset)

    def publish_offset(self):
        with self.video_thread.offset_lock:
            offset_msg = Int32(data=self.video_thread.offset)
        self.publisher_.publish(offset_msg)


class QRCodePublisher(Node):
    def __init__(self, video_thread):
        super().__init__('qr_code_publisher')
        self.video_thread = video_thread
        self.publisher_ = self.create_publisher(String, 'qr_data', 10)
        self.timer = self.create_timer(0.5, self.publish_qr_data)

    def publish_qr_data(self):
        if self.video_thread.qr_data:
            qr_msg = String(data=self.video_thread.qr_data)
            self.publisher_.publish(qr_msg)
            self.video_thread.qr_data = None


class YellowLinePublisher(Node):
    def __init__(self, video_thread):
        super().__init__('yellow_line_publisher')
        self.video_thread = video_thread
        self.publisher_ = self.create_publisher(Bool, 'yellow_line_detected', 10)
        self.timer = self.create_timer(0.1, self.publish_yellow_line)

    def publish_yellow_line(self):
        yellow_msg = Bool(data=self.video_thread.yellow_detected)
        self.publisher_.publish(yellow_msg)


def main(args=None):
    rclpy.init(args=args)

    video_thread = VideoProcessingThread(width=400)
    video_thread.start()

    offset_publisher = OffsetPublisher(video_thread)
    qr_code_publisher = QRCodePublisher(video_thread)
    yellow_line_publisher = YellowLinePublisher(video_thread)

    executor = MultiThreadedExecutor()
    executor.add_node(offset_publisher)
    executor.add_node(qr_code_publisher)
    executor.add_node(yellow_line_publisher)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        video_thread.udp_run = False
        video_thread.join()
        executor.shutdown()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
