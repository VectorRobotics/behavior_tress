cmake_minimum_required(VERSION 3.10)
project(humanoid_bt)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(ament_index_cpp REQUIRED)

include_directories(
    include
    test/include
)

# Library or node to run BT via ROS2
add_executable(nav_bt_runner src/nav_bt_runner.cpp)
add_executable(elev_bt_runner src/elev_bt_runner.cpp)

ament_target_dependencies(nav_bt_runner behaviortree_ros2)
ament_target_dependencies(elev_bt_runner behaviortree_ros2)

# Install executable
install(TARGETS nav_bt_runner elev_bt_runner
  DESTINATION lib/${PROJECT_NAME})

# Install header files
install(DIRECTORY include/
  DESTINATION include)

# Install tree XML files
install(DIRECTORY trees/
  DESTINATION share/${PROJECT_NAME}/trees)

# Tests using pure BehaviorTree.CPP
ament_add_gtest(test_bt test/test_bt.cpp test/nodes.cpp)
if(TARGET test_bt)
  target_link_libraries(test_bt behaviortree_cpp::behaviortree_cpp)
endif()
ament_target_dependencies(test_bt ament_index_cpp)


install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)


ament_package()
