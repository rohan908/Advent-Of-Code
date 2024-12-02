#include "helper.h"

bool checkMakeFile(int argc, char* argv[]){
    if (!(argc > 1)){
        std::cout << "error in number of arguments";
        return false;
    }
    FILE* f = fopen(argv[1], "r");
    if (f == NULL){
        std::cout << "error reading input file";
        return false;
    }
    fclose(f);
    return true;
}