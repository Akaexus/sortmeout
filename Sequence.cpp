#include "Sequence.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

Sequence::Sequence(){}

Sequence::Sequence(std::vector<int> seq) {
    this->sequence = seq;
}

std::vector<int> Sequence::stringToSequence(std::string s) {
    std::vector <int> seq;
    std::string current = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i] =='\n') {
            seq.push_back(atoi(current.c_str()));
            current = "";
        } else {
            current += s[i];
        }
    }
    if(current!="") {
        seq.push_back(atoi(current.c_str()));
    }
    return seq;
}

std::string Sequence::sequenceToString(std::vector<int> seq) {
    std::stringstream output;
    for(int i=0; i<seq.size(); i++) {
        if(i+1 == seq.size()) {
            output << seq[i];
        } else {
            output << seq[i] << "\n";
        }
    }
    return output.str();
}

bool Sequence::saveToFile(std::string path) {
    std::ofstream file;
    file.open(path, std::ios::out);
    if(file.good()) {
        file << this->sequenceToString(this->sequence);
        file.close();
        return true;
    } else {
        return false;
    }
}

bool Sequence::generateSequence(int length, int min, int max) {
    srand(time(NULL));
    for(int i=0; i<length; i++) {
        this->sequence.push_back(rand()%(max-min)+min);
    }
    return true;
}

bool Sequence::loadFromFile(std::string path) {
    std::ifstream file;
    file.open(path, std::ios::in);
    if(file.good() == true) {
        std::string data = "",
            line;
        while(getline(file, line)) {
            data+=line+'\n';
        }
        this->sequence = this->stringToSequence(data);
        file.close();
        return true;
    } else {
        return false;
    }
}

std::string Sequence::prettyPrint() {
    return this->prettyPrint(this->sequence);
}

std::string Sequence::prettyPrint(std::vector<int> v) {
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
