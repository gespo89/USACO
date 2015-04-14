cmake_minimum_required(VERSION 3.1)
project(frac1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES frac1.cpp)
add_executable(frac1 ${SOURCE_FILES})