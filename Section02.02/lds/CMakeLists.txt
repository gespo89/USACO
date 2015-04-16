cmake_minimum_required(VERSION 3.1)
project(lds)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES lds.cpp)
add_executable(lds ${SOURCE_FILES})