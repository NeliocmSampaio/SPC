cmake_minimum_required(VERSION 3.3)
project(TDA_Racional)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TDA_Racional ${SOURCE_FILES})