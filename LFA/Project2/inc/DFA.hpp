#ifndef DFA_H
#define DFA_H

#include <bits/stdc++.h>
using namespace std;

const string alfabet = "#abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

class DFA{
private:
    int nrStates;
    vector <map<char, int> > transitions;
    vector <bool> isFinal;
    vector <bool> isUnreachable;

public:
    int initialState;

    // constructor that will be used to cast the NFA into a DFA
    DFA(vector <map <char, int> >&, int&, vector<bool>&);
    DFA(vector <map <char, int> >&, int&, vector<bool>&, vector<bool>&);

    friend ostream& operator << (ostream&, const DFA&);
    void removeUnreachableStates();
    int find(vector <int>&, int)const;
    bool isSameClass(vector <int>&, int&, int&);
    void minimize();
};

#endif