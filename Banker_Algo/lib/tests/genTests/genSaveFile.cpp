#include <iostream>
#include "../../read_write/generator.hpp"

int main(){
    generator gen;
    gen.generateExample();
    gen.saveDoc();
}