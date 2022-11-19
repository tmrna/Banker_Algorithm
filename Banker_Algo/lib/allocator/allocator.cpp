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
    std::string process = "p";
    process +=  + '0' + i;

    max[i].use();
    need[i].use();
    available += allocated[i];
    
   
    safeSequence.push_back(process);
}

bool allocator::canUse(int i){
    //return available >= need[i] && max[i].getStatus();
 
    return max[i].getStatus();
}

bool allocator::done(){
    // when we are done we will have as many processes as rows
    //std::cout << "checking if done" << std::endl << std::endl;
    return safeSequence.size() == max.size();
}

void allocator::genSafeSequence(){

    genNeed();
    int prevRemainingCt = 0;
    bool stuck = false;

    for(unsigned i = 0; !done(); i = (i+1)%(max.size())){

        if(canUse(i)){

            useProcess(i);
        }
        if(stuck && safeSequence.size() == max.size() -1){
            std::string error = "No safe sequence exists";
            throw error;
        }
        if(safeSequence.size() == max.size() - 1){
            stuck = true;
        }
    }
}

void allocator::loadFromFile(const std::string& path){

    reader greg;
    greg.loadFile(path);
    

    max = greg.getMaximums();

    allocated = greg.getAllocated();


    available = greg.getAvail();

}

void allocator::genSafeSequence(const char* usrInput){
    reader greg;
    std::string path = usrInput;

    loadFromFile(path);

    genSafeSequence();
}

void allocator::genSafeSequence(std::string path){
    loadFromFile(path);
    genSafeSequence();
}


void allocator::printSafeSequence(){
    std::cout << "The safe sequence is : { ";
    for(unsigned i = 0; i < safeSequence.size(); i++){
        std::cout << safeSequence[i] + ", ";
    }
    std::cout << "}\n\n";
}


void allocator::printAll(){
    std::cout << "Available: "; available.printRow();
    std::cout << "\n\n" << "Allocated:" << std::endl;
    allocated.printMatrix();
    std::cout << "\nMax: " << std::endl;
    max.printMatrix();
    std::cout << std::endl << "Need:" << std::endl;
    need.printMatrix();
    std::cout << std::endl; printSafeSequence();
}