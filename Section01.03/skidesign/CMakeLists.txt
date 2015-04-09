cmake_minimum_required(VERSION 3.1)
project(skidesign)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES skidesign.cpp)
add_executable(skidesign ${SOURCE_FILES})