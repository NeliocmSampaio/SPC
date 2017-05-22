cmake_minimum_required(VERSION 3.3)
project(Whats_Cryptanalysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Whats_Cryptanalysis ${SOURCE_FILES})