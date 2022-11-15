cmake_minimum_required(VERSION 3.22.1)
project(Banker_Algorithm VERSION 1.0.0)
include(CTest)
add_subdirectory(row_matrix)

#add_subdirectory(tests)

# default ctor + dtor
add_executable(row_default_ctor tests/rowTests/rowCtorDef.cpp)
# cpy ctor
add_executable(row_cpy_ctor tests/rowTests/rowCtorCpy.cpp)
# operator<
add_executable(row_less_than_greater_than tests/rowTests/rowLTGT.cpp)
# operator+
add_executable(row_add tests/rowTests/rowAdd.cpp)

target_link_libraries(row_default_ctor row_matrix)
target_link_libraries(row_cpy_ctor row_matrix)
target_link_libraries(row_less_than_greater_than row_matrix)
target_link_libraries(row_add row_matrix)

add_test(test_row_ctor_default row_default_ctor)
add_test(test_row_ctor_cpy row_cpy_ctor)
add_test(test_row_less_than_greater_than row_less_than_greater_than)
add_test(test_row_add row_add)

enable_testing()