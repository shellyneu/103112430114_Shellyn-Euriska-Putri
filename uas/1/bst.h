#ifndef BST_H
#define BST_H
#define Nil NULL

#include <string>
using namespace std;

typedef struct BST *node;

struct BST {
    int idProduk;
    string namaProduk;
    int stok;
    node left;
    node right;
};

typedef node BinTree;

node createProduct(int idProduk, string namaProduk, int stok);
void insertNode(BinTree &tree, node nodeBaru);
void searchById(BinTree tree, int idProduk);
void searchByProduct(BinTree tree, string namaProduk);
void deleteNode(BinTree &tree, int idProduk);
void inOrder(BinTree tree);
void preOrder(BinTree tree);
void postOrder(BinTree tree);
void deleteTree(BinTree &tree);
node findMin(BinTree tree);
node findMax(BinTree tree);

#endif