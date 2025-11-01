#ifndef LISTKENDARAAN_H
#define LISTKENDARAAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat;
};

typedef kendaraan infoType;

typedef struct ElmList *address;

struct ElmList{
    infoType isidata;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &ElmList);

bool isNopolExist(List L, string nopol);
void insertLast(List &L, address ElmListBaru);

void printList(List L);

// Searching
void findElm(List L, string nopol);

// Delete
void deleteFirst(List &List);
void deleteLast(List &List);
void deleteAfter(List &List, address Prev);

#endif