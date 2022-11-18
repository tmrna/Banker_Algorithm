#ifndef READER_HPP
#define READER_HPP

#include "generator.hpp"

class reader{

private:
    generator gen;
public:

    reader(){}
    ~reader(){}

    reader(const char*);
    reader(std::string);
    reader(generator);

    std::vector<std::vector<int>> getAllocated();

    std::vector<std::vector<int>> getMaximums();

    std::vector<int> getAvail();

    void loadFile(const std::string&);



};

#endif