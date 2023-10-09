cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(Reflect VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(Reflect
    main.cpp
    ClassFactory.cpp
)

# 添加头文件目录，使得我们可以在源文件中直接#include相应的头文件
target_include_directories(Reflect PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           "${PROJECT_SOURCE_DIR}/Test"
                           "${PROJECT_SOURCE_DIR}/Utils"
                           )