cmake_minimum_required(VERSION 2.8.3)
project(whill_mover)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  ros_whill
  roscpp
  std_msgs
  sensor_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES whill_mover
#  CATKIN_DEPENDS ros_whill roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${ros_whill_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_executable(main src/main.cpp)
target_link_libraries(main ${catkin_LIBRARIES})
add_dependencies(main ${catkin_EXPORTED_TARGETS})

