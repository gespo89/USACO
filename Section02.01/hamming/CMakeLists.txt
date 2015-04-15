cmake_minimum_required(VERSION 3.1)
project(hamming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hamming.cpp)
add_executable(hamming ${SOURCE_FILES})