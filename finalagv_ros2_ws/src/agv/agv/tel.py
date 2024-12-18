import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys, select, termios, tty

msg = """
Control myagv!
---------------------------
QR code based commands:
1 : QR data '1' - start motor
2 : QR data '2' - start motor
3 : QR data '3' - start motor
4 : QR data '4' - start motor

q : exit program

CTRL-C to quit
"""

def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def main():
    global settings
    settings = termios.tcgetattr(sys.stdin)
    
    rclpy.init(args=None)
    node = rclpy.create_node('myagv_teleop_ros2')
    pub = node.create_publisher(Twist, '/cmd_vel', 10)  # qr_data 토픽으로 발행

    try:
        print(msg)
        while True:
            key = getKey()
            twist = Twist()

            if key == '1':
                print("Key '1' pressed. Sending QR data '1'.")
                twist.linear.x = 1.0
                pub.publish(twist)
            elif key == '2':
                print("Key '2' pressed. Sending QR data '2'.")
                twist.linear.x = 2.0
                pub.publish(twist)
            elif key == '3':
                print("Key '3' pressed. Sending QR data '3'.")
                twist.linear.x = 3.0
                pub.publish(twist)
            elif key == '4':
                print("Key '4' pressed. Sending QR data '4'.")
                twist.linear.x = 4.0
                pub.publish(twist)
            elif key == 'q':
                print("Exiting program...")
                break
            elif key == '\x04':
                break

    except Exception as e:
        print(e)

    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
