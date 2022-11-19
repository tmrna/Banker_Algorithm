#include "generator.hpp"



// only present here
static const int NumProcesses = 5;
static const std::string Allocation = "Allocation";
static const std::string Max = "Max";
static const std::string P = "p";


//########################################################   Ctor and file generation #####################################################################
generator::generator(const std::string& DestinationPath){
    path = DestinationPath;
    doc.load_file(PUGIXML_TEXT(DestinationPath.c_str()));
}

generator::generator(const generator& toCpy){
    path = toCpy.path;
    doc.load_file(PUGIXML_TEXT(toCpy.path.c_str()));
}


void generator::generateExample(){

    ctsAllo = {
   /*p0*/ {0, 1, 0},
   /*p1*/ {2, 0, 0},
   /*p2*/ {3, 0, 2},
   /*p3*/ {2, 1, 1},
   /*p4*/ {0, 0, 2}
    };

    ctsMax = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

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

    // our given resources being assigned to counts
    for(unsigned i = 0; i < ctsAllo.size(); i++){
        attatchResources(allocations[i], ctsAllo[i]);
    }


    maximums = attatchMax(processes);


    for(unsigned i = 0; i < maximums.size(); i++){
        attatchResources(maximums[i], ctsMax[i]);
    }

    availCt = {3, 3, 2};

    attatchAvailable(root, availCt);
    doc.save_file(path.c_str(), PUGIXML_TEXT(" "));
}

std::string generator::genFile(std::string targetPath){
    std::string destPath;
    std::cout << "target path: " << targetPath << std::endl;
    for(int i = 0; i < targetPath.length() - 3; i++){
        destPath += targetPath[i];
    }
    destPath +=".xml";

    std::ifstream inFile(targetPath);
    if(!inFile.is_open()){
        std::cout << "failed to open file: " << targetPath << std::endl;
        exit(1);
    }

    std::string line; 
    // setting up allocation cts
    setupFromGen(ctsAllo, inFile, line);

    // setting up max cts
    setupFromGen(ctsMax, inFile, line);

    // setting up avail cts
    if(!inFile.eof()) getline(inFile, line);
    std::remove_if(line.begin(), line.end(), isspace);

    std::string nums;
    for(int i = 0; i < line.length(); i++){
        if(line[i] != ','){
            nums += line[i];
        }
        else if(i == line.length() - 1){
            nums += line[i];
        }
        else{
            availCt.push_back(stringToInt(nums));
            nums = "";
        }

    }
    //availCt.push_back(stringToInt(nums));

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

    // our given resources being assigned to counts
    std::vector<std::vector<pugi::xml_node>> resourceAssignments;
    for(unsigned i = 0; i < ctsAllo.size(); i++){
        attatchResources(allocations[i], ctsAllo[i]);
    }

    maximums = attatchMax(processes);


    for(unsigned i = 0; i < maximums.size(); i++){
        attatchResources(maximums[i], ctsMax[i]);
    }

    attatchAvailable(root, availCt);
    std::cout << "saving to " << destPath << std::endl;
    if(doc.save_file(destPath.c_str(), PUGIXML_TEXT(" "))) std::cout << "sucessful save!" << std::endl;
    return destPath;
}

void generator::setupFromGen(std::vector<std::vector<int>>& cts, std::ifstream& file, std::string& line){
    unsigned rowLen = 0;

    do{
        if(!file.eof()) getline(file, line);
        std::remove_if(line.begin(), line.end(), isspace);

        std::string num;

        std::vector<int> app;

        for(int i = 0; i < line.length() && line != "@"; i++){
            if(line[i] != ','){
                num += line[i];
            }
            else{
                app.push_back(stringToInt(num));
                num = "";
            }
        }
        //app.push_back(stringToInt(num));
        if(app.size() > rowLen) rowLen = app.size();
        cts.push_back(app);

    }while(line != "@" && !file.eof());

    // making sure cts if full

    for(unsigned i = 0; i < cts.size(); i++){
        if(cts[i].size() < rowLen){
            while(cts[i].size() < rowLen) cts[i].push_back(0);
        }
    }
}

//########################################################  attathment and setup ##########################################################################

void generator::versionEncodingStandaloneSetup(pugi::xml_node& declNode){
    declNode.append_attribute("version") = "1.0";
    declNode.append_attribute("encoding") = "uft-8";
    declNode.append_attribute("standalone") = "yes";
}

void generator::attatchProcesses(pugi::xml_node& parent, std::vector<pugi::xml_node>& cradle){
    std::string p = "p";

    //for(unsigned i = 0; i < NumProcesses; i++){
    for(unsigned i = 0; i < ctsAllo.size(); i++){
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


//#######################################################  int string conversion and getResourceTpye #############################################################

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

int generator::stringToInt(const std::string& given){
    int res = 0;
    for(int i = given.length() - 1, j = 1; i >=0; i--, j++){
        res += pow(given[i] - '0', j);
    }
    return res;
}

std::string generator::getResourceType(int selector){
    assert(selector < 26);
    std::string res;
    res += char(selector + int('A'));
    return res;
}