#include "../../allocator/read_write/row_matrix/matrix.hpp"
int main(){
    row filler({1, 2, 3, 4, 5});
    matrix tester;
    for(int i = 0; i < 100; i++){
        tester.append(filler);
    }
    assert(tester.size() == 100);
}