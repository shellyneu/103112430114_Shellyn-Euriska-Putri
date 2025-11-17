#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#define Nil NULL

#include<iostream>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef Product dataProduct; 
typedef struct node *address; 

struct node { 
    dataProduct info;
    address next;
};

struct List { 
    address first;
};


bool isEmpty(List L);
void createList(List &L);
address alokasi(Product P);
void dealokasi(address &addr);

void insertFirst(List &L, Product P);
void insertAfter(List &L, address Q, Product P);
void insertLast(List &L, Product P);

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleleAfter(List &L, address Q, Product &P);

void updateAtPosition(List L, int posisi);

void viewList(List L);

void SearchByFinalPriceRange(List L, float minPrice, float maxPrice);

//Bagian B
void MaxHargaAkhir(List L);

#endif
