#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //perulangan while (increment)
    int i = 0;
    while (i <= angka1) {
        cout << i << " - ";
        i++;
    }
    
    cout << endl;

    //perulangan do while (decrement)
    int j = angka2;
    do {
        cout << j << " - ";
        j--;
    } while (j >= 0);
    
    return 0;
}