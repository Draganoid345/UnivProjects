#ifndef NFA_H
#define NFA_H

#include <bits/stdc++.h>
#include "DFA.hpp"

using namespace std;

class NFA{
private:
    int nrStates;
    const char lambda = '#';
    vector <map<char, set<int> > > transitions; 
    vector <bool> isFinal;
public:
    int initialState;

    NFA();
    NFA(int initialState_, vector < map <char, set<int> > >& transitions_, vector <int>& finalStates_);
    
    friend istream& operator>>(istream&, NFA&);
    friend ostream& operator<<(ostream&, const NFA&);
    void removeLambdaTransitions();

    explicit operator DFA();
};

#endif