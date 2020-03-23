#ifndef NFA_H
#define NFA_H

#include <bits/stdc++.h>
using namespace std;

class NFA{
private:
    int nrStates;
    const int SZ = 30;
    const char lambda = '#';
    vector <vector <set <int> > > transitions;
    // vector <vector <vector <int> > > transitionsInv;
    vector <bool> isStart;  
    vector <bool> isFinal;
public:

    friend istream& operator>>(istream&, NFA&);
    friend ostream& operator<<(ostream&, const NFA&);
    void removeLambdaTransitions();

};

#endif