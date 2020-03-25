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

int DFA::find(vector <int> &pr, int q)const{
    if (q == -1) return -1;
    if (q == pr[q]) return q;
    pr[q] = find(pr, pr[q]);
    return pr[q];
}

bool DFA::isSameClass(vector <int> &pr, int &a, int &b){
    for (char c: alfabet){
        int unu = -1, doi = -1;
        if (transitions[a].count(c)) unu = transitions[a][c];
        if (transitions[b].count(c)) doi = transitions[b][c];
        if (find(pr, unu) != find(pr, doi)) return false;
    }
    return true;
}

void DFA::minimize(){
    removeUnreachableStates();
    vector <vector <int> > pr(2, vector<int>(nrStates, 0));
    map <int, vector<int> > mp[2];
    int fnNod = -1;
    for (int i=0; i < nrStates; i++){
        if (isUnreachable[i]) continue;
        if (isFinal[i]){
            if (fnNod == -1) fnNod = i;
            pr[0][i] = fnNod;
            mp[0][fnNod].push_back(i);
        }
        else{
            pr[0][i] = initialState;
            mp[0][initialState].push_back(i);
        }
    }
    bool dpState = 1, makeChanges = 1;
    for (auto it: mp[!dpState]){
        for (auto it2: it.second) cout << it2 << ' ';
        cout << "\n";
    }
    cout << "\n\n";
    while (makeChanges){
        makeChanges = 0;
        for (auto &eqClass: mp[!dpState]){
            // maybe do an optimization here
            // if (eqClass.second.size() == 1) continue;
            pr[dpState][eqClass.second.front()] = eqClass.second.front();
            mp[dpState][eqClass.second.front()].push_back(eqClass.second.front());
            for (int i=1; i < (int) eqClass.second.size(); i++){
                bool notFound = 1;
                for (int j=0; j < i && notFound; j++){
                    // daca am gasit o stare din aceeasi stare de echivalenta
                    if (isSameClass(pr[!dpState], eqClass.second[i], eqClass.second[j])){
                        pr[dpState][eqClass.second[i]] = eqClass.second[j];
                        mp[dpState][eqClass.second[j]].push_back(eqClass.second[i]);
                        notFound = 0;
                    }
                }
                // daca nu am gasit nici o stare echivalenta, ii creeam propria clasa de echivalenta
                if (notFound){
                    pr[dpState][eqClass.second[i]] = eqClass.second[i];
                    mp[dpState][eqClass.second[i]].push_back(eqClass.second[i]);
                    makeChanges = 1;
                }
            }
        }
        dpState = !dpState;
        for (auto it: mp[!dpState]){
            for (auto it2: it.second) cout << it2 << ' ';
            cout << "\n";
        }
        for (int i=0; i<nrStates; i++)
            cout << i << " : " << pr[!dpState][i] << '\n';
        cout << "\n\n";
        pr[dpState].resize(nrStates, 0);
        mp[dpState].clear();
    }
    for (auto it: mp[!dpState]){
        for (auto it2: it.second) cout << it2 << ' ';
        cout << '\n';
    }
    int cnt = 0;
    vector <int> newIdx(nrStates);
    for (int i=0; i<nrStates; i++){
        if (isUnreachable[i]) cnt++;
        else newIdx[i] = i - cnt;
    }
}