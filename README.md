# Cmake
cmake 实践

**构建单个文件**

如果要使用 cmake 来生成 makefile 的话，需要首先新建一个 CMakeLists.txt 文件，cmake 的所有配置都在这个文件中完成，见demo1，CMakeLists.txt 中的内容如下：
```
#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#cmake 指定编译器和编译选项
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11）
set(CMAKE_CXX_FLAGS "-Wall -g")

#项目信息
project(hello)

#执行生成目标
add_executable(hello main.cpp)
```
