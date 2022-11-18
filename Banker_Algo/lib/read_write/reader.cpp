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
            toAdd.push_back(int(resource.value()));
        }
        allocations.append(toAdd);
    }

    return allocations;
}

matrix reader::getMaximums(){

}

row reader::getAvail(){

}

