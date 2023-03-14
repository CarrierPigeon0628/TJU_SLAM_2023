cmake_minimum_required( VERSION 2.8 )
project( assignment1 )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

add_executable(assignment1 src.cpp)
