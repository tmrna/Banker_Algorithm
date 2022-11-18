#include "../../allocator/read_write/reader.hpp"
#include "../../allocator/read_write/row_matrix/row.hpp"
#include "../../allocator/read_write/row_matrix/matrix.hpp"
int main(){
    reader tester;
    std::string path = tester.loadExample();
    std::cout << path << std::endl;
    tester.getAllocated().printMatrix();
}