#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息

project(demo3)

#向工程添加多个指定头文件的搜索路径
include_directories (include ./src/div mutl)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS_1)
aux_source_directory(./src/div DIR_SRCS_2)
aux_source_directory(mutl DIR_SRCS_3)


#执行生成目标
add_executable(demo3 ${DIR_SRCS_1} ${DIR_SRCS_2} ${DIR_SRCS_3})

