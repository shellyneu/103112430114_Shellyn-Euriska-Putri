#include<iostream>
#include<string>
using namespace std;

// Fungsi untuk mencetak indentasi (untuk visualisasi tree)
void printIndent(int level) {
    for(int i = 0; i < level; i++) {
        if(i == level - 1) {
            cout << "|-- ";
        } else {
            cout << "|   ";
        }
    }
}

// Fungsi faktorial dengan visualisasi tree
long int faktorial(long int a, int level = 0){
    // Cetak node saat ini
    printIndent(level);
    cout << "faktorial(" << a << ")";
    
    if(a == 1 || a == 0){
        cout << " = 1 (base case)" << endl;
        return 1;
    } else if (a > 1){
        cout << " = " << a << " * faktorial(" << (a-1) << ")" << endl;
        long int hasil = faktorial(a - 1, level + 1);
        
        // Cetak hasil saat kembali dari rekursi
        printIndent(level);
        cout << "^ return " << a << " * " << hasil << " = " << (a * hasil) << endl;
        
        return a * hasil;
    }
    return 0;
}

int main(){
    long int angka;
    cout << "===== VISUALISASI TREE FAKTORIAL REKURSIF =====" << endl;
    cout << "Masukkan angka faktorial: ";
    cin >> angka;

    if(angka < 0){
        cout << "Faktorial tidak terdefinisi untuk angka negatif." << endl;
    } else {
        cout << "\nProses Rekursi (Tree Structure):\n" << endl;
        long int hasil = faktorial(angka);
        cout << "\n===== HASIL AKHIR =====" << endl;
        cout << angka << "! = " << hasil << endl;
    }

    return 0;
}