#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    //increment
    for (int i = 0; i < angka1; i++) {
        cout << i << " - ";
    }
    
    cout << endl;
    
    //decrement
    for (int i = angka1; i >= 0; i--) {
        cout << i << " - ";
    }
    
    return 0;
}