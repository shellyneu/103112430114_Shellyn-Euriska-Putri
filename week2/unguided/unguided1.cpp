#include <iostream>

using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrB[3][3] = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };

    int arrC[3][3] = {0}; // untuk penjumlahan
    int arrD[3][3] = {0}; // untuk pengurangan
    int arrE[3][3] = {0}; // untuk perkalian

    //penjumlahan matriks 3x3
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);

    //pengurangan matriks 3x3
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan: " << endl;
    tampilkanHasil(arrD);

    //perkalian matriks 3x3
    for(int i = 0; i < 3; i++){                         //perulangan baris
        for (int j = 0; j < 3; j++){                    //perulangan kolom
            for (int k = 0; k < 3; k++){                //perulangan perkalian
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrE);

    return 0;
}