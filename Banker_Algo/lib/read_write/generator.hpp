#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "deps/pugixml/pugixml.hpp"
#include <cassert>
#include <vector>
#include <string>
#include <iostream>

class generator{

private:
    // the document we are generating
    pugi::xml_document doc;
    // path to destination to save doc
    std::string path;
    // number of processes
    int numProcesses;
    // the declaration node with ver, encrip, standalone
    pugi::xml_node declNode;
    // root node
    pugi::xml_node root;
    // contains all processes
    pugi::xml_node processDiv;
    // processes to be placed into process div
    std::vector<pugi::xml_node> processes;
    // allocation and max sections, parent is processes
    std::vector<pugi::xml_node> allocations;
    std::vector<pugi::xml_node> maximums;

    // important counts
    std::vector<int> availCt;
    std::vector<std::vector<int>> ctsAllo;
    std::vector<std::vector<int>> ctsMax;

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

    std::vector<pugi::xml_node> attatchMax(std::vector<pugi::xml_node>&);

    void attatchAvailable(pugi::xml_node&, const std::vector<int>&);

    // Setup version, encoding and standalone
    void versionEncodingStandaloneSetup(pugi::xml_node&);

    std::string intToString(int);

    void getNewDoc(std::string newPath){
        path = newPath;
        doc.load_string(newPath.c_str());
    }

    void printDoc(){doc.save(std::cout, " ");}

    std::string saveDoc(){
        doc.save_file(path.c_str());
        return path;
    }

    std::string getPath(){return path;}

    std::string getResourceType(int);
};

#endif