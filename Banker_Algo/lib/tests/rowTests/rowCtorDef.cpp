#include "../../allocator/read_write/row_matrix/row.hpp"
#include <cassert>
int main(){
    {
        // default ctor
        row apple;
        assert(apple.empty());
    }
    {
        // dtor
        row* pear = new row();
        delete pear;
    }
}