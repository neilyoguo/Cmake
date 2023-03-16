#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息
project(demo4)

#将可执行文件输出到当前工程bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#向工程添加多个指定头文件的搜索路径
include_directories (${PROJECT_SOURCE_DIR}/addlib)

#指定库文件路径
link_directories(${PROJECT_SOURCE_DIR}/addlib/lib)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


#执行生成目标
add_executable(demo6 ${DIR_SRCS})

#链接库文件

target_link_libraries(demo6 mysharedlib)



