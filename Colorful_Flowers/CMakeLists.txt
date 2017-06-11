cmake_minimum_required(VERSION 3.3)
project(Colorful_Flowers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Colorful_Flowers ${SOURCE_FILES})