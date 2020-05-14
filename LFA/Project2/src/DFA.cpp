#include "DFA.hpp"

DFA::DFA(vector <map <char,int> > &edges, int &initState, vector <bool> &finalStates):
    nrStates(edges.size()), transitions(edges), isFinal(finalStates), isUnreachable(vector<bool>(edges.size(), 0)), initialState(initState){}

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
        if (transitions[a].count(c))
            unu = transitions[a][c];
        if (transitions[b].count(c))
            doi = transitions[b][c];
        if (find(pr, unu) != find(pr, doi))
            return false;
    }
    return true;
}

void DFA::removeUnreachableStates(){
    vector <vector <int> > invTrans(nrStates);

    for (int i=0; i<nrStates; i++){
        for (auto edge: transitions[i]){
            invTrans[edge.second].push_back(i);
        }
    }

    isUnreachable.clear();
    isUnreachable.resize(nrStates, 1);

    queue <int> Q;
    vector <bool> viz(nrStates, 0);
    Q.push(initialState);
    viz[initialState] = 1;
    while (!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for (auto &edge: transitions[nod])
            if (!viz[edge.second]) viz[edge.second] = 1, Q.push(edge.second);
    }
    for (int i=0; i<nrStates; i++)
        isUnreachable[i] = (isUnreachable[i] & viz[i]);
    
    viz.clear();
    viz.resize(nrStates, 0);
    for (int i=0; i<nrStates; i++)
        if (isFinal[i]) Q.push(i), viz[i] = 1;
    while (!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for (auto &it: invTrans[nod])
            if (!viz[it]) viz[it] = 1, Q.push(it);
    }

    for (int i=0; i<nrStates; i++) 
        isUnreachable[i] = (isUnreachable[i] & viz[i]), isUnreachable[i] = (isUnreachable[i] ^ 1);
}

void DFA::minimize(){
    removeUnreachableStates();
    vector <vector <int> > pr(2, vector<int>(nrStates, 0));
    map <int, vector<int> > mp[2];
    int fnNod = -1, stNod = -1;
    for (int i=0; i < nrStates; i++){
        // nu e bine sa-l ignor, poate sa-mi imi scape un nod pt rejecturi
        if (isUnreachable[i]) continue;
        if (isFinal[i]){
            if (fnNod == -1) fnNod = i;
            pr[0][i] = fnNod;
            mp[0][fnNod].push_back(i);
        }
        else{
            if (stNod == -1) stNod = i;
            pr[0][i] = stNod;
            mp[0][initialState].push_back(i);
        }
    }
    bool dpState = 1, makeChanges = 1;
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
        pr[dpState].clear();
        pr[dpState].resize(nrStates, 0);
        mp[dpState].clear();
    }
    int n = 0, initState2 = -1;
    vector <int> newIdx(nrStates, -1);
    vector <bool> isFinal2, isUnreachable2;
    for (auto &it: mp[!dpState]){
        newIdx[it.first] = n++;
        isFinal2.push_back(isFinal[it.second.front()]);
        isUnreachable2.push_back(0);
        if (initState2 != -1) continue;
        if (count(it.second.begin(), it.second.end(), initialState)) initState2 = n - 1;
    }
    vector <map <char, int> > edges(n);
    for (int i=0; i<nrStates; i++){
        if (isUnreachable[i]) continue;
        int iFather = pr[!dpState][i];
        for (char c: alfabet){
            for (int &it: mp[!dpState][iFather]){
                if (!transitions[it].count(c)) continue;
                if (isUnreachable[transitions[it][c]]) continue;
                edges[newIdx[iFather]][c] = newIdx[pr[!dpState][transitions[it][c]]];
                break;
            }
        }
    }
    *this = DFA(edges, initState2, isFinal2);
}