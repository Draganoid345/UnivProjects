#include <bits/stdc++.h>

#include "Automat.hpp"

using namespace std;

ifstream in ("input.in");

int main(){
    Automat automat;
    in >> automat;

    automat.removeUselessStates();

    for (int i=1; i<=automat.nrStates; i++)
        cout << i << " : " << (automat.isUseless[i] ? "Useless" : "Not useless") << '\n';
    
    return 0;
}