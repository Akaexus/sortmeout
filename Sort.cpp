#include "Sort.h"
#include <vector>

std::vector<int> Sort::bubble(std::vector<int> s, bool reverse) {
    for(int i=0; i<s.size(); i++) {
        for(int j=1; j<s.size(); j++) {
            if(reverse?s[j]>s[j-1]:s[j]<s[j-1]) {
                iter_swap(s.begin()+j, s.begin()+j-1);
            }
        }
    }
    return s;
}

std::vector<int> Sort::selection(std::vector<int> s, bool reverse) {
    for(int i=0; i<s.size()-1; i++) {
        int xIndex = i;
        for(int j=i+1; j<s.size(); j++) {
            if(reverse?s[j]>s[xIndex]:s[j]<s[xIndex]) {
                xIndex = j;
            }
        }
        iter_swap(s.begin()+i, s.begin()+xIndex);
    }
    return s;
}

std::vector<int> Sort::insertion(std::vector<int> s, bool reverse) {
    for(int i=1; i<s.size(); i++) {
        int index = s[i],
                j = i-1;
        while(j>=0 && (reverse?s[j]<index:s[j]>index)) {
            iter_swap(s.begin()+j+1, s.begin()+j);
            j--;
        }
    }
    return s;
}

std::vector<int> Sort::mmerge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> result;
    while (a.size() || b.size()) {
        if(a.size() && b.size()) {
            if(a[0] <= b[0]) {
                result.push_back(a[0]);
                a.erase(a.begin());
            }
            else {
                result.push_back(b[0]);
                b.erase(b.begin());
            }
        }  else if(a.size()) {
            for (int i = 0; i < a.size(); i++)
                result.push_back(a[i]);
            break;
        }  else if(b.size()) {
            for (int i = 0; i < b.size(); i++)
                result.push_back(b[i]);
            break;
        }
    }
    return result;
}

std::vector<int> Sort::merge(std::vector<int> s) {
    if(s.size()==1) {
        return s;
    }
    int halfSize = s.size()/2;
    std::vector<int> s1(s.begin(), s.begin()+halfSize);
    std::vector<int> s2(s.begin()+halfSize, s.end());
    s1 = merge(s1);
    s2 = merge(s2);
    return mmerge(s1, s2);
}

std::vector <int> Sort::quick(std::vector<int> s){
    quickPart(s,0,s.size()-1);
    return s;
}

bool Sort::quickPart(std::vector<int>& s, int b, int e){
    int j = b;
    int pivot = s[e];
    for(int i = b; i <= e; i++){
        if(s[i] <= pivot){
            std::swap(s[i], s[j]);
            j++;
        }
    }
    j--;
    if(j + 1 < e){
        quickPart(s, j+1, e);
    }
    if(j-1 > b){
        quickPart(s, b, j-1);
    }
    return true;
}