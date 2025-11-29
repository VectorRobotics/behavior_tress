from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():

    tree_file_arg = DeclareLaunchArgument(
        "tree_file",
        default_value="share/humanoid_bt/trees/elev_bt.xml",
        description="Path to the behavior tree XML file"
    )

    bt_node = Node(
        package="humanoid_bt",
        executable="elev_bt_runner",
        name="elev_bt_runner",
        output="screen",
        parameters=[
            {"tree_file": LaunchConfiguration("tree_file")}
        ]
    )

    return LaunchDescription([
        tree_file_arg,
        bt_node
    ])
