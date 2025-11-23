# include "nodes.h"
#include <behaviortree_cpp>

BT::NodeStatus tick() override
{
    std::cout << "Test: " << this->name() << std::endl;
    char s;
    std::cin >> s >> std::endl;
    switch (s){
        case 's':
            return BT::NodeStatus::SUCCESS;
            break;
        case 'r':
            return BT::NodeStatus::RUNNING;
            break;
        case 'f':
            return BT::NodeStatus::FAILURE;
            break;
        default:
            return BT::NodeStatus::RUNNING;
            break;
    }
    
}