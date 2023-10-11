cmake_minimum_required(VERSION 3.26)
project(square)

set(CMAKE_CXX_STANDARD 20)

add_executable(car main.cpp
        Car.h
        Car.cpp)