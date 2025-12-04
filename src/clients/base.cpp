#include "behaviortree_ros2/bt_action_node.hpp"
#include "humanoid_bt/clients/base.h"

#include "btcpp_ros2_interfaces/action/sleep.hpp"

using namespace BT;

using Base = btcpp_ros2_interfaces::action::Sleep;
using GoalHandleBase = rclcpp_action::ServerGoalHandle<Base>;

PortsList BaseActionClient::providedPorts()
{
return providedBasicPorts(
    {
        InputPort<unsigned>("order"),
    }
);
}

bool BaseActionClient::setGoal(RosActionNode::Goal& goal) 
{
    return true;
}
  
NodeStatus BaseActionClient::onResultReceived(const WrappedResult& wr)
{
    std::stringstream ss;
    ss << "Result received: ";
    auto number = wr.result->done;
    ss << number << " ";
    RCLCPP_INFO(node_.lock()->get_logger(), ss.str().c_str());
    return NodeStatus::SUCCESS;
}

NodeStatus BaseActionClient::onFailure(ActionNodeErrorCode error)
{
    RCLCPP_ERROR(node_.lock()->get_logger(), "Error: %d", error);
    return NodeStatus::FAILURE;
}

NodeStatus BaseActionClient::onFeedback(const std::shared_ptr<const Feedback> feedback)
{
    std::stringstream ss;
    ss << "Next number in sequence received: ";
    auto number = feedback->cycle;
    ss << number << " ";
    RCLCPP_INFO(node_.lock()->get_logger(), ss.str().c_str());
    return NodeStatus::RUNNING;
}
