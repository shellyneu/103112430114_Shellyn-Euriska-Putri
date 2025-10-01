#include <iostream>

using namespace std;

void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for(int i = 0; i < ukuran; i++) {
        cout << arr[i];
        if(i < ukuran - 1) cout << ", ";
    }
    cout << endl;
}

int cariMaksimum(int arr[], int ukuran) {
    int maksimum = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }
    return maksimum;
}

int cariMinimum(int arr[], int ukuran) {
    int minimum = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

void hitungRataRata(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    double rataRata = (double)totalJumlah / ukuran;
    cout << "Nilai rata-rata: " << rataRata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = 10;
    int pilihan;
    
    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                tampilkanArray(arrA, ukuran);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 5);
    
    return 0;
}