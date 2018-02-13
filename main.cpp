#include <iostream>
#include <vector>
#include "Sort.h"
#include "Sequence.h"



int main() {
    std::cout << "Bye cruel world!";
    Sort heh;
    Sequence xd;
    xd.loadFromFile("/home/krzysztof/CLionProjects/sortmeout/liczby.txt");
    xd.generateSequence(10, 0, 10);
    std::cout << xd.prettyPrint(heh.bubble(xd.sequence));
    return 0;
}
