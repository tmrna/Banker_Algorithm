cmake_minimum_required(VERSION 3.0.0)
project(Banker_Algorithm VERSION 1.0.0)

add_subdirectory(lib)

add_executable(Banker main.cpp)

target_link_libraries(Banker allocator read_write row_matrix)