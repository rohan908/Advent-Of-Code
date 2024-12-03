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

bool storeLineInList(std::ifstream& file, std::vector<int>* numList){
    std::string line;
    if (std::getline(file, line)){
        std::stringstream ss(line);
        int num;
        while (ss >> num) {
            numList->push_back(num);
        }
        return true;
    }
    return false;
}