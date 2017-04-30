cmake_minimum_required(VERSION 3.3)
project(Nao_e_mais_um_joguinho_canadense)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Nao_e_mais_um_joguinho_canadense ${SOURCE_FILES})