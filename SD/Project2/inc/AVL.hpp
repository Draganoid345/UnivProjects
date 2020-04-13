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

    Node* insert(Node* node, int &val);

    Node* rr_rotate(Node* &);
    Node* rl_rotate(Node* &);
    Node* lr_rotate(Node* &);
    Node* ll_rotate(Node* &);

    void inorder(std::ostream&, Node*&)const;

public:
    AVL();
    ~AVL();

    void insert(int val);

    void inorder(std::ostream&);   

};

#endif // _INC_AVL