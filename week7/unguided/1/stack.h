#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top; 
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void push(Stack &s, int angka);
void pop(Stack &s);
void printInfo(Stack s);
void balikstack(Stack &s);

#endif