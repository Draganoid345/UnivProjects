#ifndef AUTOMAT_H
#define AUTOMAT_H

#include <bits/stdc++.h>
using namespace std;

class Automat {
//make private!!!!!!
private:
    int nrStates;
    const int SZ = 30;
    vector <vector <vector <int> > > transitions;
    vector <vector <vector <int> > > transitionsInv;    
    vector <bool> finalStates;
    vector <bool> isUseless;

    struct nodeStates{
        int node, len;

        bool operator<(const nodeStates& other)const{
            if (len == other.len) return node < other.node;
            else return len < other.len;
        }
    };
    

public:
    int initialState;
    map <nodeStates, bool> badStates;

    friend istream& operator>> (istream&, Automat&);
    void removeUselessStates();
    bool isAccepted(string&, int, int = 0);
    void firstWords(vector <string>&, int = 100)const;
};

#endif