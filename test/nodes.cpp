#include <humanoid_bt_tests/nodes.h>
#include <behaviortree_cpp/action_node.h>
using namespace BT;

NodeStatus Test::onStart() {
    char s;
    std::cin >> s;
    switch (s){
        case 's':
            return NodeStatus::SUCCESS;
        case 'f':
            return NodeStatus::FAILURE;
        case 'r':
            return NodeStatus::RUNNING;
        default:
            std::cout << "Invalid input, returning FAILURE by default" << std::endl;
            return NodeStatus::FAILURE;
    }
}
NodeStatus Test::onRunning() {
    return Test::onStart();
}

void Test::onHalted() {
    std::cout << "Test: " << this->name() << " has been HALTED." << std::endl;
}

NodeStatus Navigate::onStart() {
    Expected<std::string> goal_pos = getInput<std::string>("goal_pos");
    if (!goal_pos)
    {
        throw RuntimeError("Navigate: missing required input [goal_pos]: ", goal_pos.error());
    }
    goal_pos_ = goal_pos.value();
    init_pos_ = "amcl_na_pos"; // This would be obtained from the robot's state in a real scenario
    setOutput<std::string>("initial_pos", this->init_pos_);
    std::cout << "Asked to navigate to position: " 
              << goal_pos.value()
              << ". I am currently at "
              << init_pos_
              << ". (s/r/f): " ;

    return Test::onStart();
}

NodeStatus Navigate::onRunning() {
    std::cout << "Enroute to position: " 
            << this->goal_pos_
            << ". (s/r/f): " ;

    return Test::onRunning();
}

NodeStatus DetectButtonPos::onStart() {
    Expected<std::string> button_text = getInput<std::string>("button_text");
    if (!button_text)
    {
        throw RuntimeError("DetectButtonPos: missing required input [button_text]: ", button_text.error());
    }
    std::cout << "Asked to detect button with text: " 
              << button_text.value()
              << ". (s/r/f): " ;

    NodeStatus input = Test::onStart();
    if (input == NodeStatus::SUCCESS) {
        setOutput<std::string>("button_pos", "def_pose_detected");
    }
    return input;
}

NodeStatus DetectButtonPos::onRunning() {
    std::cout << "Detecting button position... (s/r/f): " ;

    NodeStatus input = Test::onRunning();
    if (input == NodeStatus::SUCCESS) {
        setOutput<std::string>("button_pos", "def_pose_detected");
    }
    return input;
}

NodeStatus ManipulateToPose::onStart() {
    Expected<std::string> goal_pose = getInput<std::string>("goal_pose");
    if (!goal_pose)
    {
        throw RuntimeError("ManipulateToPose: missing required input [goal_pose]: ", goal_pose.error());
    }
    std::cout << "Asked to manipulate to pose: " 
              << goal_pose.value()
              << ". (s/r/f): " ;

    return Test::onStart();
}

NodeStatus ManipulateToPose::onRunning() {
    std::cout << "Manipulating to pose... (s/r/f): " ;

    return Test::onRunning();
}

NodeStatus DetectDoorOpen::onStart() {
    std::cout << "Asked to detect if door is open. (s/r/f): " ;

    return Test::onStart();
}

NodeStatus DetectDoorOpen::onRunning() {
    std::cout << "Detecting if door is open... (s/r/f): " ;

    return Test::onRunning();
}

NodeStatus PressButton::onStart() {
    std::cout << "Asked to press button. (s/r/f): " ;

    return Test::onStart();
}

NodeStatus PressButton::onRunning() {
    std::cout << "Pressing button... (s/r/f): " ;

    return Test::onRunning();
}

NodeStatus RecheckCurrentFloor::onStart() {
    std::cout << "Asked to recheck current floor. "
              << " (s/r/f): " ;

    NodeStatus input = Test::onStart();
    if (input != NodeStatus::RUNNING) {
        setOutput<std::string>("curr_floor", "2");
    }
    return input;
}

NodeStatus RecheckCurrentFloor::onRunning() {
    std::cout << "Rechecking current floor... (s/r/f): ";

    NodeStatus input = Test::onRunning();
    if (input != NodeStatus::RUNNING) {
        setOutput<std::string>("curr_floor", "2");
    }
    return input;
}


