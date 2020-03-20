#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <chrono>
#include <random>
#include <climits>

namespace QuickSort{

    void Sort(std::vector <int>&);
    void sortUtil(std::vector <int>&, int, int);
}

#endif