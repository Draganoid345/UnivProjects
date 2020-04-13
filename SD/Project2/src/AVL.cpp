#include "AVL.hpp"

#include <queue>

int max(int a, int b){return (a > b ? a : b);}

AVL::Node::Node(int _val): val(_val), left_son(NULL), right_son(NULL), height(1){}

int AVL::Node::getHeight()const{
    if (this == NULL){
        return 0;
    }
    int left_side = 0, right_side = 0;
    if (left_son){
        left_side = left_son->height;
    }
    if (right_son){
        right_side = right_son->height;
    }
    return max(left_side, right_side) + 1;
}

int AVL::Node::getBalance()const{
    if (this == NULL){
        return 0;
    }
    int left_side = 0, right_side = 0;
    if (left_son){
        left_side = left_son->getHeight();
    }
    if (right_son){
        right_side = right_son->getHeight();
    }
    return left_side - right_side;
}

AVL::AVL():size(0), root(NULL){}

AVL::Node* AVL::insert(Node* node, int &val){
    if (node == NULL){
        node = new Node(val);
        return node;
    }
    if (val < node->val){
        node->left_son = insert(node->left_son, val);

        if (node->getBalance() == 2){

            if (val < node->left_son->val){
                node = ll_rotate(node);
            }
            else{
                node = lr_rotate(node);
            } 
        }
    }
    else{
        node->right_son = insert(node->right_son, val);

        if (node->getBalance() == -2){

            if (val > node->right_son->val){
                node = rr_rotate(node);
            }
            else{
                node = rl_rotate(node);
            }
        }
    }
    node->height = node->getHeight();
    return node;
}

void AVL::insert(int val){
    root = insert(root, val);
}

AVL::~AVL(){
    if (root == NULL)
        return;
    std::queue <Node*> Q;
    Q.push(root);
    while (!Q.empty()){
        Node *current_node = Q.front();
        if (current_node->left_son)
            Q.push(current_node->left_son);
        if (current_node->right_son)
            Q.push(current_node->right_son);
        delete current_node;
    }
}

AVL::Node* AVL::ll_rotate(Node* &pivot){

    Node* aux = pivot->left_son;

    pivot->left_son = aux->right_son;
    pivot->height = pivot->getHeight();

    aux->right_son = pivot;
    aux->height = aux->getHeight();
    return aux;
}

AVL::Node* AVL::lr_rotate(Node* &pivot){
    pivot->left_son = rr_rotate(pivot->left_son);
    return ll_rotate(pivot);
}
AVL::Node* AVL::rl_rotate(Node* &pivot){
    pivot->right_son = ll_rotate(pivot->right_son);
    return rr_rotate(pivot);
}
AVL::Node* AVL::rr_rotate(Node* &pivot){
    Node* aux = pivot->right_son;

    pivot->right_son = aux->left_son;
    pivot->height = pivot->getHeight();

    aux->left_son = pivot;
    aux->height = aux->getHeight();

    return aux;
}

void AVL::inorder(std::ostream& os){
    inorder(os, root);
}

void AVL::inorder(std::ostream& os, Node* &nod)const{
    if (nod == NULL) return;
    inorder(os, nod->left_son);
    os << nod->val << ' ';
    inorder(os, nod->right_son);
}