#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype input);
address findNode(infotype x, address root);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

#endif