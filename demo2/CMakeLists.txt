#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息

project(demo2)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)


#执行生成目标

add_executable(demo2 ${DIR_SRCS})


