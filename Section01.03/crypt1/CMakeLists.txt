cmake_minimum_required(VERSION 3.1)
project(crypt1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES crypt1.cpp)
add_executable(crypt1 ${SOURCE_FILES})