cmake_minimum_required(VERSION 3.3)
project(Total_Flow)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Total_Flow ${SOURCE_FILES})