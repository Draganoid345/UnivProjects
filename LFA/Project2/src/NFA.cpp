#include "NFA.hpp"
#include <bits/stdc++.h>

NFA::NFA() {}

istream& operator>>(istream& in, NFA& ob){
    int m;
    in >> ob.nrStates >> m;
    ob.transitions.resize(ob.nrStates, map<char, set<int>>());
    ob.isFinal.resize(ob.nrStates, 0);
    for (int i=0; i<m; i++){
        int x, y; char c;
        in >> x >> y >> c;
        if (c == ob.lambda && x == y) continue;
        ob.transitions[x][c].insert(y);
    }
    in >> ob.initialState;
    in >> m;
    for (int i=0; i<m; i++){
        int x; in >> x;
        ob.isFinal[x] = 1;
    }
    return in;
}

ostream& operator<<(ostream& out, const NFA& ob){
    out << ob.nrStates << " states\n";
    for (int i=0; i<ob.nrStates; i++){
        for (auto edge: ob.transitions[i]){
            for (auto to: edge.second){
                out << i << " -> " << to << " prin " << char(edge.first) << '\n';
            }
        }
    }
    out << "Initial state: " << ob.initialState << '\n';
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
            if (!transitions[i].count(lambda)) continue;
            // consider all lambda-transitions
            for (int it: transitions[i][lambda]){
                // duplicate all the transitions from to
                for (auto &edge: transitions[it]){
                    for (auto &it2: edge.second){
                        transitions[i][edge.first].insert(it2);
                        makeChanges = 1;
                    }
                }

                // if the target state is final, then the current one is also a final state
                if (isFinal[it]) isFinal[i] = 1, makeChanges = 1;
            }
            transitions[i][lambda].clear();
        }
    }    
}

NFA::operator DFA(){
    this->removeLambdaTransitions();
    vector <map<char, int> > edges;
    vector <bool> finalStates;
    map <set <int>, int> mp;
    set <int> aux;
    queue < set<int> > Q;
    int n = 0;
    aux.insert(initialState);
    Q.push(aux);
    finalStates.push_back(isFinal[initialState]);
    mp[aux] = n++;
    edges.push_back(map<char, int>());
    aux.clear();
    while (!Q.empty()){
        set <int> curr = Q.front();
        Q.pop();
        for (char c: alfabet){
            for (auto &from: curr){
                for (auto &to: transitions[from][c]){
                    aux.insert(to);
                }
            }
            if (!aux.size()) continue;
            if (!mp.count(aux)){
                finalStates.push_back(0);
                for (const int &it: aux){
                    if (isFinal[it]) finalStates.back() = 1;
                }
                mp[aux] = n++;
                edges.push_back(map <char, int>());
                Q.push(aux);
            }
            edges[mp[curr]][c] = mp[aux];
            aux.clear();
        }
    }
    return DFA(edges, mp[{initialState}], finalStates);
}

NFA::NFA(int initialState_, vector < map <char, set<int> > >& transitions_, vector <int>& finalStates_):
    nrStates(transitions_.size()), transitions(transitions_), initialState(initialState_)
{
    isFinal.resize(nrStates);
    for (int it: finalStates_)
        isFinal[it] = 1;
}