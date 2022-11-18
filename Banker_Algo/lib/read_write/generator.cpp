#include "generator.hpp"

// only present here
static const int NumProcesses = 5;
static const std::string Allocation = "Allocation";
static const std::string Max = "Max";
static const std::string P = "p";


//########################################################   Ctor and genExample #####################################################################
generator::generator(const std::string& DestinationPath){
    path = DestinationPath;
    doc.load_string(PUGIXML_TEXT(DestinationPath.c_str()));
}

generator::generator(const generator& toCpy){
    path = toCpy.path;
    doc.load_string(PUGIXML_TEXT(toCpy.path.c_str()));
}


void generator::generateExample(){
    // path for the file
    path = "GivenExample.xml";
    
    // our initial declaration node
    declNode = doc.append_child(pugi::node_declaration);
    // seting up all the things we need for version encoding and if standalone
    versionEncodingStandaloneSetup(declNode);

    // creating our root node
    root = doc.append_child("rootNode");

    // adding our list of processes to the root node
    processDiv = root.append_child("processes");

    // processes[i] is pi
    attatchProcesses(processDiv, processes);

    // sets up an allocation node for each process
    allocations = attatchAllocation(processes);

    // given counts for allocation
    ctsAllo = {
   /*p0*/ {0, 1, 0},
   /*p1*/ {2, 0, 0},
   /*p2*/ {3, 0, 2},
   /*p3*/ {2, 1, 1},
   /*p4*/ {0, 0, 2}
    };

    // our given resources being assigned to counts
    std::vector<std::vector<pugi::xml_node>> resourceAssignments;
    for(unsigned i = 0; i < ctsAllo.size(); i++){
        attatchResources(allocations[i], ctsAllo[i]);
    }


    maximums = attatchMax(processes);

    ctsMax = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    for(unsigned i = 0; i < maximums.size(); i++){
        attatchResources(maximums[i], ctsMax[i]);
    }

    availCt = {3, 3, 2};

    attatchAvailable(root, availCt);
}

//########################################################  attathment and setup ##########################################################################

void generator::versionEncodingStandaloneSetup(pugi::xml_node& declNode){
    declNode.append_attribute("version") = "1.0";
    declNode.append_attribute("encoding") = "uft-8";
    declNode.append_attribute("standalone") = "yes";
}

void generator::attatchProcesses(pugi::xml_node& parent, std::vector<pugi::xml_node>& cradle){
    std::string p = "p";

    for(unsigned i = 0; i < NumProcesses; i++){
        // attatches a number of processes to the parent node
        cradle.push_back(parent.append_child((p + intToString(i)).c_str()));
    }
}

std::vector<pugi::xml_node> generator::attatchAllocation(std::vector<pugi::xml_node>& parents){
    std::vector<pugi::xml_node> cradle;

    for(unsigned i = 0; i < parents.size(); i++){
        // attatches Allocation node to the parent
        cradle.push_back(parents[i].append_child((Allocation).c_str()));
    }
    return cradle;
}

std::vector<pugi::xml_node> generator::attatchMax(std::vector<pugi::xml_node>& parents){

    std::vector<pugi::xml_node> cradle;

    for(unsigned i = 0; i < parents.size(); i++){
        // attatches Max node to the parent
        cradle.push_back(parents[i].append_child((Max).c_str()));
    }

    return cradle;
}

std::vector<pugi::xml_node> generator::attatchResources(pugi::xml_node& parent, const std::vector<int>& ct){

    std::vector<pugi::xml_node> cradle;

    for(unsigned i = 0; i < ct.size(); i++){
        // gets resource type, supports up to 26 types
        cradle.push_back(parent.append_child(getResourceType(i).c_str()));

        cradle[i].append_child(pugi::node_pcdata).set_value(intToString(ct[i]).c_str());
    }
    return cradle;
}

void generator::attatchAvailable(pugi::xml_node& parent, const std::vector<int>& cts){
    // attatches available cat to parent
    pugi::xml_node available = parent.append_child("Available");
    attatchResources(available, cts);
}


//#######################################################  int to string and getResourceTpye #############################################################

std::string generator::intToString(int val){
    std::vector<char> tmp;
    while(val > 0){
        char filler = char(val % 10 + int('0'));
        tmp.push_back(filler);
        val /= 10;
    }
    std::string res;
    for(int i = tmp.size() - 1; i >= 0; i--){
        res+=tmp[i];
    }
    if(res.empty()) return "0";
    return res;
}

std::string generator::getResourceType(int selector){
    assert(selector < 26);
    std::string res;
    res += char(selector + int('A'));
    return res;
}