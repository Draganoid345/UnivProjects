#include "NFA.hpp"

istream& operator>>(istream& in, NFA& ob){
    int m;
    in >> ob.nrStates >> m;
    ob.transitions.resize(ob.nrStates, vector <set <int> > (ob.SZ));
    ob.isFinal.resize(ob.nrStates, 0);
    ob.isStart.resize(ob.nrStates, 0);
    for (int i=0; i<m; i++){
        int x, y; char c;
        in >> x >> y >> c;
        if (c == '#' && x == y) continue;
        if (c == ob.lambda) ob.transitions[x][0].insert(y);
        else ob.transitions[x][c - 'a' + 1].insert(y);
    }
    in >> m;
    for (int i=0; i<m; i++){
        int x; in >> x;
        ob.isStart[x] = 1;
    }
    in >> m;
    for (int i=0; i<m; i++){
        int x; in >> x;
        ob.isFinal[x] = 1;
    }
    return in;
}

ostream& operator<<(ostream& out, const NFA& ob){
    for (int i=0; i<ob.nrStates; i++){
        for (char c=0; c<=27; c++){
            for (auto it: ob.transitions[i][c]){
                out << i << " -> " << it << " prin " << char((!c ? '#' : (c + 'a' - 1))) << '\n';
            }
        }
    }
    out << "Initial states: \n";
    for (int i=0; i<ob.nrStates; i++)
        if (ob.isStart[i]) out << i << ' ';
    out << '\n';
    out << "Final states: \n";
    for (int i=0; i<ob.nrStates; i++)
        if (ob.isFinal[i]) out << i << ' ';
    out << '\n';
    return out;
}

void NFA::removeLambdaTransitions(){
    bool makeChanges = 1;
    while (makeChanges){
        makeChanges = 0;
        for (int i=0; i < nrStates; i++){
            // consider all lambda-transitions
            for (int it: transitions[i][0]){
                // duplicate all the transitions from v2
                for (char c=0; c <= 'z' - 'a' + 1; c++){
                    for (int it2: transitions[it][c]){
                        transitions[i][c].insert(it2);
                        makeChanges = 1;
                    }
                }
                
                // if the target state is final, then the current one is also a final state
                if (isFinal[it]) isFinal[i] = 1, makeChanges = 1;

                // if current state is an initial state, then the target state is also an initial state
                if (isStart[i]) isStart[it] = 1, makeChanges = 1;
            }
            
            // remove all the considered lambda-transitions
            transitions[i][0].clear();
        }
    }

    
}

NFA::operator DFA(){
    map <set <int>, int> mp;
    set <int> aux;
    queue <int> Q;
    for (int i=0; i < nrStates; i++){
        if (!isStart[i]) continue;
        aux.insert(i);
        mp[aux] = ++n;
    }
}