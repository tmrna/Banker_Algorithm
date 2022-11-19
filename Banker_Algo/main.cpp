#include <string>
#include <iostream>

#include "lib/allocator/allocator.hpp"
#include "lib/allocator/read_write/reader.hpp"
#include "lib/allocator/read_write/generator.hpp"
#include "lib/allocator/read_write/row_matrix/row.hpp"
#include "lib/allocator/read_write/row_matrix/matrix.hpp"

#include <iostream>

void printHelp();

int main(int argc, char** argv){
    std::cout << "Running main";
    if(argc == 1){ 
        printHelp();
    }

    if(argv[1] == "--generate-example"){
        std::cout << "\n\n    Generating example...";
        allocator solver;
        reader example;
        std::string pathToExample = example.loadExample();
        try{
            solver.genSafeSequence(pathToExample);
            solver.printSafeSequence();
        }
        catch(std::string noGo){
            std::cout << noGo << std::endl;
        }
    }

    
}


void printHelp(){
    std::cout << "\n\n" << "The following options are available:\n";

    std::cout << "    --generate-example                          -   generates example from assignment and determines safe sequence\n\n" <<
                 "    --findSequence <relative path to file>    -   finds the safe sequence for the given file\n\n" <<
                 "\n\n" <<
                 "The format of each xml file is:\n\n" <<
                 "<?xml [ver] [encoding] [standalone]?>\n"<<
                 "  <rootNode>\n"<<
                 "    <processes>\n"<<
                 "      <p[process number]>\n"<<
                 "        <Allocation>\n"<<
                 "          <[resource type]> [resource count] </[resource type>\n"<<
                 "          ...\n"<<
                 "        </Allocation>\n"<<
                 "        <Max>\n" <<
                 "          <[resource type]> [resource count] </[resource type]>\n" <<
                 "          ...\n" <<
                 "        </Max>\n" <<
                 "      </p[process number]>\n" <<
                 "    </processes>\n" <<
                 "    <Available>\n" <<
                 "      <[resource type]> [resource count] </resource type>\n" <<
                 "      ...\n" <<
                 "    </Available>" <<
                 "  </rootNode>\n";
}

