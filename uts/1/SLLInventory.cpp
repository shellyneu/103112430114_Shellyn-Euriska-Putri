#include "SLLInventory.h"
#include <iostream>
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
}

address alokasi(Product P) { 
    address nodeBaru = new node;
    cout << "Masukkan data produk baru:" << endl;
    cout << "Masukkan nama: " << P.Nama << endl;
    nodeBaru->info.Nama = P.Nama;
    cout << "Masukkan SKU: " << P.SKU << endl;
    nodeBaru->info.SKU = P.SKU;
    cout << "Masukkan jumlah: " << P.Jumlah << endl;
    nodeBaru->info.Jumlah = P.Jumlah;
    cout << "Masukkan harga satuan: " << P.HargaSatuan << endl;
    nodeBaru->info.HargaSatuan = P.HargaSatuan;
    cout << "Masukkan diskon persen: " << P.DiskonPersen << endl;
    nodeBaru->info.DiskonPersen = P.DiskonPersen;
    cout << endl;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &addr) {
    addr->next = Nil;
    delete addr;
}

void insertFirst(List &L, Product P) {
    address nodeBaru = alokasi(P);
    nodeBaru->next = L.first; 
    L.first = nodeBaru;
}

void insertAfter(List &List, address Q, Product P) {
    address nodeBaru = alokasi(P);
    if (Q != Nil) {
        nodeBaru->next = Q->next;
        Q->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(List &L, Product P) {
    address nodeBaru = alokasi(P);
    if (isEmpty(L)) {
        L.first = nodeBaru;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void deleteFirst(List &L, Product &P){
    address nodeHapus;
    if (isEmpty(L) == false) {
        nodeHapus = L.first;
        P = nodeHapus->info;
        L.first = L.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void deleteLast(List &L, Product &P){
    address nodeHapus, nodePrev;
    if(isEmpty(L) == false){
        nodeHapus = L.first;
        if(nodeHapus->next == Nil){
            P = nodeHapus->info;
            L.first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            P = nodeHapus->info;
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void deleteAfter(List &L, address Q, Product &P){
    address nodeHapus;
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (Q != Nil && Q->next != Nil) { 
            nodeHapus = Q->next;
            P = nodeHapus->info;
            Q->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void updateAtPosition(List L, int posisi){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int count = 1;
        while (nodeBantu != Nil && count < posisi) {
            nodeBantu = nodeBantu->next;
            count++;
        }
        if (nodeBantu != Nil){
            cout << "Masukkan update data produk pada posisi " << posisi << " : " << endl;
            cout << "Nama: ";
            cin >> nodeBantu->info.Nama;
            cout << "SKU: ";
            cin >> nodeBantu->info.SKU;
            cout << "Jumlah: ";
            cin >> nodeBantu->info.Jumlah;
            cout << "Harga Satuan: ";
            cin >> nodeBantu->info.HargaSatuan;
            cout << "Diskon Persen: ";
            cin >> nodeBantu->info.DiskonPersen;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 1;
        while (nodeBantu != Nil) { 
            cout << "Produk ke-" << posisi << ":" << endl;
            cout << "Nama: " << nodeBantu->info.Nama << endl;
            cout << "SKU: " << nodeBantu->info.SKU << endl;
            cout << "Jumlah: " << nodeBantu->info.Jumlah << endl;
            cout << "Harga Satuan: " << nodeBantu->info.HargaSatuan << endl;
            cout << "Diskon Persen: " << nodeBantu->info.DiskonPersen << endl;
            cout << "-------------------------------------------" << endl;
            nodeBantu = nodeBantu->next;
            posisi++;
        }
    }
}

void SearchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Produk dengan Harga Akhir Antara " << minPrice << " dan " << maxPrice << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float hargaAkhir = nodeBantu->info.HargaSatuan * (1 - nodeBantu->info.DiskonPersen / 100);
            if(hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
                cout << "Produk ke-" << posisi << ":" << endl;
                cout << "Nama: " << nodeBantu->info.Nama << endl;
                cout << "SKU: " << nodeBantu->info.SKU << endl;
                cout << "Jumlah: " << nodeBantu->info.Jumlah << endl;
                cout << "Harga Satuan: " << nodeBantu->info.HargaSatuan << endl;
                cout << "Diskon Persen: " << nodeBantu->info.DiskonPersen << endl;
                cout << "Harga Akhir: " << hargaAkhir << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada produk dalam rentang harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

//Bagian B
void MaxHargaAkhir(List L) {
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        float maxHargaAkhir = 0.0;
        while (nodeBantu != Nil) {
            float hargaAkhir = nodeBantu->info.HargaSatuan * (1 - nodeBantu->info.DiskonPersen / 100);
            if(hargaAkhir > maxHargaAkhir) {
                maxHargaAkhir = hargaAkhir;
            }
            nodeBantu = nodeBantu->next;
        }
        cout << "--- Produk dengan Harga Akhir Tertinggi: " << maxHargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        nodeBantu = L.first;
        int posisi = 0;
        while (nodeBantu != Nil) {
            posisi++;
            float hargaAkhir = nodeBantu->info.HargaSatuan * (1 - nodeBantu->info.DiskonPersen / 100);
            if(hargaAkhir == maxHargaAkhir) {
                cout << "Produk ke-" << posisi << ":" << endl;
                cout << "Nama: " << nodeBantu->info.Nama << endl;
                cout << "SKU: " << nodeBantu->info.SKU << endl;
                cout << "Jumlah: " << nodeBantu->info.Jumlah << endl;
                cout << "Harga Satuan: " << nodeBantu->info.HargaSatuan << endl;
                cout << "Diskon Persen: " << nodeBantu->info.DiskonPersen << endl;
                cout << "Harga Akhir: " << hargaAkhir << endl;
                cout << "-------------------------------------------" << endl;
            }
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}