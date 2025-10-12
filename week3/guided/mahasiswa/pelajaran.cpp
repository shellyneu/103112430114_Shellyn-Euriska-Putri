#include "pelajaran.h"

// Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodePel;
    return p;
}

// Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran: " << pel.namaMapel << endl;
    cout << "Nilai : " << pel.kodeMapel << endl;
}