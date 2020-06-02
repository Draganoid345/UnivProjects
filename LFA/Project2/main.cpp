#include <bits/stdc++.h>

#include "DFA.hpp"
#include "NFA.hpp"
#include "RegGram.hpp"

using namespace std;

ifstream in ("input.in");

int main(){

    cout << "Choose the program:\n";
    cout << "1 - lambda-NFA to DFA\n";
    cout << "2 - regular grammar to DFA\n";
    int x;
    cin >> x;

    if (x == 1){
        NFA automatNFA;
        in >> automatNFA;

        cout << "Read the (lambda) NFA:\n";
        cout << automatNFA << '\n';

        automatNFA.removeLambdaTransitions();
        cout << "Removed lambda transitions:\n";
        cout << automatNFA << '\n';

        DFA automatDFA = DFA (automatNFA);
        cout << "Converted to DFA:\n";
        cout << automatDFA << '\n';

        automatDFA.minimize();
        cout << "Minimized DFA:\n";
        cout << automatDFA << '\n';
    }
    else{
        RegGram GramaticaRegulata;
        in >> GramaticaRegulata;

        cout << "Read the Regular Grammar:\n";
        cout << GramaticaRegulata << '\n';

        NFA automatNFA = NFA(GramaticaRegulata);
        cout << "Got the (lambda)NFA:\n";
        cout << automatNFA << '\n';

        DFA automatDFA = DFA(automatNFA);
        cout << "Got the DFA\n";
        cout << automatDFA << '\n';

        automatDFA.minimize();
        cout << "DFA minimizat:\n";
        cout << automatDFA << '\n';
    }
    return 0;
}