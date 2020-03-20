#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

class Heap{
private:
    int *h;
    const int capacity;
    int n;
public:
    Heap(int);
    ~Heap();

    void heapUp(int);
    void heapDown(int);
    void insert(int);
    void pop(int);
    int getMin()const;
};

namespace HeapSort{
    void Sort(std::vector <int>&);
}

#endif