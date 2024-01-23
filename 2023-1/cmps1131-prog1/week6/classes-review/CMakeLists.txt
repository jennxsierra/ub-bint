cmake_minimum_required(VERSION 3.26)
project(classes-review)

set(CMAKE_CXX_STANDARD 20)

add_executable(classes-review main.cpp
        point.h
        point.cpp)