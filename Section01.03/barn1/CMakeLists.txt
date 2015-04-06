cmake_minimum_required(VERSION 3.1)
project(barn1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES barn1.cpp)
add_executable(barn1 ${SOURCE_FILES})