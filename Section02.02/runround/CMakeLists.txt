cmake_minimum_required(VERSION 3.1)
project(runround)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES runround.cpp)
add_executable(runround ${SOURCE_FILES})