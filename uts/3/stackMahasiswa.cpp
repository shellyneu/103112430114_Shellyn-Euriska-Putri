#include "stackMahasiswa.h"
#include <iostream>

using namespace std;

void createStackMahasiswa(StackMahasiswa &StackMHS){
    StackMHS.top = -1;
}

bool isEmpty(StackMahasiswa StackMHS){
    return StackMHS.top == -1;
}

bool isFull(StackMahasiswa StackMHS){
    return StackMHS.top == MAX - 1;
}

static float hitungNilaiAkhir(const Mahasiswa &m){
    return 0.2 * m.NilaiTugas + 0.4 * m.NilaiUTS + 0.4 * m.NilaiUAS;
}

void push(StackMahasiswa &StackMHS){
    if(isFull(StackMHS)){
        cout << "Stack penuh! Tidak bisa menambahkan mahasiswa." << endl;
        return;
    }
    Mahasiswa m;
    cout << "Masukkan data mahasiswa baru:" << endl;
    cout << "Masukkan Nama: "; cin >> m.Nama;
    cout << "Masukkan NIM: "; cin >> m.NIM;
    cout << "Masukkan Nilai Tugas: "; cin >> m.NilaiTugas;
    cout << "Masukkan Nilai UTS: "; cin >> m.NilaiUTS;
    cout << "Masukkan Nilai UAS: "; cin >> m.NilaiUAS;
    cout << endl;
    m.NilaiAkhir = hitungNilaiAkhir(m);
    StackMHS.top++;
    StackMHS.data[StackMHS.top] = m;
}

void pop(StackMahasiswa &StackMHS){
    if(isEmpty(StackMHS)){
        cout << "Stack kosong!" << endl;
        return;
    }
    Mahasiswa m = StackMHS.data[StackMHS.top];
    cout << "Data yang di-pop: " << m.Nama << " (NIM: " << m.NIM << ")" << endl;
    StackMHS.top--;
}

void update(StackMahasiswa &StackMHS, int posisi){
    if(isEmpty(StackMHS)){
        cout << "Stack kosong!" << endl;
        return;
    }
    int idx = StackMHS.top - (posisi - 1);
    if(idx < 0 || idx > StackMHS.top){
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    Mahasiswa m;
    cout << "Update data pada posisi " << posisi << endl;
    cout << "Masukkan Nama: "; cin >> m.Nama;
    cout << "Masukkan NIM: "; cin >> m.NIM;
    cout << "Masukkan Nilai Tugas: "; cin >> m.NilaiTugas;
    cout << "Masukkan Nilai UTS: "; cin >> m.NilaiUTS;
    cout << "Masukkan Nilai UAS: "; cin >> m.NilaiUAS;
    cin.ignore();
    m.NilaiAkhir = hitungNilaiAkhir(m);
    StackMHS.data[idx] = m;
}

void view(StackMahasiswa StackMHS){
    if(isEmpty(StackMHS)){
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "[TOP]" << endl;
    for(int i = StackMHS.top; i >= 0; i--){
        int no = StackMHS.top - i + 1;
        cout << "No. " << no << " Nama: " << StackMHS.data[i].Nama << " | NIM: " << StackMHS.data[i].NIM
            << " | NilaiAkhir: " << StackMHS.data[i].NilaiAkhir << endl;
    }
}

void searchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax){
    if(isEmpty(StackMHS)){
        cout << "Stack kosong." << endl;
        return;
    }
    bool found = false;
    for(int i = StackMHS.top; i >= 0; i--){
        if(StackMHS.data[i].NilaiAkhir >= NilaiAkhirMin && StackMHS.data[i].NilaiAkhir <= NilaiAkhirMax){
            int no = StackMHS.top - i + 1;
            if(!found){
                cout << "Data mahasiswa dengan NilaiAkhir in [" << NilaiAkhirMin << ", " << NilaiAkhirMax << "]:" << endl;
            }
            found = true;
            cout << "1. " << no << "Nama: " << StackMHS.data[i].Nama << " (NIM: " << StackMHS.data[i].NIM << ") -> " << StackMHS.data[i].NilaiAkhir << endl;
        }
    }
    if(!found) cout << "Tidak ada mahasiswa di range itu." << endl;
}

void maxNilaiAkhir(StackMahasiswa s){
    if(isEmpty(s)){
        cout << "Stack kosong." << endl;
        return;
    }
    int bestIdx = s.top;
    for(int i = s.top-1; i >= 0; i--){
        if(s.data[i].NilaiAkhir > s.data[bestIdx].NilaiAkhir) bestIdx = i;
    }
    cout << "Nilai Akhir terbesar: " << s.data[bestIdx].NilaiAkhir << "(" << s.data[bestIdx].Nama << ")" << endl;
}
