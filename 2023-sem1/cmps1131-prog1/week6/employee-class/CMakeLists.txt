cmake_minimum_required(VERSION 3.26)
project(employee-class)

set(CMAKE_CXX_STANDARD 20)

add_executable(employee-class main.cpp
        employee.cpp
        employee.h)