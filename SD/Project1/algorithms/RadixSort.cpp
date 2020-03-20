#include "RadixSort.hpp"

void RadixSort::Sort256(std::vector <int> &v){
    std::vector <int> buckets[256];
    int n = v.size();
    for (int cnt = 0, dim = 1; cnt < 4; cnt++, dim *= 256){
        for (int i=0; i<n; i++)
            buckets[(v[i] / dim) % 256].emplace_back(v[i]);
        int idx = 0;
        for (int i=0; i<256; i++){
            for (auto it: buckets[i]) v[idx++] = it;
            buckets[i].clear();
        }
    }
}

void RadixSort::Sort16(std::vector <int> &v){
    std::vector <int> buckets[16];
    int n = v.size();
    for (int cnt = 0, dim = 1; cnt < 8; cnt++, dim *= 16){
        for (int i=0; i<n; i++)
            buckets[(v[i] / dim) % 16].emplace_back(v[i]);
        int idx = 0;
        for (int i=0; i<16; i++){
            for (auto it: buckets[i]) v[idx++] = it;
            buckets[i].clear();
        }
    }
}