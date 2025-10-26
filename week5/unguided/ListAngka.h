//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka; //Memberikan nama alias dataAngka untuk struct angka.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataAngka isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 5
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int angka);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void SearchNodeByData(linkedlist list, int data);
void SearchNodeByAddress(linkedlist list, address node);
void SearchNodeByMinValue(linkedlist list, int nilaiMin);

//operasi aritmetika
int penjumlahan(linkedlist List);
int pengurangan(linkedlist List);
int perkalian(linkedlist List);

#endif