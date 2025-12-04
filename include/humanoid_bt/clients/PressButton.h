#pragma once

#include "humanoid_bt/clients/base.h"
#include <behaviortree_ros2/ros_node_params.hpp>



class PressButton: public BaseActionClient
{
public:
  PressButton(const std::string& name,
                  const NodeConfig& conf,
                  const RosNodeParams& params)
    : BaseActionClient(name, conf, params)
  {}

    /// TODO
};