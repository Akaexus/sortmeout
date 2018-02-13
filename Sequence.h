

#ifndef SORTMEOUT_SEQUENCE_H
#define SORTMEOUT_SEQUENCE_H
#include <string>
#include <vector>


class Sequence {
    public:
        Sequence();
        Sequence(std::vector<int> seq);
        std::vector <int> sequence;
        bool loadFromFile(std::string path);
        bool saveToFile(std::string path);
        bool generateSequence(int length, int min, int max);
        std::string prettyPrint(std::vector<int> v);
    protected:
        std::vector<int> stringToSequence(std::string s);
        std::string sequenceToString(std::vector<int> seq);
};


#endif //SORTMEOUT_SEQUENCE_H
