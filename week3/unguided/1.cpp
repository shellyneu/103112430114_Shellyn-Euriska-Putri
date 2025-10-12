#include<iostream>
using namespace std;

struct mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

void input(mahasiswa &m) {
    cout << "Nama: "; cin >> m.nama;
    cout << "NIM: "; cin >> m.nim;
    cout << "UTS: "; cin >> m.uts;
    cout << "UAS: "; cin >> m.uas;
    cout << "Tugas: "; cin >> m.tugas;
}

float hitungNilai(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

int main() {
    mahasiswa mhs[10];
    int n;
    
    cout << "Jumlah mahasiswa (max 10): "; cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "\nMahasiswa " << i+1 << ":\n";
        input(mhs[i]);
        mhs[i].nilaiAkhir = hitungNilai(mhs[i]);
    }
    
    cout << "\nHASIL:\n";
    for(int i = 0; i < n; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ") - Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    
    return 0;
}


