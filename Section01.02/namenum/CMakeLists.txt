cmake_minimum_required(VERSION 3.1)
project(namenum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES namenum.cpp)
add_executable(namenum ${SOURCE_FILES})