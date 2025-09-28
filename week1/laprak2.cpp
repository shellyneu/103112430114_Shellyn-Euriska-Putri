#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << ": ";
    if (angka < 0 || angka > 100) {
        cout << "Angka harus 1-100" << endl;
    } else {
        vector<string> satuan = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
        string hasil;

        if (angka < 12) {
            hasil = satuan[angka];
        } else if (angka < 20) {
            hasil = satuan[angka % 10] + " belas";
        } else if (angka < 100) {
            int puluhan = angka / 10;
            int sisa = angka % 10;
            if (sisa == 0) {
                hasil = satuan[puluhan] + " puluh";
            } else {
                hasil = satuan[puluhan] + " puluh " + satuan[sisa];
            }
        } else {
            hasil = "seratus";
        }
        cout << hasil << endl;
    }

    return 0;
}
