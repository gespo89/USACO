cmake_minimum_required(VERSION 3.1)
project(prefix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES prefix.cpp)
add_executable(prefix ${SOURCE_FILES})