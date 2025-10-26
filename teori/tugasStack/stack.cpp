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
    int Top;
};

void createStack(RakBuku &S) {
    S.Top = 0;
}

bool isEmpty(RakBuku S) {
    return S.Top == 0;
}

bool isFull(RakBuku S) {
    return S.Top == MAX;
}

void Push(RakBuku &S, string judul, string penulis) {
    if (isFull(S)) {
        cout << "Rak penuh!" << endl;
    } else {
        S.Top++;
        S.T[S.Top].judul = judul;
        S.T[S.Top].penulis = penulis;
    }
}

void Pop(RakBuku &S, string &judul, string &penulis) {
    if (isEmpty(S)) {
        cout << "Rak kosong!" << endl;
    } else {
        judul = S.T[S.Top].judul;
        penulis = S.T[S.Top].penulis;
        S.Top--;
    }
}

void Get(RakBuku &S, string judulCari, string &namaPenulis) {
    bool ditemukan = false;

    if (isEmpty(S)) {
        cout << "Rak kosong!" << endl;
        namaPenulis = "";
    } else {
        while (!isEmpty(S) && !ditemukan) {
            if (S.T[S.Top].judul == judulCari) {
                namaPenulis = S.T[S.Top].penulis;
                S.Top--;
                ditemukan = true;
            } else {
                S.Top--;
            }
        }

        if (!ditemukan) {
            cout << "Buku dengan judul '" << judulCari << "' tidak ditemukan." << endl;
            namaPenulis = "";
        }
    }
}

void tampilRak(RakBuku S) {
    if (isEmpty(S)) {
        cout << "Rak kosong." << endl;
    } else {
        cout << "\nIsi rak buku (dari atas ke bawah):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.T[i].judul << " - " << S.T[i].penulis << endl;
        }
    }
}

int main() {
    RakBuku rak;
    createStack(rak);

    Push(rak, "Dilan", "Pidi Baiq");
    Push(rak, "Persuasion", "Jane Austen");
    Push(rak, "The Alchemist", "Paulo Coelho");
    Push(rak, "Supernova: Kesatria, Putri, & Bintang Jatuh", "Dee Lestari");
    Push(rak, "5cm", "Donny Dhirgantoro");

    tampilRak(rak);

    string judul, penulis;
    Pop(rak, judul, penulis);
    cout << "\nJudul buku yang diambil: " << judul << endl 
    << "Penulis: " << penulis << endl;

    tampilRak(rak);

    string cari = "The Alchemist";
    string namaPenulis;
    Get(rak, cari, namaPenulis);
    if (!namaPenulis.empty()) {
        cout << "\nPenulis buku '" << cari << "' yang di get adalah: " 
        << namaPenulis << endl;
    }

    tampilRak(rak);

    return 0;
}
