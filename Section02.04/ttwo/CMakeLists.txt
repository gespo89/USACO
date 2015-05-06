cmake_minimum_required(VERSION 3.1)
project(ttwo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ttwo.cpp)
add_executable(ttwo ${SOURCE_FILES})