//
// Created by krzysztof on 13.02.18.
//

#ifndef SORTMEOUT_SORT_H
#define SORTMEOUT_SORT_H
#include <vector>

class Sort {
public:
    static std::vector<int> insertion(std::vector<int> s, bool reverse = false);
    static std::vector<int> selection(std::vector<int> s, bool reverse = false);
    static std::vector<int> bubble(std::vector<int> s, bool reverse = false);
    static std::vector<int> merge(std::vector<int> s);
private:
    static std::vector<int> mmerge(std::vector<int> a, std::vector<int> b);
};

#endif //SORTMEOUT_SORT_H
