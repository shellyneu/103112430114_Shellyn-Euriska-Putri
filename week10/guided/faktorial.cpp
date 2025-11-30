#include<iostream>
using namespace std;

long int faktorial(long int a){
    if(a == 1 || a == 0){
        return 1;
    } else if (a > 1){
        return a * faktorial(a - 1);
    }
    return 0;
}

int main(){
    long int angka;
    cout << "Masukkan angka faktorial: ";
    cin >> angka;

    if(angka < 0){
        cout << "Faktorial tidak terdefinisi untuk angka negatif." << endl;
    } else {
        long int hasil = faktorial(angka);
        cout << angka << "! = " << hasil << endl;
    }

    return 0;
}