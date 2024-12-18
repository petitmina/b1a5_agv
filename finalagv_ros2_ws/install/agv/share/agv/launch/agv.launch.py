from launch import LaunchDescription
from launch.actions import TimerAction
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # pub.py 실행
        Node(
            package='agv',
            executable='pub',
            name='agv_pub',
            output='screen'
        ),

        Node(
            package='agv',
            executable='sub',
            name='agv_sub',
            output='screen'
        ),

    ])
