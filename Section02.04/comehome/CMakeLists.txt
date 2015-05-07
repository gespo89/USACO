cmake_minimum_required(VERSION 3.1)
project(comehome)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES comehome.cpp)
add_executable(comehome ${SOURCE_FILES})