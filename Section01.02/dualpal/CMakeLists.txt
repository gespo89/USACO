cmake_minimum_required(VERSION 3.1)
project(dualpal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES dualpal.cpp)
add_executable(dualpal ${SOURCE_FILES})