#include "MergeSort.hpp"

void MergeSort::Sort(std::vector <int> &v){
    std::vector <int> aux(v.size());
    MergeSort::sortUtil(v, 0, v.size() - 1, aux);
}

void MergeSort::sortUtil(std::vector <int> &v, int st, int dr, std::vector <int> &aux){
    if (st == dr) return;
    int mid = (st + dr) >> 1;
    MergeSort::sortUtil(v, st, mid, aux);
    MergeSort::sortUtil(v, mid+1, dr, aux);
    int idx1 = st, idx2 = mid+1, idx = st;
    while (idx1 <= mid && idx2 <= dr){
        if (v[idx1] < v[idx2]) aux[idx++] = v[idx1++];
        else aux[idx++] = v[idx2++];
    }
    while (idx1 <= mid) aux[idx++] = v[idx1++];
    while (idx2 <= dr) aux[idx++] = v[idx2++];
    for (int i=st; i<=dr; i++) v[i] = aux[i];
}