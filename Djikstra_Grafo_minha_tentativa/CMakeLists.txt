cmake_minimum_required(VERSION 3.3)
project(Djikstra_Grafo_minha_tentativa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Djikstra_Grafo_minha_tentativa ${SOURCE_FILES})