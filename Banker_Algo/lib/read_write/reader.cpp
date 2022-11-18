#include "reader.hpp"

reader::reader(const char* path){
    std::string pathStr(path);
    loadFile(pathStr);
}

reader::reader(std::string path){
    loadFile(path);
}

void reader::loadFile(const std::string& path){
    target.load_string(path.c_str());
}

std::string reader::loadExample(){
    generator gen;
    gen.generateExample();
    std::string pathToDoc = gen.saveDoc();
    target.load_file(pathToDoc.c_str());
    return pathToDoc;
}


matrix reader::getAllocated(){

    std::vector<pugi::xml_node> processes = fetchProcessNodes();

    std::vector<pugi::xml_node> alloc = fetchAllocNodes();

    matrix allocations;
    
    for(unsigned i = 0; i < alloc.size(); i++){
        row nextRow;
        
        pugi::xml_node toAdd = alloc[i].first_child();
        while(toAdd.name() != ""){
            nextRow.push_back(charToInt(toAdd.child_value()));
            toAdd = toAdd.next_sibling();
        }

        allocations.append(nextRow);
    }
    
    return allocations;
}

matrix reader::getMaximums(){

}

row reader::getAvail(){

}

int reader::charToInt(const char* input){
    int res = 0;
    std::string toConvert(input);
    for(int i = toConvert.size() - 1, j = 1; i >=0; i--, j++){
        res += pow(toConvert[i] - int('0'), j);
    }
    return res;
}


std::vector<pugi::xml_node> reader::fetchProcessNodes(){
    std::vector<pugi::xml_node> res;
    pugi::xml_node root = target.first_child();
    pugi::xml_node proc = root.first_child();
    
    pugi::xml_node toAdd = proc.first_child();

    while(toAdd.name() != ""){
        res.push_back(toAdd);
        toAdd = toAdd.next_sibling();
    }

    return res;
}

std::vector<pugi::xml_node> reader::fetchMaxNodes(){
    std::vector<pugi::xml_node> res;
    std::vector<pugi::xml_node> alloc = fetchAllocNodes();
    for(unsigned i = 0; i < alloc.size(); i++){
        res.push_back(alloc[i].next_sibling());
    }
}

std::vector<pugi::xml_node> reader::fetchAllocNodes(){
    std::vector<pugi::xml_node> res;

    auto processes = fetchProcessNodes();

    for(unsigned i = 0; i < processes.size(); i++){

        res.push_back(processes[i].first_child());
    }
    return res;
}