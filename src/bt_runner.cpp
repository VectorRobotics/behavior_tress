#include <rclcpp/rclcpp.hpp>
#include <behaviortree_ros2/ros_node_params.hpp>
#include <behaviortree_cpp/bt_factory.h>
#include <filesystem>

#include "humanoid_bt/clients/clients.h"

#include "humanoid_bt/bt_runner.h"

namespace fs = std::filesystem;

BTRunner::BTRunner(const std::string& tree_file,const std::string& name)
: tree_file_(tree_file)
{

    this->node = std::make_shared<rclcpp::Node>(name);

    BT::BehaviorTreeFactory factory;

    // Register basic ROS2 nodes
    BT::RosNodeParams params;
    params.nh = this->node;

    /* /////////////////////////////////////
    REGISTER ALL NODES WITH THE FACTORY HERE
    //////////////////////////////////////*/

    factory.registerNodeType<Navigate>("Navigate", params);
    factory.registerNodeType<DetectButtonPos>("DetectButtonPos", params);
    factory.registerNodeType<ManipulateToPos>("ManipulateToPos", params);
    factory.registerNodeType<PressButton>("PressButton", params);
    factory.registerNodeType<RecheckCurrentFloor>("RecheckCurrentFloor", params);
    factory.registerNodeType<DetectDoorOpen>("DetectDoorOpen", params);
    factory.registerNodeType<BaseActionClient>("BaseActionClient", params);

    /////////////////////////////////////////

    this->tree = factory.createTreeFromFile(tree_file_);
}

void BTRunner::run()
{
    rclcpp::Rate rate(10);
    while (rclcpp::ok()) {
        this->tree.tickOnce();
        rclcpp::spin_some(this->node);
        rate.sleep();
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::string tree_file =
        (argc > 1) ? argv[1] : "share/humanoid_bt/trees/nav_bt.xml";

    std::string name =
        (argc > 2) ? argv[2] : fs::path(tree_file).stem().string();

    

    BTRunner runner(tree_file, name);
    runner.run();

    rclcpp::shutdown();
    return 0;
}
