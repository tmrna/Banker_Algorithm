cmake_minimum_required(VERSION 3.22.1)
project(Banker_Algorithm VERSION 1.0.0)
include(CTest)

#add_subdirectory(read_write)

add_subdirectory(read_write)
#add_subdirectory(tests)
# ROW TESTS
# default ctor + dtor
add_executable(row_default_ctor tests/rowTests/rowCtorDef.cpp)
# cpy ctor
add_executable(row_cpy_ctor tests/rowTests/rowCtorCpy.cpp)
# operator<
add_executable(row_less_than_greater_than tests/rowTests/rowLTGT.cpp)
# operator+
add_executable(row_add tests/rowTests/rowAdd.cpp)


# LINK ROW EXEC
target_link_libraries(row_default_ctor row_matrix)
target_link_libraries(row_cpy_ctor row_matrix)
target_link_libraries(row_less_than_greater_than row_matrix)
target_link_libraries(row_add row_matrix)


# ADD ROW TESTS
add_test(test_row_ctor_default row_default_ctor)
add_test(test_row_ctor_cpy row_cpy_ctor)
add_test(test_row_less_than_greater_than row_less_than_greater_than)
add_test(test_row_add row_add)

# MATRIX TESTS


# READER TESTS

# GENERATOR TESTS
# ctor dtor
add_executable(gen_default_ctor tests/genTests/genCtor.cpp)
# generate example
add_executable(gen_example tests/genTests/genGenExample.cpp)

# LINK GENERATOR TESTS
target_link_libraries(gen_default_ctor read_write)
target_link_libraries(gen_example read_write)

# ADD GENERATOR TESTS
add_test(gen_ctor_default gen_default_ctor)
add_test(gen_generate_example gen_example)


enable_testing()