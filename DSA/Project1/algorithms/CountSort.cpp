#include "CountSort.hpp"

void CountSort::Sort(std::vector <int>& v){
    int valMin = (1 << 30), valMax = -(1 << 30);
    for (size_t i=0; i<v.size(); i++)
        valMin = std::min(valMin, v[i]), valMax = std::max(valMax, v[i]);
    
    std::vector <int> fv(valMax - valMin + 1, 0);

    for (size_t i=0; i<v.size(); i++)
        fv[v[i] - valMin]++;
    
    int cnt = 0;
    for (int i=0; i<=valMax - valMin; i++){
        while (fv[i]) v[cnt++] = i + valMin, fv[i]--;
    }
}