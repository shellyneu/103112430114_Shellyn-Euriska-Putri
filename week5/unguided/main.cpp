#include "ListAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);

    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    printList(List);

    cout << endl;

    SearchNodeByData(List, 20);
    SearchNodeByData(List, 55);
    SearchNodeByAddress(List, nodeA);
    SearchNodeByAddress(List, nodeB);
    SearchNodeByMinValue(List, 40);

    cout << "Total Penjumlahan : " << penjumlahan(List) << endl;
    cout << "Total Pengurangan : " << pengurangan(List) << endl;
    cout << "Total Perkalian : " << perkalian(List) << endl;
    
    return 0;
}