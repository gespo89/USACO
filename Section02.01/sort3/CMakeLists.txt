cmake_minimum_required(VERSION 3.1)
project(sort3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sort3.cpp)
add_executable(sort3 ${SOURCE_FILES})