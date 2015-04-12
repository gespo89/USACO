cmake_minimum_required(VERSION 3.1)
project(pprime)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES pprime.cpp)
add_executable(pprime ${SOURCE_FILES})