#include <bits/stdc++.h>

#include "Automat.hpp"

using namespace std;

ifstream in ("input.in");

int main(){
    Automat automat;
    in >> automat;

    automat.removeUselessStates();

    int nrWords;
    in >> nrWords;
    string word;
    getline(in, word);
    while (nrWords--){
        getline(in, word);
        if (automat.isAccepted(word, automat.initialState))
            cout << word << " apartine automatului\n";
        else cout << word << " nu apartine automatului\n";
        automat.badStates.clear();
    }
    
    vector <string> sol;
    automat.firstWords(sol);

    if (!sol.size()) cout << "Automatul nu accepta nici un cuvant\n";
    else if (sol.size() < 100) cout << "Automatul accent doar " << sol.size() << " cuvinte:\n";
    else cout << "Primele 100 de cuvinte acceptate de automat sunt:\n";
    for (auto &it: sol)
        cout << it << '\n';

    return 0;
}