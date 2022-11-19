#include "../../allocator/read_write/row_matrix/row.hpp"
#include <cassert>
int main(){
    {
        std::vector<int> filling = {1, 2, 3, 4, 5};
        row pie(filling);
        row cpyPie(pie);
        std::cout << "Copy1" << std::endl;
        assert(pie == cpyPie);
    }
    {
        std::vector<int> filling2 = {2, 3, 4, 5, 6};
        row pie2(filling2);
        row notCpy;
        std::cout << "Copy2!" << std::endl;
        assert(pie2 != notCpy);
    }
}