#include "AVL.hpp"

#include <queue>

int max(int a, int b){return (a > b ? a : b);}

AVL::Node::Node(int _val): val(_val), left_son(NULL), right_son(NULL), height(1){}

int AVL::Node::getHeight()const{
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

AVL::Node* AVL::insert(Node* &node, int &val){
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

AVL::Node* AVL::erase(Node* node, int &val){
    if (node == NULL)
        return NULL;

    if (node->val == val){
        
        // 2 children
        if (node->left_son != NULL && node->right_son != NULL){
            Node* t = getMin(node->right_son);            
            node->val = t->val;
            node->right_son = erase(node->right_son, t->val);
        }
        // 1 or 0 children
        else {
            Node *u = node;
            if (node->left_son)
                node = node->left_son;
            else
                node = node->right_son;
            delete u;
        }        
    }
    else if (val < node->val)
        node->left_son = erase(node->left_son, val);
    else
        node->right_son = erase(node->right_son, val);
    
    if (node == NULL)
        return NULL;
    if (node->getBalance() == 2){
        if (node->left_son->left_son == NULL)
            node = lr_rotate(node);
        else
            node = ll_rotate(node);
    }
    else if (node->getBalance() == -2){
        if (node->right_son->right_son == NULL)
            node = rl_rotate(node);
        else
            node = rr_rotate(node);
    }

    return node;
}

void AVL::insert(int val){
    root = insert(root, val);
}

void AVL::erase(int val){
    root = erase(root, val);
}

AVL::~AVL(){
    if (root == NULL)
        return;
    std::queue <Node*> Q;
    Q.push(root);
    while (!Q.empty()){
        Node *current_node = Q.front();
        Q.pop();
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

void AVL::inorder(std::ostream& os)const{
    inorder(os, root);
}

void AVL::inorder(std::ostream& os, int lo, int hi)const{
    inorder(os, root, lo, hi);
}

void AVL::inorder(std::ostream& os, Node* node, int &lo, int &hi)const{
    if (node == NULL) return;
    inorder(os, node->left_son, lo, hi);
    if (node->val >= lo && node->val <= hi)
        os << node->val << ' ';
    inorder(os, node->right_son, lo, hi);
}

void AVL::inorder(std::ostream& os, Node* nod)const{
    if (nod == NULL) return;
    inorder(os, nod->left_son);
    os << nod->val << ' ';
    inorder(os, nod->right_son);
}

AVL::Node* AVL::getMin(Node* node){
    if (node == NULL)
        return NULL;
    if (node->left_son)
        return getMin(node->left_son);
    else return node;
}

bool AVL::isPresent(int val)const{
    return isPresent(root, val);
}

bool AVL::isPresent(Node* node, int &val)const{
    if (node == NULL)
        return 0;
    else if (node->val == val)
        return 1;
    else if (val < node->val)
        return isPresent(node->left_son, val);
    else
        return isPresent(node->right_son, val);
}

int AVL::lower_bound(int val)const{
    return lower_bound(root, val);
}

int AVL::lower_bound(Node* node, int &val)const{
    if (node == NULL)
        return val - 1;
    if (val > node->val)
        return lower_bound(node->right_son, val);
    int aux = lower_bound(node->left_son, val);
    if (aux < val)
        return node->val;
    else
        return aux;
}

int AVL::upper_bound(int val)const{
    return upper_bound(root, val);
}

int AVL::upper_bound(Node* node, int &val)const{
    if (node == NULL)
        return val + 1;
    if (val < node->val)
        return upper_bound(node->left_son, val);
    int aux = upper_bound(node->right_son, val);
    if (aux > val)
        return node->val;
    else
        return aux;
}