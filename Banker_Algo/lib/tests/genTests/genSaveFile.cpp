#include <iostream>
#include "../../allocator/read_write/generator.hpp"

int main(){
    generator gen;
    gen.generateExample();
    gen.saveDoc();
}