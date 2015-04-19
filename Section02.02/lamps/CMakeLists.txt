cmake_minimum_required(VERSION 3.1)
project(lamps)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES lamps.cpp)
add_executable(lamps ${SOURCE_FILES})