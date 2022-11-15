cmake_minimum_required(VERSION 3.22.1)
project(Banker_Algorithm VERSION 1.0.0)
include(CTest)
add_subdirectory(row_matrix)

#add_subdirectory(tests)


add_executable(RowCtor tests/rowTests/rowCtor.cpp)


target_link_libraries(RowCtor row_matrix)

add_test(test_row_ctor RowCtor)

enable_testing()