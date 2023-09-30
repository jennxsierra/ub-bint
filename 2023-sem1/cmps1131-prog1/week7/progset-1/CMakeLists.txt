cmake_minimum_required(VERSION 3.26)
project(progset-1)

set(CMAKE_CXX_STANDARD 20)

add_executable(progset-1 main.cpp
        Student.h
        Student.cpp
        Converter.h
        Converter.cpp)
