#include "header.h"

int main(int argc, char* argv[]){
    if (!(checkMakeFile(argc, argv))){
        return 0;
    }
    FILE* f1 = fopen(argv[1], "r");
    std::list<int> leftList{};
    std::list<int> rightList{};
    int leftNum;
    int rightNum;
    while (fscanf(f1, "%d %d", &leftNum, &rightNum) != EOF){
        leftList.push_back(leftNum);
        rightList.push_back(rightNum);
    }
    leftList.sort();
    rightList.sort();

    std::list<int>::iterator it1;
    std::list<int>::iterator it2 = rightList.begin();
    std::unordered_map<int, int> m;
    int totalDistance = 0;
    for (it1 = leftList.begin(); it1 != leftList.end(); ++it1){
        //std::cout << *it1 << " " << *it2 << "\n";
        totalDistance += abs(*it1 - *it2);
        auto search = m.find(*it2);
        if (search != m.end()){
            m[*it2]++;
        }
        else {
            m[*it2] = 1;
        }
        ++it2;
    }
    std::cout << "The total distance for the given input, " << argv[1] << ", is " << totalDistance << ".\n"; 

    int similarityScore = 0;
    for (it1 = leftList.begin(); it1 != leftList.end(); ++it1){
        auto search = m.find(*it1);
        if (search != m.end()){
            //std::cout << *it1 << " " << search->second << "\n";
            similarityScore += *it1 * search->second;
        }
    }
    std::cout << "Total similarity score: " << similarityScore <<".\n";
}


/*
#include <iostream>
#include "lib/helper.h"

int main() {
    std::cout << "Current working directory: " << std::endl;
    system("pwd");  // This will print the current working directory
    return 0;
}
*/