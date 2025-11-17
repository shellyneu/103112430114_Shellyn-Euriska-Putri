#include "queuePengiriman.h"
#include <iostream>

using namespace std;

bool isEmptyQueue(queueEkspedisi Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queueEkspedisi Q){
    return ((Q.tail + 1) % MAX == Q.head);
}

void createQueue(queueEkspedisi &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queueEkspedisi &Q){
    if(isFullQueue(Q)){
        cout << "Queue is full!" << endl;
    } else {
        Paket x;
        cin.ignore();
        cout << "Masukkan KodeResi: "; getline(cin, x.KodeResi);
        cout << "NamaPengirim: "; getline(cin, x.NamaPengirim);
        cout << "BeratBarang (kg): "; cin >> x.BeratBarang;
        cin.ignore();
        cout << "Tujuan: "; getline(cin, x.Tujuan);
        
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
        cout << "Paket masuk ke antrian." << endl;
    }
}

void dequeue(queueEkspedisi &Q){
    if (isEmptyQueue(Q)){
        cout << "Empty queue" << endl;
    } else {
        Paket x = Q.info[Q.head];
        cout << "Paket dengan KodeResi " << x.KodeResi << " dihapus dari antrian." << endl;
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void viewQueue(queueEkspedisi Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << "  : empty queue" << endl;
    } else {
        int i = Q.head;
        cout << Q.head << " - " << Q.tail << "    :" << endl;
        while(true){
            Paket p = Q.info[i];
            cout << "KodeResi: " << p.KodeResi << endl;
            cout << "NamaPengirim: " << p.NamaPengirim << endl;
            cout << "BeratBarang: " << p.BeratBarang << endl;
            cout << "Tujuan: " << p.Tujuan << endl;
            cout << "---------------------" << endl;
            if(i == Q.tail) break;
            i = (i + 1) % MAX;
        }
    }
}

long TotalBiayaPengiriman(queueEkspedisi Q){
    if(isEmptyQueue(Q)) return 0;
    long total = 0;
    int i = Q.head;
    while(true){
        total += (long)Q.info[i].BeratBarang * 8250L;
        if(i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    return total;
}