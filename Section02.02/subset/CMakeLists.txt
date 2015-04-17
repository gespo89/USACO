cmake_minimum_required(VERSION 3.1)
project(subset)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES subset.cpp)
add_executable(subset ${SOURCE_FILES})