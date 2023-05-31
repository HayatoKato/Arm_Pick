import launch
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="catch_cola_smach",
            executable="catch_cola_smach_node",
            on_exit=launch.actions.Shutdown(),
        ),
        Node(
            package="detection_aruco",
            executable="detection_aruco_node",
            output="screen",
        ),
        Node(
            package="detection_frcnn",
            executable="detection_frcnn_node",
            output="screen",
        ),
        Node(
            package="transformation_axis",
            executable="transformation_axis_node",
            output="screen",
        ),
        Node(
            package="control_arm",
            executable="control_arm_node",
            output="screen",
        ),
        Node(
            package="usb_cam",
            executable="usb_cam_node_exe",
        ),
    ])
