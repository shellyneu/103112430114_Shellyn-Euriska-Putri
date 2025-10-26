#include <iostream>
#include <string>
using namespace std;

const int MAX = 12;

struct Buku {
    string judul;
    string penulis;
};

struct RakBuku {
    Buku T[MAX];
    int head;
    int tail;
};

void createQueue(RakBuku &Q) {
    Q.head = 0;
    Q.tail = 0;
}

bool isEmpty(RakBuku Q) {
    return (Q.head == 0 && Q.tail == 0);
}

bool isFull(RakBuku Q) {
    return (Q.tail == MAX);
}

void Enqueue(RakBuku &Q, string judul, string penulis) {
    if (isFull(Q)) {
        cout << "Rak penuh!" << endl;
    } else if (isEmpty(Q)) {
        Q.head = 1;
        Q.tail = 1;
        Q.T[Q.tail - 1].judul = judul;
        Q.T[Q.tail - 1].penulis = penulis;
    } else {
        Q.tail++;
        Q.T[Q.tail - 1].judul = judul;
        Q.T[Q.tail - 1].penulis = penulis;
    }
}

void Dequeue(RakBuku &Q, string &judul, string &penulis) {
    if (isEmpty(Q)) {
        cout << "Rak kosong!" << endl;
    } else {
        judul = Q.T[0].judul;
        penulis = Q.T[0].penulis;

        for (int i = 1; i < Q.tail; i++) {
            Q.T[i - 1] = Q.T[i];
        }

        Q.tail--;
        if (Q.tail == 0) Q.head = 0;
    }
}

void tampilRak(RakBuku Q) {
    if (isEmpty(Q)) {
        cout << "Rak kosong." << endl;
    } else {
        cout << endl << "Isi rak buku:" <<  endl;
        for (int i = Q.head - 1; i < Q.tail; i++) {
            cout << (i - Q.head + 2) << ". " << Q.T[i].judul 
            << " - " << Q.T[i].penulis << endl;
        }
    }
}

int main() {
    RakBuku rak;
    createQueue(rak);

    Enqueue(rak, "Dilan", "Pidi Baiq");
    Enqueue(rak, "Persuasion", "Jane Austen");
    Enqueue(rak, "The Alchemist", "Paulo Coelho");
    Enqueue(rak, "Supernova: Kesatria, Putri, & Bintang Jatuh", "Dee Lestari");
    Enqueue(rak, "5cm", "Donny Dhirgantoro");

    tampilRak(rak);

    string judul, penulis;
    Dequeue(rak, judul, penulis);
    cout << "\nJudul buku yang diambil: " << judul << endl 
    << "Penulis: " << penulis << endl;

    tampilRak(rak);

    return 0;
}
