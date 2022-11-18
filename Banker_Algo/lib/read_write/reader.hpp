#ifndef READER_HPP
#define READER_HPP

#include <cmath>

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

    std::string loadExample();

    int charToInt(const char*);

    std::vector<pugi::xml_node> fetchProcessNodes();

    std::vector<pugi::xml_node> fetchMaxNodes();

    std::vector<pugi::xml_node> fetchAllocNodes();

};

#endif