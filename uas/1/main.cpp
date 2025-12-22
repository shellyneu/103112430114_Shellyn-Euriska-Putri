#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree = Nil;

    cout << "1) Input Data Produk" << endl;
    insertNode(tree, createProduct(50, "Monitor LED", 10));
    insertNode(tree, createProduct(30, "Keyboard RGB", 20));
    insertNode(tree, createProduct(70, "Mouse Gaming", 15));
    insertNode(tree, createProduct(20, "Kabel HDMI", 50));
    insertNode(tree, createProduct(40, "Headset 7.1", 12));
    insertNode(tree, createProduct(60, "Webcam HD", 8));
    insertNode(tree, createProduct(80, "Speaker BT", 5));
    cout << endl << endl;

    cout << "2) inOrder(), preOrder(), dan postOrder() " << endl;
    cout << "InOrder Traversal:" << endl;
    inOrder(tree);
    cout << "PreOrder Traversal:" << endl;
    preOrder(tree);
    cout << "PostOrder Traversal:" << endl;
    postOrder(tree);
    cout << endl << endl;

    cout << "3) searchById(40) " << endl;
    searchById(tree, 40);
    cout << endl << endl;

    cout << "4) searchById(99) " << endl;
    searchById(tree, 99);
    cout << endl << endl;

    cout << "5) searchByProduct() -> Webcam HD " << endl;
    searchByProduct(tree, "Webcam HD");
    cout << endl << endl;

    cout << "6) searchByProduct() -> Printer " << endl;
    searchByProduct(tree, "Printer");
    cout << "Produk dengan nama 'Printer' tidak ditemukan!" << endl;
    cout << endl << endl;

    cout << "7) findMin() dan findMax() " << endl;
    node minNode = findMin(tree);
    node maxNode = findMax(tree);
    if(minNode != Nil) {
        cout << "Produk dengan ID terkecil: " << minNode->idProduk << " - " << minNode->namaProduk << endl;
    }
    if(maxNode != Nil) {
        cout << "Produk dengan ID terbesar: " << maxNode->idProduk << " - " << maxNode->namaProduk << endl;
    }
    cout << endl << endl;

    cout << "8) deleteNode(20) " << endl;
    deleteNode(tree, 20);
    cout << "Node dengan ID 20 berhasil dihapus!" << endl;
    cout << endl << endl;
    
    cout << "9) inOrder() " << endl;
    inOrder(tree);
    cout << endl << endl;
    
    cout << "10) deleteNode(30) " << endl;
    deleteNode(tree, 30);
    cout << "Node dengan ID 30 berhasil dihapus!" << endl;
    cout << endl << endl;
    
    cout << "11) inOrder() " << endl;
    inOrder(tree);
    cout << endl << endl;
    
    cout << "12) deleteNode(50) " << endl;
    deleteNode(tree, 50);
    cout << "Node dengan ID 50 berhasil dihapus!" << endl;
    cout << endl << endl;

    cout << "13) inOrder() " << endl;
    inOrder(tree);
    cout << endl << endl;

    cout << "14) deleteTree() " << endl;
    deleteTree(tree);
    cout << "Seluruh tree berhasil dihapus!" << endl;
    cout << endl << endl;

    cout << "15) inOrder() " << endl;
    if(tree == Nil) {
        cout << "Tree kosong!" << endl;
    } else {
        inOrder(tree);
    }
    cout << endl << endl;

    return 0;
}