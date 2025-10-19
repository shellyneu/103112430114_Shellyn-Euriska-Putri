#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct infoType {
    int number;
};

typedef infoType dataNumber; 
typedef struct node *address; 

struct node { 
    dataNumber info;
    address next;
};

struct linkedList { 
    address first;
};


bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(int number);
void dealokasi(address &node);
void printInfo(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
