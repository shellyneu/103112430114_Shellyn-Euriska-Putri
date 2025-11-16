#include "queue.h"
#include <iostream>

using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return ((Q.tail + 1) % MAX == Q.head);
}

void createQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue is full!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Empty queue" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
        return x;
    }
}

void printInfo(queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << "  : empty queue" << endl;
    } else {
        int i = Q.head;
        cout << Q.head << " - " << Q.tail << "    : ";
        while(true){
            cout << Q.info[i] << " ";
            if( i == Q.tail){
                break;
            }
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}