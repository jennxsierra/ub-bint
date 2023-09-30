cmake_minimum_required(VERSION 3.26)
project(invoice-class)

set(CMAKE_CXX_STANDARD 20)

add_executable(invoice-class main.cpp
        invoice.cpp
        invoice.h)