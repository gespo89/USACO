cmake_minimum_required(VERSION 3.1)
project(money)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES money.cpp)
add_executable(money ${SOURCE_FILES})