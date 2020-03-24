#ifndef DFA_H
#define DFA_H

#include <bits/stdc++.h>
using namespace std;

class DFA{
private:
    int nrStates;
    vector <map<char, int> > transitions;
    vector <bool> isFinal;

public:
    int initialState;

    DFA(vector <map <char, int> >&, int&, vector<bool>&);
    friend ostream& operator << (ostream&, const DFA&);
};

#endif