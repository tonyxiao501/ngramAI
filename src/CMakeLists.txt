# CMakeLists.txt for the src directory

cmake_minimum_required(VERSION 3.10)

# 项目名称
project(ngramAI)

# 设置C++标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源文件
set(SRCS
    main.cpp
    utils.cpp
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SRCS})