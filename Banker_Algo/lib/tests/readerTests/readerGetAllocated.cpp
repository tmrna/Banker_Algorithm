#include "../../read_write/reader.hpp"
#include "../../read_write/row_matrix/row.hpp"
#include "../../read_write/row_matrix/matrix.hpp"
int main(){
    std::cout << "\n\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n";
    reader tester;
    std::string path = tester.loadExample();
    std::cout << path << std::endl;
    tester.getAllocated().printMatrix();
}