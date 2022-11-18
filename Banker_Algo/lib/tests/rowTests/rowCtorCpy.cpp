#include "../../allocator/read_write/row_matrix/row.hpp"
#include <cassert>
int main(){
    {
        std::vector<int> filling = {1, 2, 3, 4, 5};
        row pie(filling);
        row cpyPie(pie);
        assert(pie == cpyPie);
    }
    {
        std::vector<int> filling2 = {2, 3, 4, 5, 6};
        row pie2(filling2);
        row notCpy;
        assert(pie2 != notCpy);
    }
}