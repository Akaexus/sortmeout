#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <ctime>
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
    std::string sequenceSource[] = {
        "Z pliku",
        "Generuj"
    };
    std::cout << "Zrodla ciagu: \n";
    for(int i=0; i<(sizeof(sequenceSource)/sizeof(*sequenceSource)); i++) {
        printf("\t[%d] %s\n", i, sequenceSource[i].c_str());
    }
    int choice = promptInt("", 0, sizeof(sequenceSource)/sizeof(*sequenceSource));
    Sequence seq;
    if(choice == 0) {
        while(1) {
            std::string path;
            std::cout << "Sciezka: ";
            std::cin >> path;
            if(seq.loadFromFile(path)) {
                std::cout << seq.prettyPrint();
                break;
            }
        }
    } else if(choice == 1) {
        int count = promptInt("Dlugosc ciagu", 1, INT_MAX),
            min = promptInt("Minimalna wartosc w ciagu"),
            max = promptInt("Maksymalna wartosc w ciagu");
        std::cout << count << " " << min << " " << max;
        if(max<min) {
            std::swap(min, max);
        }
        seq.generateSequence(count, min, max);
        std::cout << seq.prettyPrint();
        std::cout << "\nZapisac ciag? [T/n]";
        char c;
        std::cin >> c;
        if(c == 'y' || c == 'Y' || c == 'T' || c == 't' || c == '\n') {
            while(1) {
                std::string path;
                std::cout << "Sciezka> ";
                std::cin >> path;
                if(seq.saveToFile(path)) {
                    break;
                }
            }
        }
    }

    std::cout << "\n\nSORTOWANIE W TOKU\n\n";

    std::map<std::string, clock_t> sortTimes;
    clock_t begin;
    begin = clock();
    Sort::insertion(seq.sequence);
    sortTimes["insertion"] = clock()-begin;

    begin = clock();
    Sort::selection(seq.sequence);
    sortTimes["selection"] = clock()-begin;

    begin = clock();
    Sort::bubble(seq.sequence);
    sortTimes["bubble"] = clock()-begin;

    begin = clock();
    Sort::merge(seq.sequence);
    sortTimes["merge"] = clock()-begin;

    begin = clock();
    seq.sequence = Sort::quick(seq.sequence);
    sortTimes["quicksort"] = clock()-begin;

    std::cout << seq.prettyPrint() << "\n";
    for(std::map<std::string, clock_t>::iterator i = sortTimes.begin(); i!=sortTimes.end(); ++i) {
        printf("%s | %d cykli | %fs\n", i->first.c_str(), i->second, float(i->second)/CLOCKS_PER_SEC);
    }
    std::cout << "Zapisac? [T/n]";
    char c;
    std::cin >> c;
    if(c == 'y' || c == 'Y' || c == 'T' || c == 't' || c == '\n') {
        while(1) {
            std::string path;
            std::cout << "Sciezka> ";
            std::cin >> path;
            if(seq.saveToFile(path)) {
                break;
            }
        }
    }

    return 0;
}
