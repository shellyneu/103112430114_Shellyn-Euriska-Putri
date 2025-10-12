#include<iostream>
using namespace std;

void tampil(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int x, int y) {
    int temp = arr1[x][y];
    arr1[x][y] = arr2[x][y];
    arr2[x][y] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr1[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int arr2[3][3] = {{10,11,12}, {13,14,15}, {16,17,18}};

    int x = 10, y = 20;
    int *ptr1 = &x, *ptr2 = &y;
    
    cout << "Array 1:\n"; tampil(arr1);
    cout << "Array 2:\n"; tampil(arr2);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl;
    
    tukarArray(arr1, arr2, 1, 1);
    cout << "\nSetelah ditukar:\n";
    cout << "Array 1:\n"; tampil(arr1);
    cout << "Array 2:\n"; tampil(arr2);
    
    tukarPointer(ptr1, ptr2);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl;
    
    return 0;
}