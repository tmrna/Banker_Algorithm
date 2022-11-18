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

void reader::loadExample(){
    generator gen;
    gen.generateExample();
    loadFile(gen.saveDoc());
}


matrix reader::getAllocated(){
   pugi::xml_node proc = target.child("processes");
   
   std::vector<pugi::xml_node> processes;

    for(pugi::xml_node sibling : proc.children()){
        processes.push_back(sibling);
    }

    matrix allocations;

    for(unsigned i = 0; i < processes.size(); i++){
        row toAdd;
        for(pugi::xml_node resource : processes[i].child("Allocation")){
            toAdd.push_back(charToInt(resource.value()));
        }
        allocations.append(toAdd);
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
    for(int i = toConvert.size() - 1, j = 0; i >=0; i--, j++){
        res += pow(toConvert[i] - int('0'), j);
    }
    return res;
}