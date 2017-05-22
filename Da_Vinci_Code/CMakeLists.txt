cmake_minimum_required(VERSION 3.3)
project(Da_Vinci_Code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Da_Vinci_Code ${SOURCE_FILES})