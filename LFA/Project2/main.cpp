#include <bits/stdc++.h>

#include "NFA.hpp"

using namespace std;

ifstream in ("input.in");

int main(){
    NFA automat;
    in >> automat;

    cout << "Read the NFA:\n";
    cout << automat << '\n';

    automat.removeLambdaTransitions();

    cout << "Removed the lambda transitions:\n";
    cout << automat << '\n';

    //casting, sort of constructor operator
    DFA automat2 = DFA(automat);

    cout << "Converted the NFA to DFA:\n";
    cout << automat2 << '\n';

    automat2.minimize();
    cout << "Minimized the DFA:\n";

    cout << automat2;

    return 0;
}