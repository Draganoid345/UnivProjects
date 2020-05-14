#include "RegGram.hpp"
#include <bits/stdc++.h>

istream& operator>>(istream& in, RegGram& ob){
    int m;
    in >> m;
    for (int i=0; i < m; i++){
        char x; string y;
        in >> x >> y;
        ob.transitions[x].push_back(y);
    }
    ob.nrStates = ob.transitions.size();
    return in;
}

ostream& operator<<(ostream& out, const RegGram& ob){
    out << "Numarul de stari: " << ob.transitions.size() << '\n';
    for (auto &it: ob.transitions){
        out << it.first << " -> ";
        for (string to: it.second){
            out << to << " | ";
        }
        out << '\n';
    }
    return out;
}

RegGram::operator NFA(){
    vector < map <char, set<int> > > newTransitions(nrStates + 1);
    vector <int> newFinalStates = {nrStates};
    unordered_map <char, int> reorderedStates;
    unsigned cnt = 0;
    for (auto &it: transitions){
        reorderedStates[it.first] = cnt++;
    }
    for (auto &it: transitions){
        for (string trans: it.second){
            if (trans.size() == 1){
                newTransitions[reorderedStates[it.first]][trans[0]].insert(nrStates);
            }
            else if (trans.size() == 2){
                newTransitions[reorderedStates[it.first]][trans[0]].insert(reorderedStates[trans[1]]);
            }
            else
                throw runtime_error("Regular Grammar transitions was given in the wrong format!");
        }
        cnt++;
    }

    return NFA(reorderedStates[initialState], newTransitions, newFinalStates);
}