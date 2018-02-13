#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "sort.h"

std::vector<int> generateSequence(int length, int min, int max) {
    srand(time(NULL));
    std::vector<int> sequence;
    for(int i=0; i<length; i++) {
        sequence.push_back(rand()%max+min);
    }
    return sequence;
}

std::string prettyPrint(std::vector<int> v) {
    std::stringstream output;
    output << "[ ";
    int size = v.size();
    for(int i=0; i<size; i++) {
        if(i+1==v.size()) {
            output << "  " << v[i] << " ]";
        } else {
            output << (i?"  ":"") << v[i] << ',' << (size>20?"\n":"");
        }
    }
    return output.str();
}


int main() {
    std::vector xd = generateSequence(21, 0, 10000);
    std::cout << prettyPrint(xd);
    std::cout << "\n\n\n";
    xd = Sort::bubble(xd);
    std::cout << prettyPrint(xd);
    return 0;
}