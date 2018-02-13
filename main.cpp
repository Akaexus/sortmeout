#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>

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

std::vector<int> bubbleSort(std::vector<int> sequence, bool reverse = false) {
    for(int i=0; i<sequence.size(); i++) {
        for(int j=1; j<sequence.size(); j++) {
            if(reverse?sequence[j]>sequence[j-1]:sequence[j]<sequence[j-1]) {
                iter_swap(sequence.begin()+j, sequence.begin()+j-1);
            }
        }
    }
    return sequence;
}

std::vector<int> selectionSort(std::vector<int> unsorted, bool reverse = false) {
    for(int i=0; i<unsorted.size()-1; i++) {
        int xIndex = i;
        for(int j=i+1; j<unsorted.size(); j++) {
            if(reverse?unsorted[j]>unsorted[xIndex]:unsorted[j]<unsorted[xIndex]) {
                xIndex = j;
            }
        }
        iter_swap(unsorted.begin()+i, unsorted.begin()+xIndex);
    }
    return unsorted;
}

std::vector<int> insertionSort(std::vector<int> unsorted, bool reverse = false) {
    for(int i=1; i<unsorted.size(); i++) {
        int index = unsorted[i],
            j = i-1;
        while(j>=0 && (reverse?unsorted[j]<index:unsorted[j]>index)) {
            iter_swap(unsorted.begin()+j+1, unsorted.begin()+j);
            j--;
        }
    }
    return unsorted;
}

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
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




std::vector<int> mergeSort(std::vector<int> s) {
    if(s.size()==1) {
        return s;
    }
    int halfSize = s.size()/2;
    std::vector<int> s1(s.begin(), s.begin()+halfSize);
    std::vector<int> s2(s.begin()+halfSize, s.end());
    s1 = mergeSort(s1);
    s2 = mergeSort(s2);
    return merge(s1, s2);
}

int main() {
    std::vector xd = generateSequence(21, 0, 10000);
    std::cout << prettyPrint(xd);
    std::cout << "\n\n\n";
    xd = bubbleSort(xd);
    std::cout << prettyPrint(xd);
    return 0;
}