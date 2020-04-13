#include <bits/stdc++.h>
using namespace std;

#include "inc/AVL.hpp"



int main(){
    AVL t;
    t.insert(3);
    t.inorder(cout);
    cout << '\n';
    t.insert(2);
    t.inorder(cout);
    cout << '\n';
    t.insert(1);
    t.inorder(cout);
    cout << '\n';
    t.insert(0);
    t.inorder(cout);
    cout << '\n';
    t.insert(4);
    t.inorder(cout);
    cout << '\n';
    t.insert(5);
    t.inorder(cout);
    cout << '\n';
    t.insert(6);
    t.inorder(cout);
    cout << '\n';
    return 0;
}