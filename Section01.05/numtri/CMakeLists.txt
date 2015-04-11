cmake_minimum_required(VERSION 3.1)
project(numtri)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES numtri.cpp)
add_executable(numtri ${SOURCE_FILES})