#include "../../read_write/row_matrix/matrix.hpp"
int main(){
    matrix tester;
    for(int i = 0; i < 100; i++){
        row toAppend;
        for(int j = 0; j < 250; j++){
            toAppend.push_back(i - j);
        }
        tester.append(toAppend);
    }

    matrix confirmer(tester);

    for(int i = 0; i < 100/2; i++){
        std::cout << "Current row swap: " << i << " and " << 99 -i << std::endl;
        tester.swapRows(i, 99 - i);
        assert(tester[i] == confirmer[99-i]);
        assert(tester[99 - i] == confirmer[i]);
        std::cout << "--    successful swap\n";
    }
}