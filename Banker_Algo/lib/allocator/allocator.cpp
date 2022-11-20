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

    for(int j = 0; j < available.get_size(); j++){

        if(available[j] < need[i][j]) return false;
        if(!need[i].getStatus()) return false;
    }
    return true;

}

bool allocator::done(){

    return safeSequence.size() == max.size();
}

void allocator::genSafeSequence(){

    genNeed();
    allocated.setUsable();
    max.setUsable();
    need.setUsable();
    int failCt = 0;
    for(unsigned i = 0; !done(); i = (i+1)%(max.size())){

        if(canUse(i)){
            useProcess(i);
        }
        if(!canUse(i)){
            failCt++;
            if(failCt == max.size()){
                std::cout << "No safe sequence exists" << std::endl;
                exit(0);
            }
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