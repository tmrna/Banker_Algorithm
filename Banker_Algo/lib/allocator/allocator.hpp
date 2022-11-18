#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "read_write/row_matrix/row.hpp"
#include "read_write/row_matrix/matrix.hpp"

class allocator{

private:

    row available;
    matrix allocated;
    matrix max;
    matrix need;

public:

    allocator(){}
    ~allocator(){}

    void setAvailable(const row&);
    void setAllocated(const matrix&);
    void setMax(const matrix&);

    std::vector<std::string> getSafeSequence();

};

#endif