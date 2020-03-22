#include <bits/stdc++.h>

#include "Automat.hpp"

using namespace std;

ifstream in ("test.in");

int main(){
    Automat automat;
    in >> automat;

    for (int i=1; i <= automat.nrStates; i++){
        for (int j='a'; j<='z'; j++){
            for (int &it: automat.transitions[i][j - 'a'])
                cout << i << " - " << char(j) << " - > " << it << '\n';
        }
    }

    return 0;
}