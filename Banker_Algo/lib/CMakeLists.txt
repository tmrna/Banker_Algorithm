cmake_minimum_required(VERSION 3.0.0)
project(Banker_Algorithm VERSION 1.0.0)

include(CTest)

add_subdirectory(allocator)


######################################################################################################################################################
######################################################################################################################################################

# ROW TESTS
# default ctor + dtor
add_executable(row_default_ctor tests/rowTests/rowCtorDef.cpp)
# cpy ctor
add_executable(row_cpy_ctor tests/rowTests/rowCtorCpy.cpp)
# operator<
add_executable(row_less_than_greater_than tests/rowTests/rowLTGT.cpp)
# operator+
add_executable(row_add tests/rowTests/rowAdd.cpp)
# size
add_executable(row_size tests/rowTests/rowSize.cpp)


# LINK ROW EXEC
target_link_libraries(row_default_ctor row_matrix)
target_link_libraries(row_cpy_ctor row_matrix)
target_link_libraries(row_less_than_greater_than row_matrix)
target_link_libraries(row_add row_matrix)
target_link_libraries(row_size row_matrix)


# ADD ROW TESTS
add_test(test_row_ctor_default row_default_ctor)
add_test(test_row_ctor_cpy row_cpy_ctor)
add_test(test_row_less_than_greater_than row_less_than_greater_than)
add_test(test_row_add row_add)
add_test(test_row_size row_size)

######################################################################################################################################################
######################################################################################################################################################

# MATRIX TESTS
# ctor dtor
add_executable(matrix_default_ctor tests/matrixTests/matrixCtor.cpp)
# dimension
add_executable(matrix_dim tests/matrixTests/matrixDim.cpp)
# size
add_executable(matrix_size tests/matrixTests/matrixSize.cpp)
# swap
add_executable(matrix_swap tests/matrixTests/matrixSwap.cpp)
# append
add_executable(matrix_append tests/matrixTests/matrixAppend.cpp)

# LINK MATRIX TESTS
target_link_libraries(matrix_default_ctor row_matrix)
target_link_libraries(matrix_dim row_matrix)
target_link_libraries(matrix_size row_matrix)
target_link_libraries(matrix_swap row_matrix)
target_link_libraries(matrix_append row_matrix)

# ADD MATRIX TESTS
add_test(test_matrix_ctor matrix_default_ctor)
add_test(test_matrix_dimensions matrix_dim)
add_test(test_matrix_get_size matrix_size)
add_test(test_matrix_swap matrix_swap)
add_test(test_matrix_append matrix_append)

######################################################################################################################################################
######################################################################################################################################################

# READER TESTS

# getAllocated matrix
add_executable(reader_alloc tests/readerTests/readerGetAllocated.cpp)


# LINK READER TESTS
target_link_libraries(reader_alloc read_write row_matrix)

# ADD READER TESTS
add_test(test_reader_alloc reader_alloc)

######################################################################################################################################################
######################################################################################################################################################

# GENERATOR TESTS
# ctor dtor
add_executable(gen_default_ctor tests/genTests/genCtor.cpp)
# generate example
add_executable(gen_example tests/genTests/genGenExample.cpp)
# generate from file
add_executable(gen_file tests/genTests/genGenFile.cpp)

# LINK GENERATOR TESTS
target_link_libraries(gen_default_ctor read_write)
target_link_libraries(gen_example read_write)
target_link_libraries(gen_file read_write)

# ADD GENERATOR TESTS
add_test(test_gen_ctor_default gen_default_ctor)
add_test(test_gen_generate_example gen_example)
add_test(test_gen_file gen_file)

######################################################################################################################################################
######################################################################################################################################################

# ALLOCATOR TESTS
# setting
add_executable(allocator_set tests/allocatorTests/allocatorSetter.cpp)
# solving example
add_executable(solve_example tests/allocatorTests/allocatorExample.cpp)

# LINK ALLOCATOR TESTS
target_link_libraries(allocator_set allocator read_write row_matrix)
target_link_libraries(solve_example allocator read_write row_matrix)

# ADD ALLOCATOR TESTS
add_test(test_allocator_set allocator_set)
add_test(test_solve_example solve_example)

enable_testing()