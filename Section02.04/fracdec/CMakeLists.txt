cmake_minimum_required(VERSION 3.1)
project(fracdec)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES fracdec.cpp)
add_executable(fracdec ${SOURCE_FILES})