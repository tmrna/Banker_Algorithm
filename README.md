# Banker_Algorithm
Banker's algorithm implementation for OS Fall 2022

# Building
Running build.py will build the project and move the executable into the current directory.

# Requirements
c++11
CMake 3.0.0 or higher

# Compiler used
g++ 11.3.0

# Obtaining example
running:
./Banker --generate-example

will generate a file for the given example and find the safe sequence. 

# Obtaining safe sequence
running:
./Banker --solve GivenExample.xml

will output the safe sequence.

# Dependencies
pugixml (included in Banker_Algo/lib/read_write/deps/pugixml, configured for header only.)