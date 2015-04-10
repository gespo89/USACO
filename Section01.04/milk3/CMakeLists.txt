cmake_minimum_required(VERSION 3.1)
project(milk3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES milk3.cpp)
add_executable(milk3 ${SOURCE_FILES})