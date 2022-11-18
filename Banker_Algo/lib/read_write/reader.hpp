#ifndef READER_HPP
#define READER_HPP

#include "generator.hpp"
#include "row_matrix/matrix.hpp"
#include "row_matrix/row.hpp"

class reader{

private:
    pugi::xml_document target;
public:

    reader(){}
    ~reader(){}

    // create gen and load file
    reader(const char*);
    reader(std::string);

    matrix getAllocated();

    matrix getMaximums();

    row getAvail();

    void loadFile(const std::string&);

    void loadExample();

};

#endif