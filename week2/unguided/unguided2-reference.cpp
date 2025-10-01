#include <iostream>

using namespace std;

void tukar(int &x, int &y, int &z){
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Value of ref (alias a): " << ref << endl;
    cout << "Address of ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nAfter ref = 50;" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;

    cout << "\nBefore swapping: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    tukar(a, b, c);
    
    cout << "After swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}