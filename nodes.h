#include "behaviortree_cpp/action_node.h"
using namespace BT;

class Test : public StatefulActionNode
{
public:
  Test(const std::string& name, const BT::NodeConfig& config) :
      BT::StatefulActionNode(name, config)
  {}

  // You must override the virtual function tick()
  BT::NodeStatus tick() override 
  {}
};

class Navigate: public Test { 
  public: 
    Navigate(const std::string& name): Test(name) {} 

    static PortsList providedPorts()
    {
      return { 
        InputPort<std::string>("goal_pos"),
        OutputPort<std::string>("initial_pos")
      };
    }
};
class DetectButtonPos: public Test { 
  public: 
    DetectButtonPos(const std::string& name): Test(name) {}
    static PortsList providedPorts()
    {
      return { 
        InputPort<std::string>("button_text"),
        OutputPort<std::string>("button_pos")
      };
    }
};
class ManipulateToPose: public Test { 
  public: 
    ManipulateToPose(const std::string& name): Test(name) {}
  
    static PortsList providedPorts()
    {
      return { 
        InputPort<std::string>("goal_pose")
      };
    }
};
class DetectDoorOpen: public Test { 
  public: 
    DetectDoorOpen(const std::string& name): Test(name) {}

};
class PressButton: public Test { 
  public: 
    PressButton(const std::string& name): Test(name) {}

};
class RecheckCurrentFloor: public Test { 
  public: 
    RecheckCurrentFloor(const std::string& name): Test(name) {}

    static PortsList providedPorts()
    {
      return { 
        OutputPort<std::string>("curr_floor")
      };
    }

};

