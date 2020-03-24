#ifndef NFA_H
#define NFA_H

#include <bits/stdc++.h>
#include "DFA.hpp"

using namespace std;

class NFA{
private:
    int nrStates;
    const int SZ = 30;
    const char lambda = '#';
    vector <vector <set <int> > > transitions;
    vector <bool> isStart;  
    vector <bool> isFinal;
public:
    
    friend istream& operator>>(istream&, NFA&);
    friend ostream& operator<<(ostream&, const NFA&);
    void removeLambdaTransitions();

    explicit operator DFA();
};

#endif