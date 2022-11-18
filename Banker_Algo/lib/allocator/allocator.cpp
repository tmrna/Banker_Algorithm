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

void allocator::genNeed(){
    need = max - allocated;
}

void allocator::useProcess(int i){
    max[i].use();
    need[i].use();
    available += allocated[i];
    std::string process = "p" + (char(i + int('0')));
    safeSequence.push_back(process);
}

bool allocator::canUse(int i){
    return available >= need[i] && max[i].getStatus();
}

bool allocator::done(){
    // when we are done we will have as many processes as rows
    return safeSequence.size() == max.size();
}

void allocator::genSafeSequence(){
    int prevRemainingCt = 0;
    bool stuck = false;
    for(unsigned i = 0; !done(); i = (i+1)%max[i].get_size()){
        if(canUse(i)){
            useProcess(i);
        }
        if(safeSequence.size() == max.size() - 1){
            stuck = true;
        }
        if(stuck && safeSequence.size() == max.size() -1){
            std::string error = "No safe sequence exists";
            throw error;
        }
    }
}