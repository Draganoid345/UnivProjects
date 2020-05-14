#include <bits/stdc++.h>

#include "DFA.hpp"
#include "NFA.hpp"
#include "RegGram.hpp"

using namespace std;

ifstream in ("input.in");

int main(){
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

    return 0;
}