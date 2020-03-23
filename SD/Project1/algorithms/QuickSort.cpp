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

void QuickSort::Sort3(std::vector <int> &v){
    QuickSort::sortUtil3(v, 0, v.size() - 1);
}

void QuickSort::sortUtil3(std::vector <int> &v, int x, int y){
    int i = x, j = y;

    int aux1 = v[rnd() % (y -x + 1) + x];
    int aux2 = v[rnd() % (y -x + 1) + x];
    int aux3 = v[rnd() % (y -x + 1) + x];

    if (aux2 < aux1) std::swap(aux1, aux2);
    if (aux3 < aux1) std::swap(aux1, aux3);
    if (aux3 < aux2) std::swap(aux2, aux3);

    int k = aux2;
    
    while (i <= j){
        while (v[i] < k) i++;
        while (v[j] > k) j--;
        if (i <= j) std::swap(v[i], v[j]), i++, j--;
    }
    if (j > x) QuickSort::sortUtil(v, x, j);
    if (i < y) QuickSort::sortUtil(v, i, y);
}