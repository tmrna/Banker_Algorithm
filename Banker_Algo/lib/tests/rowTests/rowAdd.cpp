#include "../../allocator/read_write/row_matrix/row.hpp"
#include <cassert>

int main(){
    {
        // empty adding
        row a;
        row b;
        row c;
        c = a + b;
        assert(a == c);
        assert(b == c);
        assert(c == a);
        assert(c == b);
        assert(a == b);
        assert(b == a);
    }

    {
        // adding size() == 1
        std::vector one = {1};
        std::vector two = {2};
        row a(one);
        row b(two);
        row c = a + b;
        assert(c[0] == 3);
    }
}