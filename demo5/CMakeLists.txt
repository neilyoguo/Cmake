#cmake 版本要求
cmake_minimum_required(VERSION 2.8)


# 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 生成链接库 
#SHARED，动态库 xxx.so 
#STATIC，静态库 xxx.a
add_library (mysharedlib SHARED ${DIR_SRCS})
add_library (mystaticlib STATIC ${DIR_SRCS})


