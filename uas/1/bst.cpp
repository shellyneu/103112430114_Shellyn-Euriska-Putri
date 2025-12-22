#include "bst.h"
#include <iostream>

using namespace std;

node createProduct(int idProduk, string namaProduk, int stok) {
    node produkBaru = new BST;
    produkBaru->idProduk = idProduk;
    produkBaru->namaProduk = namaProduk;
    produkBaru->stok = stok;
    produkBaru->left = Nil;
    produkBaru->right = Nil;
    return produkBaru;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Produk dengan ID " << nodeBaru->idProduk << " berhasil ditambahkan!" << endl;
        return;
    } else if(nodeBaru->idProduk < tree->idProduk){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->idProduk > tree->idProduk){
        insertNode(tree->right, nodeBaru);
    } else {
        cout << "ID Produk sudah ada!" << endl;
    }
}

void searchById(BinTree tree, int idProduk){
    if(tree == Nil){
        cout << "Tree kosong!" << endl;
        return;
    }
    
    node nodeBantu = tree;
    bool ketemu = false;
    
    while(nodeBantu != Nil){
        if(idProduk < nodeBantu->idProduk){
            nodeBantu = nodeBantu->left;
        } else if(idProduk > nodeBantu->idProduk){
            nodeBantu = nodeBantu->right;
        } else {
            ketemu = true;
            break;
        }
    }
    
    if(ketemu){
        cout << "Produk ditemukan!" << endl;
        cout << "ID Produk: " << nodeBantu->idProduk << endl;
        cout << "Nama Produk: " << nodeBantu->namaProduk << endl;
        cout << "Stok: " << nodeBantu->stok << endl;
    } else {
        cout << "Produk dengan ID " << idProduk << " tidak ditemukan!" << endl;
        return;
    }
}

void searchByProduct(BinTree tree, string namaProduk){
    if(tree == Nil){
        return;
    }
    
    searchByProduct(tree->left, namaProduk);
    
    if(tree->namaProduk == namaProduk){
        cout << "Produk ditemukan!" << endl;
        cout << "ID Produk: " << tree->idProduk << endl;
        cout << "Nama Produk: " << tree->namaProduk << endl;
        cout << "Stok: " << tree->stok << endl;
    }
    
    searchByProduct(tree->right, namaProduk);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << "ID: " << tree->idProduk << " - " << tree->namaProduk << " (Stok: " << tree->stok << ")" << endl;
    inOrder(tree->right);
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << "ID: " << tree->idProduk << " - " << tree->namaProduk << " (Stok: " << tree->stok << ")" << endl;
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << "ID: " << tree->idProduk << " - " << tree->namaProduk << " (Stok: " << tree->stok << ")" << endl;
}



void deleteNode(BinTree &tree, int idProduk) {
    if (tree == Nil) {
        cout << "Produk dengan ID " << idProduk << " tidak ditemukan!" << endl;
        return;
    }
    
    if (idProduk < tree->idProduk) {
        deleteNode(tree->left, idProduk);
    } else if (idProduk > tree->idProduk) {
        deleteNode(tree->right, idProduk);
    } else {
        
        if (tree->left == Nil && tree->right == Nil) {
            delete tree;
            tree = Nil;
        } else if (tree->left == Nil) {
            node nodeBantu = tree;
            tree = tree->right;
            delete nodeBantu;
        } else if (tree->right == Nil) {
            node nodeBantu = tree;
            tree = tree->left;
            delete nodeBantu;
        } else {
            node successor = findMin(tree->right);
            tree->idProduk = successor->idProduk;
            tree->namaProduk = successor->namaProduk;
            tree->stok = successor->stok;
            deleteNode(tree->right, successor->idProduk);
        }
    }
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    }
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
    tree = Nil;
}

node findMin(BinTree tree){
    if(tree == Nil){
        return Nil;
    }
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

node findMax(BinTree tree){
    if(tree == Nil){
        return Nil;
    }
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;
}
