#include "allocator.hpp"

void allocator::setAllocated(const matrix& newAlloc){
    allocated = newAlloc;
}

void allocator::setAvailable(const row& newAvail){
    available = newAvail;
}

void allocator::setMax(const matrix& newMax){
    max = newMax;
}