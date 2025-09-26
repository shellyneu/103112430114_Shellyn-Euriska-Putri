#include <iostream>

using namespace std;

int main() {
    float angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //penjumlahan
    cout << "penjumlahan: " << angka1 << " + " << angka2 << " = " << angka1 + angka2 << endl;
    //pengurangan
    cout << "pengurangan: " << angka1 << " - " << angka2 << " = " << angka1 - angka2 << endl;
    //perkalian 
    cout << "perkalian: " << angka1 << " * " << angka2 << " = " << angka1 * angka2 << endl;
    //pembagian
    if ( angka2 != 0 ) {
        cout << "pembagian: " << angka1 << " / " << angka2 << " = " << angka1 / angka2 << endl;
    } else {
        cout << "pembagian: tidak terdefinisi karena pembagi 0" << endl;
    }

    return 0;
}
