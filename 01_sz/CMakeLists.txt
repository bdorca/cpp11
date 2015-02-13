cmake_minimum_required(VERSION 2.8.4)
project(01_sz)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wpedantic")

set(SOURCE_FILES main.cpp)
add_executable(01_sz ${SOURCE_FILES})