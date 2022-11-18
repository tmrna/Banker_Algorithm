#include "../../read_write/row_matrix/matrix.hpp"
int main(){
    matrix testMatr;
    row testRowA({1, 2, 3, 4});
    row testRowB({4, 5, 6, 7});
    testMatr.append(testRowA);
    testMatr.append(testRowB);
    testMatr.printMatrix();
}