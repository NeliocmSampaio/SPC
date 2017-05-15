cmake_minimum_required(VERSION 3.3)
project(Bits_trocados)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Bits_trocados ${SOURCE_FILES})