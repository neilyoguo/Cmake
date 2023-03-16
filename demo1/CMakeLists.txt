#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -g")

#项目信息

project(hello)


#执行生成目标

add_executable(hello main.cpp)