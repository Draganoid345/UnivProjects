#include "Automat.hpp"

istream& operator>> (istream& in, Automat& ob){
    int m;
    in >> ob.nrStates >> m;
    ob.transitions.resize(ob.nrStates + 1, vector <vector <int> > (ob.SZ));
    ob.transitionsInv.resize(ob.nrStates + 1, vector <vector <int> > (ob.SZ));
    for (int i=0; i<m; i++){
        int x, y; char c;
        in >> x >> y >> c;
        ob.transitions[x][c - 'a'].push_back(y);
        ob.transitionsInv[y][c - 'a'].push_back(x);
    }
    in >> ob.initialState;
    in >> m; //number of final states
    ob.finalStates.resize(ob.nrStates + 1, 0);
    ob.isUseless.resize(ob.nrStates + 1, 0);
    for (int i=0; i<m; i++){
        int x;
        in >> x;
        ob.finalStates[x] = 1;
    }
    return in;
}

void Automat::removeUselessStates(){
    queue <int> Q;
    for (int i=1; i <= this->nrStates; i++){
        if (this->finalStates[i]) Q.push(i), this->isUseless[i] = 1;
    }
    while (!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for (char c='a'; c<='z'; c++){
            for (int &it: this->transitionsInv[nod][c - 'a']){
                if (!this->isUseless[it]) Q.push(it), this->isUseless[it] = 1;
            }
        }
    }
    for (int i=1; i <= this->nrStates; i++) this->isUseless[i] = !this->isUseless[i];
}