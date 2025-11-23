#include "behaviortree_cpp/bt_factory.h"

// file that contains the custom nodes definitions
#include "nodes.h"
using namespace BT;

int main()
{
    // We use the BehaviorTreeFactory to register our custom nodes
  BehaviorTreeFactory factory;

  // The recommended way to create a Node is through inheritance.
  factory.registerNodeType<Navigate>("Navigate");
  factory.registerNodeType<DetectButtonPos>("DetectButtonPos");
  factory.registerNodeType<ManipulateToPose>("ManipulateToPose");
  factory.registerNodeType<PressButton>("PressButton");
  factory.registerNodeType<RecheckCurrentFloor>("RecheckCurrentFloor");
  factory.registerNodeType<DetectDoorOpen>("DetectDoorOpen");
  
  // Trees are created at deployment-time (i.e. at run-time, but only 
  // once at the beginning). 
    
  // IMPORTANT: when the object "tree" goes out of scope, all the 
  // TreeNodes are destroyed
  auto tree = factory.createTreeFromFile("./elev_bt.xml");
  Groot2Publisher publisher(tree);
  // To "execute" a Tree you need to "tick" it.
  // The tick is propagated to the children based on the logic of the tree.
  // In this case, the entire sequence is executed, because all the children
  // of the Sequence return SUCCESS.
  tree.tickWhileRunning();

  return 0;
}