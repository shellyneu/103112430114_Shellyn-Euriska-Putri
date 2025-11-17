#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

struct Paket{
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; // kg
    string Tujuan;
};

struct queueEkspedisi {
    Paket info[MAX];
    int head;
    int tail;
};

void createQueue(queueEkspedisi &Q);
bool isEmptyQueue(queueEkspedisi Q);
bool isFullQueue(queueEkspedisi Q);
void enqueue(queueEkspedisi &Q);
void dequeue(queueEkspedisi &Q);
void viewQueue(queueEkspedisi Q);

// Bagian B
long TotalBiayaPengiriman(queueEkspedisi Q);

#endif
