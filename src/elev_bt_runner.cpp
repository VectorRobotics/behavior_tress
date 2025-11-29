#include "humanoid_bt/elev_bt_runner.h"
#include <rclcpp/rclcpp.hpp>
#include <behaviortree_ros2/ros_node_params.hpp>
#include <behaviortree_cpp/bt_factory.h>

using namespace humanoid_bt;

ElevBTRunner::ElevBTRunner(const std::string& tree_file)
: tree_file_(tree_file)
{}

void ElevBTRunner::run()
{
  rclcpp::Node::SharedPtr node = std::make_shared<rclcpp::Node>("elev_bt_runner");

  BT::BehaviorTreeFactory factory;

  // Register basic ROS2 nodes
  BT::RosNodeParams params;
  params.nh = node;

  auto tree = factory.createTreeFromFile(tree_file_);

  rclcpp::Rate rate(10);
  while (rclcpp::ok()) {
    tree.tickOnce();
    rclcpp::spin_some(node);
    rate.sleep();
  }
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::string tree_file =
    (argc > 1) ? argv[1] : "share/humanoid_bt/trees/elev_bt.xml";

  ElevBTRunner runner(tree_file);
  runner.run();

  rclcpp::shutdown();
  return 0;
}
