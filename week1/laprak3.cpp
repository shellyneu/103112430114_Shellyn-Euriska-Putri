#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "input: ";
    cin >> angka;
    
    int i = angka;
    
    cout << "output: " << endl;

    while (i >= 1) {

        int j = 1;
        while (j <= angka - i) {
            cout << "  ";
            j++;
        }
        

        int k = i;
        while (k >= 1) {
            cout << k << " ";
            k--;
        }

        cout << "* ";

        int l = 1;
        while (l <= i) {
            cout << l << " ";
            l++;
        }

        cout << endl;
        i--;
    }

    int m = 1;
    while (m <= angka) {
        cout << "  ";
        m++;
    }
    
    cout << "*" << endl;

    return 0;
}