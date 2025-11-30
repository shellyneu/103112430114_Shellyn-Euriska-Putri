#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x){
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype input){
    if(root == Nil){
        root = alokasi(input);
        return;
    } else if(input < root->info){
        insertNode(root->left, input);
    } else if(input > root->info){
        insertNode(root->right, input);
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else if(x > root->info){
        return findNode(x, root->right);
    } else {
        return root;
    }
}

void preOrder(address root){ 
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(address root){ 
    if(root == Nil){
        return;
    }
    inOrder(root->left);
    cout << root->info << " - ";
    inOrder(root->right);
}

void postOrder(address root){ 
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}
