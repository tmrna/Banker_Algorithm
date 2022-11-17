# Apt does not include pugixml.cpp, including dependencies here rather than supplying an install instruction

add_library(pugixml
pugixml.hpp
pugixml.cpp
pugiconfig.hpp
)