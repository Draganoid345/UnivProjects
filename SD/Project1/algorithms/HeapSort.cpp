#include "HeapSort.hpp"

Heap::Heap(int len):h(new int[len+1]), capacity(len), n(0){};

Heap::~Heap(){
    delete []h;
}

void Heap::heapUp(int idx){
    while (idx > 1 && this->h[idx] < this->h[idx / 2]){
        std::swap(this->h[idx], this->h[idx / 2]);
        idx /= 2;
    }
    return;
}

void Heap::heapDown(int idx){
    int son = idx;
    while (son){
        if (2 * idx <= this->n && this->h[2 * idx] < this->h[son]) son = 2 * idx;
        if (2 * idx + 1 <= this->n && this->h[2*idx + 1] < this->h[son]) son = 2*idx + 1;
        if (son != idx){
            std::swap(this->h[idx], this->h[son]);
            idx = son;
        }
        else son = 0;
    }
    return;
}

void Heap::insert(int val){
    this->h[++n] = val;
    heapUp(n);
    return;
}

void Heap::pop(int idx){
    std::swap(this->h[idx], this->h[n--]);
    heapDown(idx);
    return;
}

int Heap::getMin()const{
    return this->h[1];
}

void HeapSort::Sort(std::vector <int> &v){
    Heap heap(v.size());
    for (auto &it: v) heap.insert(it);
    for (size_t i=0; i < v.size(); i++){
        v[i] = heap.getMin();
        heap.pop(1);
    }
}