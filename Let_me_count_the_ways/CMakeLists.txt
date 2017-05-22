cmake_minimum_required(VERSION 3.3)
project(Let_me_count_the_ways)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Let_me_count_the_ways ${SOURCE_FILES})