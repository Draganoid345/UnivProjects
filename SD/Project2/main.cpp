#include <bits/stdc++.h>
using namespace std;

#include "inc/AVL.hpp"



int main(){
    AVL t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    cout << t.lower_bound(-1) << '\n';
    cout << t.lower_bound(3) << '\n';
    cout << t.upper_bound(4) << '\n';
    cout << t.upper_bound(7) << '\n';
    t.inorder(cout, 2, 4);
    // t.insert(3);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.insert(2);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.insert(1);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.insert(0);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.insert(4);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.insert(5);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.insert(6);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(3);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(2);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(1);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(0);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(4);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(5);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    // t.erase(6);
    // t.inorder(cout);
    // cout << '\n';
    // cout << t.isPresent(6) << '\n';
    return 0;
}