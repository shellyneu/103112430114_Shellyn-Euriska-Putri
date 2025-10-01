#include <iostream>

using namespace std;

void tukar(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Value of a: " << a << endl;
    cout << "Addres of a (&a): " << &a << endl;
    cout << "Value of ref (alias a): " << ref << endl;
    cout << "Addres of ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nAfter ref = 50;" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl;

    return 0;
}