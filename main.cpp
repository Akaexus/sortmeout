#include <iostream>
#include <vector>
#include "sort.h"
#include "Sequence.h"



int main() {
    std::cout << "Bye cruel world!";
    Sort heh;
    Sequence xd;
    xd.loadFromFile("/home/krzysztof/CLionProjects/sortmeout/liczby.txt");
    std::cout << xd.prettyPrint(xd.sequence);
    return 0;
}
