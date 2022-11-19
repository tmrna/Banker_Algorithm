#include <iostream>
#include "../../allocator/read_write/generator.hpp"

int main(){
    {
        // we will be starting from lib/build
        generator gen;
        gen.genFile("../tests/genTests/fileTest1.txt");
    }
    {
        generator gen;
        gen.genFile("../tests/genTests/fileTest2.txt");
    }
    {
        generator gen;
        gen.genFile("../tests/genTests/fileTest3.txt");
    }

}