#include "behaviortree_cpp/action_node.h"
using namespace BT;

class Test : public StatefulActionNode
{
public:
  Test(const std::string& name, const BT::NodeConfig& config) :
      BT::StatefulActionNode(name, config){} ;

  // You must override the virtual function tick()
  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;
  void onHalted() override  ;
};

class Navigate: public Test { 
  public: 
    Navigate(const std::string& name, const BT::NodeConfig& config): Test(name, config){}  ;

    static PortsList providedPorts()
    {
      return { 
        InputPort<std::string>("goal_pos"),
        OutputPort<std::string>("initial_pos")
      };
    }

  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;

  private:
    std::string goal_pos_;
    std::string init_pos_;
};
class DetectButtonPos: public Test { 
  public: 
    DetectButtonPos(const std::string& name, const BT::NodeConfig& config): Test(name, config){} ;
    static PortsList providedPorts()
    {
      return { 
        InputPort<std::string>("button_text"),
        OutputPort<std::string>("button_pos")
      };
    }

  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;

};
class ManipulateToPose: public Test { 
  public: 
    ManipulateToPose(const std::string& name, const BT::NodeConfig& config): Test(name, config){} ;
  
    static PortsList providedPorts()
    {
      return { 
        InputPort<std::string>("goal_pose")
      };
    }

  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;
};
class DetectDoorOpen: public Test { 
  public: 
    DetectDoorOpen(const std::string& name, const BT::NodeConfig& config): Test(name, config){} ;
    static PortsList providedPorts()
    {
      return { 
      };
    }

  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;

};
class PressButton: public Test { 
  public: 
    PressButton(const std::string& name, const BT::NodeConfig& config): Test(name, config){} ;

    static PortsList providedPorts()
    {
      return { 
      };
    }

  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;
};
class RecheckCurrentFloor: public Test { 
  public: 
    RecheckCurrentFloor(const std::string& name, const BT::NodeConfig& config): Test(name, config){} ;

    static PortsList providedPorts()
    {
      return { 
        OutputPort<std::string>("curr_floor"),
      };
    }

  BT::NodeStatus onStart() override ;
  BT::NodeStatus onRunning() override ;

  private:
    std::string target_floor_;
};