#include "singlylist.h"

#include<iostream>
using namespace std;

int main(){
    linkedList L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    delFirst(L);
    delLast(L);
    delAfter(L, P5, P4);

    printInfo(L);
    cout << endl << "Jumlah node : " << nbList(L) << endl << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L);

    return 0;
}