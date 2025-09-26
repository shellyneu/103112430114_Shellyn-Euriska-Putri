#include <iostream>
// #define MAX 5
using namespace std;

int main() {
    const int jumlah = 5;

    struct rapot{
        char nama[jumlah];
        int nilai;
    };
    
    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++ ) {
        cout << "masukkan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa: ";
        cin >> siswa[i].nilai;
    }

    cout << endl;

    int i = 0;
    while (i < jumlah) {
        cout << "nama : " << siswa[i].nama << "\nnilai : " << siswa[i].nilai << endl;
        i++;
    }
    
    return 0;
}