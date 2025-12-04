cmake_minimum_required(VERSION 3.16)
project(humanoid_bt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(ament_cmake REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(btcpp_ros2_interfaces REQUIRED)

set(THIS_PACKAGE_DEPS
    behaviortree_ros2::behaviortree_ros2
    ${btcpp_ros2_interfaces_TARGETS}
)

include_directories( include )
######################################################
# Simple example showing how to use and customize the BtExecutionServer

add_executable(
  bt_runner 
    src/bt_runner.cpp 
    src/clients/base.cpp
)
target_link_libraries(bt_runner ${THIS_PACKAGE_DEPS})

######################################################
# INSTALL

install(TARGETS
  bt_runner
  DESTINATION lib/${PROJECT_NAME}
  )

######################################################
# INSTALL Behavior.xml's, ROS config and launch files

install(DIRECTORY include/ DESTINATION include)

install(DIRECTORY
    trees
    launch
    DESTINATION share/${PROJECT_NAME}/
    )

ament_export_dependencies(behaviortree_ros2 btcpp_ros2_interfaces)

ament_package()