add_subdirectory(deps)

add_library(
    read_write
    generator.hpp
    generator.cpp
    reader.cpp
    reader.hpp
)
