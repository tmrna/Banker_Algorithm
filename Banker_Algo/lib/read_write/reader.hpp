#ifndef READER_HPP
#define READER_HPP

#include "generator.hpp"
#include "row_matrix/matrix.hpp"
#include "row_matrix/row.hpp"

class reader{

private:
    generator gen;
public:

    reader(){}
    ~reader(){}

    reader(const char*);
    reader(std::string);
    reader(generator);

    matrix getAllocated();

    matrix getMaximums();

    row getAvail();

    void loadFile(const std::string&);



};

#endif