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
    
    return 0;
}