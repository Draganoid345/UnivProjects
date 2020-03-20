#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

namespace MergeSort{

    void Sort(std::vector <int>&);
    void sortUtil(std::vector <int>&, int, int, std::vector <int>&);
}

#endif