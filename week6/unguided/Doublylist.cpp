#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nopol, string warna, int thnBuat) { 
    address nodeBaru = new ElmList;
    nodeBaru->isidata.nopol = nopol;
    nodeBaru->isidata.warna = warna; 
    nodeBaru->isidata.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

bool isNopolExist(List L, string nopol) {
    address p = L.first;
    while(p != Nil) {
        if(p->isidata.nopol == nopol) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void insertLast(List &L, address nodeBaru){
    if(isEmpty(L) == true){
        L.first = L.last = nodeBaru;
    } else {
        nodeBaru->prev = L.last;
        L.last->next = nodeBaru;
        L.last = nodeBaru;
    }
    cout << "Kendaraan dengan nomor polisi " << nodeBaru->isidata.nopol << " berhasil ditambahkan!" << endl;
}

void printList(List L) {
    if (isEmpty(L) == true) {
        cout << "L kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << "Nomor Polisi : " << nodeBantu->isidata.nopol << endl;
            cout << "Warna        : " << nodeBantu->isidata.warna << endl;
            cout << "Tahun        : " << nodeBantu->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// SEARCHING
void findElm(List L, string nopol){
    if(isEmpty(L)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = L.first;
    while(p != Nil){
        if(p->isidata.nopol == nopol){
            cout << "Ditemukan (berdasarkan nomor polisi):" << endl;
            cout << "Nomor Polisi : " << p->isidata.nopol << endl;
            cout << "Warna        : " << p->isidata.warna << endl;
            cout << "Tahun        : " << p->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            return;
        }
        p = p->next;
    }
    cout << "Kendaraan dengan nomor polisi \"" << nopol << "\" tidak ditemukan." << endl;
}

// DELETE
void deleteFirst(List &L){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.first;
    if(L.first == L.last){
        L.first = L.last = Nil;
    } else {
        L.first = pDel->next;
        L.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(List &L){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.last;
    if(L.first == L.last){
        L.first = L.last = Nil;
    } else {
        L.last = pDel->prev;
        L.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(List &L, address Prev){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada kendaraan yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Kendaraan sebelumnya (Prev) tidak valid atau tidak ada kendaraan setelahnya!" << endl;
        return;
    }
    if(Prev->next == L.last){
        deleteLast(L);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus setelah kendaraan bernomor polisi " << Prev->isidata.nopol << "." << endl;
    dealokasi(pDel);
}
