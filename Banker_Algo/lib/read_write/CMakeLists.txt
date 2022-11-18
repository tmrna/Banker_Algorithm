cmake_minimum_required(VERSION 3.0.0)
project(Banker_Algorithm VERSION 1.0.0)

add_subdirectory(deps)

add_subdirectory(row_matrix)

add_library(
    read_write
    generator.hpp
    generator.cpp
    reader.cpp
    reader.hpp
)
