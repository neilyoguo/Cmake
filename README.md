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

**同一个目录下构建多个文件**

比如我们的目录如下：
```
.
|-- add.cpp
|-- add.h
|-- CMakeLists.txt
`-- main.cpp
```
当源文件很少时，在add_executable的参数里把对应的源文件加进来即可，如下：
add_executable(demo1 main.cpp add.cpp)
可以类推，如果在同一目录下有多个源文件，那么只要在add_executable里把所有源文件都添加进去就可以了，比如:

```
add_executable( demo1 
                main.cpp 
                add.cpp
                xx.cpp
                xx.cpp
                ....
)

```

但是如果有几十个上百个源文件，再这样做就有离谱了，cmake提供了一个命令可以把指定目录下所有的源文件存储在一个变量中，这个命令就是：
使用aux_source_directory()
aux_source_directory(. DIR_SRCS)将当前目录的所有源文件保存到变量DIR_SRCS中,
cmake可以这样写:见demo2，CMakeLists.txt 中的内容如下:

```
#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#cmake 指定编译器和编译选项
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11）
set(CMAKE_CXX_FLAGS "-Wall -g")


# 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

#项目信息
project(demo2)

#执行生成目标
add_executable(demo2 ${DIR_SRCS})

```

**同一个目录下构建多个文件**

案例1:一个凌乱的目录树

```
.
|-- CMakeLists.txt
|-- include
|   |-- add.h
|   `-- sub.h
|-- mutl
|   |-- mutl.cpp
|   `-- mutl.h
`-- src
    |-- add.cpp
    |-- div
    |   |-- div.cpp
    |   `-- div.h
    |-- main.cpp
    `-- sub.cpp
```
这里使用了include_directories()
因为main.c里include了"div.h"和"mutl.h"，如果没有include_directories命令来指定头文件所在位置，就会无法编译,
同时此处要注意aux_source_directory不会递归包含子目录，仅包含指定的dir目录，所以当有子目录时还是需要在添加一个,
cmake可以这样写,见demo3，CMakeLists.txt中的内容如下:
```
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
```
案例2:一个标准结构清晰的目录树
```
.
|-- CMakeLists.txt
|-- include
|   |-- add.h
|   |-- div.h
|   |-- mutl.h
|   `-- sub.h
`-- src
    |-- add.cpp
    |-- div.cpp
    |-- main.cpp
    |-- mutl.cpp
    `-- sub.cpp
```
这样demo3的cmakelists就可以简化了，见demo4，CMakeLists.txt中的内容如下:
```
#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息

project(demo4)

#向工程添加多个指定头文件的搜索路径
include_directories (include)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


#执行生成目标
add_executable(demo4 ${DIR_SRCS})

```

**构建链接库**

要使用 add_library,cmake可以这样写,见demo5，CMakeLists.txt中的内容如下:
```
#cmake 版本要求
cmake_minimum_required(VERSION 2.8)


# 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 生成链接库 
#SHARED，动态库 xxx.so 
#STATIC，静态库 xxx.a
add_library (mysharedlib SHARED ${DIR_SRCS})
add_library (mystaticlib STATIC ${DIR_SRCS})

```

**使用链接库**


这里引入了以下语句:

```
#将可执行文件输出到当前工程bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#将库文件输出到当前工程lib目录下
set (LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)
#指定库文件路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
#将目标文件与库文件链接
target_link_libraries(demo6 mysharedlib)
```
案例1:
cmake可以这样写,见demo6，此处需要执行两次cmake，首先要执行addlib下的cmake生成链接库，然后执行
工程下的cmake，CMakeLists.txt中的内容如下:
```
#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息
project(demo6)

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

```
案例2:
demo6中，需要人为的在指定目录多执行一次cmake，可以引入以下语句，只在父目录执行即可
```
#添加一个子目录并构建该子目录
add_subdirectory (source_dir [binary_dir] [EXCLUDE_FROM_ALL])
source_dir:必选参数，指定子目录，子目录下应该包含CMakeLists.txt文件和代码文件
[binary_dir]:可选参数，执行子目录输出路径
```

见demo7，修改后的CMakeLists.txts如下：
```
#cmake 版本要求
cmake_minimum_required(VERSION 2.8)

#项目信息
project(demo7)

#将可执行文件输出到当前工程bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#向工程添加多个指定头文件的搜索路径
include_directories (${PROJECT_SOURCE_DIR}/addlib)

#指定库文件路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

#添加一个子目录并构建该子目录
add_subdirectory(addlib ${PROJECT_SOURCE_DIR}/lib)

# 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


#执行生成目标
add_executable(demo7 ${DIR_SRCS})

#链接库文件

target_link_libraries(demo7 mysharedlib)
```


