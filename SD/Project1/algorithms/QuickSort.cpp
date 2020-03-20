#include "QuickSort.hpp"

namespace {
    std::mt19937 rnd(time(0));
}

void QuickSort::Sort(std::vector <int> &v){
    QuickSort::sortUtil(v, 0, v.size() - 1);
}

void QuickSort::sortUtil(std::vector <int> &v, int x, int y){
    int i = x, j = y;
    int k = v[rnd() % (y -x + 1) + x];
    while (i <= j){
        while (v[i] < k) i++;
        while (v[j] > k) j--;
        if (i <= j) std::swap(v[i], v[j]), i++, j--;
    }
    if (j > x) QuickSort::sortUtil(v, x, j);
    if (i < y) QuickSort::sortUtil(v, i, y);
}