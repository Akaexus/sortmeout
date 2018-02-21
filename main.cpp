#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include "Sort.h"
#include "Sequence.h"

int promptInt(std::string name, int min = INT_MIN, int max =INT_MAX) {
    int temp;
    do {
        std::cout << name << "> ";
        while(!(std::cin >> temp)) {
            std::cout << name << "> ";
            std::cin.clear();
            std::cin.ignore();
        }
    } while(temp<min || temp>max);
    return temp;
}

int main() {
    std::vector<std::string> menu = {
                    "Posortuj ${n}-elementowy ciąg wartości od ${a} do ${b}",
                    "${x} razy posortuj ${n}-elementowy ciąg wartości od ${a} do ${b}",
                    "${x} razy posortuj ${n}-elementowy ciąg wartości od ${a} do ${b} (z ${y} przeskokiem)",
                    "exit"

    };
    for(int i=0; i<menu.size(); i++) {
        printf("[%d]\t%s\n", i, menu[i].c_str());
    }
    switch(promptInt("", 1, menu.size())) {

    }
    return 0;
}
