#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    List L;
    createList(L);

    infoType dataKendaraan;
    string nopol, warna, cariNopol, hapusNopol;
    int thnBuat;
    int count = 0;
    
    while(count < 3) {
        cout << "\nKendaraan ke-" << (count + 1) << endl;
        cout << "Masukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;
        cin.ignore();
        
        if(!isNopolExist(L, nopol)) {
            address nodeBaru = alokasi(nopol, warna, thnBuat);
            insertLast(L, nodeBaru);
            count++;
        } else {
            cout << "Nomor polisi " << nopol << " sudah terdaftar!" << endl;
        }
    }
    
    cout << "\n=== DATA LIST ===" << endl;
    printList(L);

    cout << "\nMasukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    findElm(L, cariNopol);

    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    if(!isEmpty(L)) {
        address p = L.first;
        
        if(p->isidata.nopol == hapusNopol) {
            deleteFirst(L);
        } else if(L.last->isidata.nopol == hapusNopol) {
            deleteLast(L);
        } else {
            while(p != Nil && p->next != Nil) {
                if(p->next->isidata.nopol == hapusNopol) {
                    deleteAfter(L, p);
                    break;
                }
                p = p->next;
            }
        }
    }
    
    cout << "\n=== DATA LIST ===" << endl;
    printList(L);

    return 0;
}