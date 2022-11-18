#include "../../allocator/read_write/row_matrix/row.hpp"
#include <cassert>

int main(){
    row tester({1, 2, 3, 4, 5});
    assert(tester.get_size() == 5);
}