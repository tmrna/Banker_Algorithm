#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "read_write/row_matrix/row.hpp"
#include "read_write/row_matrix/matrix.hpp"
#include "read_write/reader.hpp"


class allocator{

private:

    row available;
    matrix allocated;
    matrix max;
    matrix need;
    std::vector<std::string> safeSequence;
    bool safeState;

public:

    allocator(){safeState = false;}
    ~allocator(){}

    void setAvailable(const row&);
    void setAllocated(const matrix&);
    void setMax(const matrix&);

    void genNeed();

    void genSafeSequence();
    void genSafeSequence(const char*);
    void genSafeSequence(std::string);

    void printSafeSequence();

    void printAll();

    void loadFromFile(const std::string&);
    
    void useProcess(int);

    bool canUse(int);

    bool done();

    std::vector<std::string> getSafeSequence(){return safeSequence;}


};

#endif