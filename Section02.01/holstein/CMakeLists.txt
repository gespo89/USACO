cmake_minimum_required(VERSION 3.1)
project(holstein)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES holstein.cpp)
add_executable(holstein ${SOURCE_FILES})