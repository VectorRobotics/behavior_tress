cmake_minimum_required(VERSION 3.16)
project(humanoid_bt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(ament_cmake REQUIRED)
find_package(behaviortree_ros2 REQUIRED)

set(THIS_PACKAGE_DEPS
    behaviortree_ros2::behaviortree_ros2
)

include_directories( include )
######################################################
# Simple example showing how to use and customize the BtExecutionServer
add_executable(nav_bt_runner src/nav_bt_runner.cpp)
target_link_libraries(nav_bt_runner ${THIS_PACKAGE_DEPS})

add_executable(elev_bt_runner src/elev_bt_runner.cpp)
target_link_libraries(elev_bt_runner ${THIS_PACKAGE_DEPS})

######################################################
# INSTALL

install(TARGETS
  nav_bt_runner
  elev_bt_runner
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


ament_export_dependencies(behaviortree_ros2)

ament_package()