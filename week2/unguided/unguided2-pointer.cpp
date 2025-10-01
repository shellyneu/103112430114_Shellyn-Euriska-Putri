#include <iostream>

using namespace std;

void tukar(int *x, int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    cout << "\nBefore swapping: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    tukar(&a, &b, &c);
    
    cout << "After swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}