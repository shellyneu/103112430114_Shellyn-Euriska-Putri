#include<iostream>

using namespace std;

struct mahasiswa
{
    string nama;
    float nilai, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Masukkan nilai mahasiswa: ";
    cin >> m.nilai;
    cout << "Masukkan nilai 2 mahasiswa: ";
    cin >> m.nilai2;
};

float rata2(mahasiswa m) {
    return float(m.nilai + m.nilai2)/2;
};

int main() {
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan procedure

    cout << "Rata-rata: " << rata2(mhs); //pemanggilan function

    return 0;
}


