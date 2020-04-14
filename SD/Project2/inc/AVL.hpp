#ifndef _INC_AVL
#define _INC_AVL

#include <vector>
#include <iostream>

class AVL
{
private:
    struct Node{
        int val;
        Node *left_son, *right_son;
        int height;

        Node(int = 0);
        int getHeight()const;
        int getBalance()const;
    };

    size_t size;
    Node* root;

    Node* insert(Node* &node, int &val);
    Node* erase(Node* node, int &val);
    Node* getMin(Node* node);
    bool isPresent(Node* node, int &val)const;
    int lower_bound(Node* node, int &val)const;
    int upper_bound(Node* node, int &val)const;

    Node* rr_rotate(Node* &);
    Node* rl_rotate(Node* &);
    Node* lr_rotate(Node* &);
    Node* ll_rotate(Node* &);

    void inorder(std::ostream&, Node*)const;
    void inorder(std::ostream&, Node*, int& lo, int &hi)const;

public:
    AVL();
    ~AVL();

    void insert(int val);

    void erase(int val);

    void inorder(std::ostream&)const;;
    void inorder(std::ostream&, int lo, int hi)const;

    bool isPresent(int val)const;

    int lower_bound(int val)const;

    int upper_bound(int val)const;

};

#endif // _INC_AVL