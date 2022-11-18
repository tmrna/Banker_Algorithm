cmake_minimum_required(VERSION 3.0.0)
project(Banker_Algorithm VERSION 1.0.0)

add_library(allocator
    allocator.hpp
    allocator.cpp
)

add_subdirectory(read_write)