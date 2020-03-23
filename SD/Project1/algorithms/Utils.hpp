#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <climits>
#include <fstream>

namespace Utils{

    void testTheSort(void (*) (std::vector <int>&) , std::vector <int>, std::ostream& = std::cout);
    
    void generateTest(std::vector <int>&, int, int, bool);

    bool isSorted(std::vector <int>&);
}

#endif