#include "SLLInventory.h"

#include<iostream>
using namespace std;

int main(){
    List L;
    createList(L);

    Product P1 = {"Puple", "A001", 20, 2500.0, 0};
    Product P2 = {"Buku Tulis", "A002", 15, 5000.0, 10.0};
    Product P3 = {"Penghapus", "A003", 30, 1500.0, 0};
    Product update = {"Stabilo", "A0101", 40, 9000.0, 5.0};

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    viewList(L);

    deleteFirst(L, P1);
    cout << "Setelah menghapus produk pertama:" << endl;
    viewList(L);

    updateAtPosition(L, 2);
    cout << "Setelah mengupdate produk pada posisi 2:" << endl;
    viewList(L);

    float minPrice = 2000.0;
    float maxPrice = 7000.0;
    SearchByFinalPriceRange(L, minPrice, maxPrice);

    //Bagian B
    MaxHargaAkhir(L);

    return 0;
}