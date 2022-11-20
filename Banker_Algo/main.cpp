#include <string>
#include <iostream>

#include "lib/allocator/allocator.hpp"
#include "lib/allocator/read_write/reader.hpp"
#include "lib/allocator/read_write/generator.hpp"
#include "lib/allocator/read_write/row_matrix/row.hpp"
#include "lib/allocator/read_write/row_matrix/matrix.hpp"

#include <iostream>

void printHelp();

void printGenHelp();

int main(int argc, char** argv){
    if(argc == 1){ 
        printHelp();
    }
    else{
        std::vector<std::string> args;
        for(int i = 0; i < argc; i++){
            std::string sample = argv[i];
            args.push_back(sample);
        }
        if(args[1] == "--generate-example"){
            std::cout << "loading example..." << std::endl << std::endl;
            allocator solver;
            reader getter;

            solver.loadFromFile(getter.loadExample());

            solver.genNeed();

            std::cout << "current status is\n";
            solver.printAll();

            std::cout << "solving..." << std::endl;
            solver.genSafeSequence();

            std::cout << "Done" << std::endl;
            solver.printSafeSequence();
        }
        if(args[1] == "--help"){
            printHelp();
        }
        if(args[1] == "--solve"){
            if(argc > 2){
                for(unsigned i = 2; i < args.size(); i++){
                    allocator solver;
                    std::cout << "solving " << args[i] << "..." << std::endl;
                    solver.genSafeSequence(args[i]);
                    solver.printSafeSequence();
                }
            }
            else printHelp();
        }
        /*
        if(args[1] == "--gen"){
            if(argc > 2){

                if(args[2] == "--help"){
                    printGenHelp();
                }

                for(unsigned i = 2; i < args.size(); i++){
                    std::cout << "generating from " << args[i] << std::endl;
                    generator gen;
                    gen.genFile(args[i]);
                }
            }
            else{
                printHelp();
            }
        }
        */
    }

}


void printHelp(){
    std::cout << "\n\n" << "The following options are available:\n\n";

    std::cout << "    --generate-example                 -   generates example from assignment and determines safe sequence\n\n" <<
                 "    --solve <relative path to file>    -   finds the safe sequence for the given file\n\n" <<
                // "    --gen (incomplete) <relative path to file>      -    generates a file from a given text file.\n\n"<<
                // "    --gen --help                       -    displays accepted format for text files"<<
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

    exit(0);
}

/*
void printGenHelp(){
    std::cout << "--gen accepts the following format for txt files:\n\n" <<
    "<allocated row 1 element 1>, <allocated row 1 element 2> ...\n" <<
    ".\n"<<
    ".\n" <<
    ".\n" <<
    "<allocated row n element 1>, <allocated row n element 2>, ...\n" <<
    "@\n" <<
    "<max row 1 element 1>, <max row 1 element 2> ...\n" <<
    ".\n"<<
    ".\n" <<
    ".\n" <<
    "<max row m element 1>, <max row n element 2>, ...\n" <<
    "@\n" <<
    "<available 1>, <available 2> ...\n\n"<<
    "Any rows or colomns that over hang will cause the others to autofill with zeros\n" <<
    "so having a 10x10 allocation and  2x2 max is fine.\n" << std::endl;
    exit(0);
}
*/

void quit(){
    exit(0);
}