#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "deps/pugixml/pugixml.hpp"
#include <cassert>
#include <vector>
#include <string>
#include <iostream>

class generator{

private:
    pugi::xml_document doc;
    std::string path;



public:
    generator(){/*handled by stl and pugi*/}
    ~generator(){/*handled by stl and pugi*/}

    // generator with specified path for destination
    generator(const std::string&);

    // cpy ctor
    generator(const generator&);

    // generates the given scenario for the assignment and writes to memory, no need to write to disk
    void generateExample();

    void attatchProcesses(pugi::xml_node&, std::vector<pugi::xml_node>&);

    std::vector<pugi::xml_node> attatchResources(pugi::xml_node&, const std::vector<int>&);

    std::vector<pugi::xml_node> attatchAllocation(std::vector<pugi::xml_node>&);

    // Setup version, encoding and standalone
    void versionEncodingStandaloneSetup(pugi::xml_node&);

    std::string intToString(int);

};

#endif