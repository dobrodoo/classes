cmake_minimum_required(VERSION 3.27)
project(classes)

set(CMAKE_CXX_STANDARD 20)

add_executable(classes main.cpp
        queue.cpp
        queue.h
        myArray.cpp
        myArray.h)
