#include "../../allocator/allocator.hpp"
#include "../../allocator/read_write/reader.hpp"

int main(){
    reader example;
    allocator solver;
    solver.loadFromFile(example.loadExample());
    solver.genSafeSequence();
    solver.printAll();
}