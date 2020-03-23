#include <bits/stdc++.h>

#include "NFA.hpp"

using namespace std;

ifstream in ("input.in");

int main(){
    NFA automat;
    in >> automat;

    cout << automat << '\n';

    automat.removeLambdaTransitions();

    cout << automat << '\n';

    return 0;
}