#pragma once // INC_GRAM_

#include "NFA.hpp"

using namespace std;

class RegGram
{
private:
    int nrStates;
    const char lambda = '#';
    map <char, vector <string> > transitions;
public:
    const char initialState = 'S';

    friend istream& operator>>(istream&, RegGram&);
    friend ostream& operator<<(ostream&, const RegGram&);

    explicit operator NFA();
};