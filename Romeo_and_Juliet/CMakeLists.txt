cmake_minimum_required(VERSION 3.3)
project(Romeo_and_Juliet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Romeo_and_Juliet ${SOURCE_FILES})