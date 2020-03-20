#include "BubbleSort.hpp"

void BubbleSort::Sort(std::vector <int> &v){
    for (size_t k=1; k<v.size(); k++){
        for (size_t i =1; i<v.size(); i++){
            if (v[i] < v[i-1]) std::swap(v[i], v[i-1]);
        }
    }
}