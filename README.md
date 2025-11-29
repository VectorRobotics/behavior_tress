‼️ The repository is currently under development 🚧.‼️

This repository contains behavior trees for executing:
1. Generalist humanoid navigation
2. Robotic elevator riding

# Introduction
[Behavior Trees](https://en.wikipedia.org/wiki/Behavior_tree_(artificial_intelligence,_robotics_and_control)) allow implementing complex task logic in an intuitive and interactable environment. They are extensively used in robotics.

[BehaviorTree.CPP](https://www.behaviortree.dev/) is tightly integrated with [ROS](https://www.ros.org/) and especially used in the [Nav2](https://docs.nav2.org/) Project. We will be using the same here.

Read about behavior trees in contect of robotics here:
1. [Nav2 guide to BTs](https://docs.nav2.org/behavior_trees/index.html)
2. [ROS2 integration for BehavirTree.CPP](https://www.behaviortree.dev/docs/ros2_integration)

# BehaviorTree.CPP 
BehaviorTree.CPP is C++ library for developing and integrating BTs. Architecture of the BT is stored in an `.xml` which is loaded at runtime. Individual tasks would be implemented as "Actions" or "Services".

BehaviorTree.CPP is frequently used in robotics and in the ROS ecosystem. BehaviorTree.ROS2 is a ready-to-use set of wrappers, which can be used to quickly implement TreeNodes that interact with ROS2.

# Installation

The repository can be cloned as a ROS2 Jazzy package and also includes scripts to test BTs outside the ROS environment.

## Steps
1. Clone this repo in the `src` directory of your workspace.
    ``` bash
    git clone https://github.com/VectorRobotics/humanoid_bt.git
    ```
2. Clone the BehaviorTree.ROS2 repo in the `src` directory of your workspace.
    ``` bash
    git clone https://github.com/BehaviorTree/BehaviorTree.ROS2.git
    ```
3. Build
    ```
    cd ..
    colcon build
    source install/setup.bash
    ```

## Testing
Run
```bash
./build/humanoid_bt/test_bt 
```

## Running with ROS2 🚧
TODO