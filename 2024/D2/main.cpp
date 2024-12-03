#include "header.h"

bool checkCondition(std::vector<int> list){
    int increasing = 1;
    if (list[0] > list[1]){
        increasing = -1;
    }
    else if (list[0] == list[1]){
        return false;
    }
    int diff = increasing * (list[1] - list[0]);
    for (int i = 0; i < (int)(list.size()) - 1; ++i){
        diff = increasing * (list[i+1] - list[i]);
        if (diff < 1 || diff > 3){
            return false;
        }
    }
    return true;

}

int main(int argc, char* argv[]){
    if (!(checkMakeFile(argc, argv))){
        return 0;
    }
    int numReportsSafe = 0;
    std::ifstream file(argv[1]);
    std::vector<int> lineList{};
    int lineNumber = 0;
    while (storeLineInList(file, &lineList)){
        if (checkCondition(lineList)){
            numReportsSafe++;
        }
        else {
            bool usedRemove = false;
            bool dontAdd = true;
            int skipIndex = -2;
            for (int i = 0; i < (int)(lineList.size()); ++i){
                std::vector<int> firstHalf = std::vector<int>(lineList.begin(), lineList.begin() + i);
                std::vector<int> secondHalf = std::vector<int>(lineList.begin() + (i+1), lineList.end());
                std::vector<int> copy;
                if (i == 0){
                    copy = secondHalf;
                }
                else if(i == (int)(lineList.size() - 1)){
                    copy = firstHalf;
                }
                else{
                    firstHalf.insert(firstHalf.end(), secondHalf.begin(), secondHalf.end());
                    copy = firstHalf;
                }

                if (!usedRemove){
                    if (checkCondition(copy)){
                        usedRemove = true;
                        dontAdd = false;
                        skipIndex = i;
                    }
                }
                else if (checkCondition(copy) && i != skipIndex + 1){
                    dontAdd = false;
                }
            }
            if (!dontAdd){
                numReportsSafe++;
            }
        }
        std::cout << lineNumber << " " << numReportsSafe << std::endl;
        lineNumber++;
        lineList.clear();
    }
    std::cout << "Number of Reports safe for " << argv[1] << " is " << numReportsSafe << "." << std::endl;
}