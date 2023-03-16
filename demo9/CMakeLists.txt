#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息

project(demo9)

#追加Modules目录
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)


#执行生成目标
add_executable(demo9 ${DIR_SRCS})



find_package(MySQL REQUIRED)

if(MYSQL_INCLUDE_DIR)
        include_directories(${MYSQL_INCLUDE_DIR})
        message("include dir is found")
endif()
if(MYSQL_LIB)
        target_link_libraries(demo9 ${MYSQL_LIB})
        message("lib dir is found")
endif()


