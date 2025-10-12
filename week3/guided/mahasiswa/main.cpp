#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodePel);

    tampil_pelajaran(pel);

    return 0;
}