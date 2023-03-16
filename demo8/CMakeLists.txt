#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息
project(demo8)


# 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

include_directories(
        /usr/include/mysql
)

link_directories(
        /usr/lib64/mysql
)
#执行生成目标
add_executable(demo8 ${DIR_SRCS})

target_link_libraries (demo8 libmysqlclient.so)
