cmake_minimum_required(VERSION 3.1)
project(nocows)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES nocows.cpp)
add_executable(nocows ${SOURCE_FILES})