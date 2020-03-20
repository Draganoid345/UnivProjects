#include "Utils.hpp"

void Utils::testTheSort(void (*sortFunc) (std::vector <int>&) , std::vector <int> v, std::ostream& out){
    auto start = std::chrono::high_resolution_clock::now();

    sortFunc(v);

    auto stop = std::chrono::high_resolution_clock::now();
    if (isSorted(v)) out << "\tA fost sortat corect!\n";
    else out << "\tATENTIE!!! Nu a fost sortat corect!\n";
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    out << "\tTime elapsed: " << duration.count() << " miliseconds\n";
}

std::vector <int> Utils::generateTest(int n, int valMax, bool negatives){
    std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> _random(1, INT_MAX);

    std::vector <int> aux;
    for (int i=0; i<n; i++){
        int val = _random(rnd) % valMax;
        aux.push_back(val);
        if (!negatives) continue;
        if (i & 1) aux[i] *= -1;
    }
    return aux;

}

bool Utils::isSorted(std::vector <int>& v){
    for (size_t i=1; i < v.size(); i++){
        if (v[i] < v[i-1]) return false;
    }
    return true;
}

