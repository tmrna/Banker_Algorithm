#include "../../allocator/allocator.hpp"
#include "../../allocator/read_write/reader.hpp"

int main(){
    allocator tester;
    std::vector<std::vector<int>> filler={
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    matrix alloTest = filler;
    filler = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    matrix maxTest = filler;

    row availTest = std::vector({2, 3, 4, 5});

    tester.setAllocated(alloTest);
    tester.setAvailable(availTest);
    tester.setMax(maxTest);
    tester.genNeed();
    
    tester.genSafeSequence();
    
    tester.printAll();
}