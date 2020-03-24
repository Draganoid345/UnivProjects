#include "DFA.hpp"

DFA::DFA(vector <map <char,int> > &edges, int &initState, vector <bool> &finalStates):
    nrStates(edges.size()), transitions(edges), isFinal(finalStates), initialState(initState){}

ostream& operator<<(ostream &out, const DFA &ob){
    out << ob.nrStates << " states\n";
    for (int i=0; i<ob.nrStates; i++){
        for (auto &edge: ob.transitions[i]){
            out << i << " -> " << edge.second << " prin " << edge.first << '\n';
        }
    }
    out << "Initial state: " << ob.initialState << '\n';
    out << "Final states:\n";
    for (int i=0; i<ob.nrStates; i++)
        if (ob.isFinal[i]) out << i << ' ';
    out << '\n';
    return out;
}