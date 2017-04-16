cmake_minimum_required(VERSION 3.3)
project(Mesa_da_sra_montagny)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Mesa_da_sra_montagny ${SOURCE_FILES})