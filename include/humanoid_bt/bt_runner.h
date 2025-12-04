#pragma once

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <behaviortree_cpp/bt_factory.h>

class BTRunner
{
  private:
    std::string tree_file_;
    rclcpp::Node::SharedPtr node;
    BT::Tree tree;
  public:
    BTRunner(const std::string& tree_file, const std::string& name);

    void run();
};