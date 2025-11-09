#include "stack.h"
#include <iostream>
#include <cmath>

using namespace std;

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.top == MAX - 1;
}

void createStack(Stack &s){
    s.top = -1;
}

void push(Stack &s, int angka){
    if(isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " <<  val << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack s){
    if(isEmpty(s)){
        cout << "List kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void balikstack(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    
    int temp[MAX];
    int count = 0;
    
    while(!isEmpty(s)){
        temp[count] = s.data[s.top];
        s.top--;
        count++;
    }
    
    for(int i = 0; i < count; i++){
        s.top++;
        s.data[s.top] = temp[i];
    }
}

void pushAscending(Stack &s, int x){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
        return;
    }
    
    Stack temp;
    createStack(temp);
    
    while(!isEmpty(s) && s.data[s.top] > x){
        temp.top++;
        temp.data[temp.top] = s.data[s.top];
        s.top--;
    }
    
    s.top++;
    s.data[s.top] = x;
    
    while(!isEmpty(temp)){
        s.top++;
        s.data[s.top] = temp.data[temp.top];
        temp.top--;
    }
    
    cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
}

void getInputStream(Stack &s){
    int angka, x, bagi, digit, awal;
    cin >> angka;
    
    x = angka;
    digit = 0;
    while(x > 0){
        digit++;
        x /= 10;
    }
    
    bagi = pow(10, digit - 1);
    
    while(bagi > 0 && !isFull(s)){
        awal = (angka / bagi) % 10;
        push(s, awal);
        bagi /= 10;
    }
}