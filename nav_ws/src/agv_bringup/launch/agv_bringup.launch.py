#!/usr/bin/env python3

# Author: Bishop Pearson

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import ThisLaunchFileDir


def generate_launch_description():
  # agv_mcu_parameter = LaunchConfiguration(
  #   'agv_mcu_parameter',
  #   default=os.path.join(
  #     get_package_share_directory('agv_bringup'),
  #     'param/agv_mcu.yaml'
  #   )
  # )

  agv_lidar_parameter = LaunchConfiguration(
    'agv_lidar_parameter',
    default=os.path.join(
      get_package_share_directory('agv_bringup'),
      'param/agv_lidar.yaml'
    )
  )

  use_sim_time = LaunchConfiguration('use_sim_time', default='false')

  agv_description_dir = LaunchConfiguration(
    'agv_description_dir',
    default=os.path.join(
      get_package_share_directory('agv_description'),
      'launch'
    )
  )

  return LaunchDescription([
    # DeclareLaunchArgument(
    #   'agv_mcu_parameter',
    #   default_value=agv_mcu_parameter
    # ),

    DeclareLaunchArgument(
      'agv_lidar_parameter',
      default_value=agv_lidar_parameter
    ),

    # IncludeLaunchDescription(
    #   PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/agv_mcu.launch.py']),
    #   launch_arguments={'agv_mcu_parameter': agv_mcu_parameter}.items()
    # ),
    
    IncludeLaunchDescription(
      PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/agv_lidar.launch.py']),
      launch_arguments={'agv_lidar_parameter': agv_lidar_parameter}.items()
    ),
    
    IncludeLaunchDescription(
      PythonLaunchDescriptionSource([agv_description_dir, '/agv_state_publisher.launch.py']),
      launch_arguments={'use_sim_time': use_sim_time}.items(),
    ),
  ])
