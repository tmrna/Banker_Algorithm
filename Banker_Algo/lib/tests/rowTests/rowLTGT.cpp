#include "../../read_write/row_matrix/row.hpp"
#include <cassert>
#include <iostream>
int main(){

    {
        std::vector<int> normal = {0, 1, 2, 3, 4, 5, 6};
        std::vector<int> r = {1, 2, 3, 4, 5, 6, 7};
        row a(normal);
        row b(r);
        assert(a < b);
        assert(b > a);
    }
    {
        std::vector<int> apple;
        std::vector<int> orange;
        for(int i = 0; i < 100; i++){
            apple.push_back(i%2);
            orange.push_back(i%2);
        }
    
        orange.push_back(3);
        apple.push_back(2);

        row big(orange);
        row little(apple);

        assert(big > little);
        assert(little < big);
    }
    {
        std::vector<int> cranberry;
        std::vector<int> pineapple;
        for(int i = 0; i < 100; i++){
            cranberry.push_back(i%2);
            pineapple.push_back(i%2);
        }

        row sameL(cranberry);
        row sameR(pineapple);

        assert(!(sameL > sameR));
        assert(!(sameR < sameL));
    }
}