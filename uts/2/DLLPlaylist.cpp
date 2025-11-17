#include "DLLPlaylist.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool isEmpty(List L) {
    return (L.head == Nil && L.tail == Nil);
}

void createList(List &L) {
    L.head = Nil;
    L.tail = Nil;
}

address allocate(Song S) {
    address nodeBaru = new ElmList;
    nodeBaru->data = S;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void deallocate(address &node) {
    if(node != Nil) {
        delete node;
        node = Nil;
    }
}

void insertFirst(List &L, Song S){
    address nodeBaru = allocate(S);
    if(isEmpty(L)){
        L.head = L.tail = nodeBaru;
    } else {
        nodeBaru->next = L.head;
        L.head->prev = nodeBaru;
        L.head = nodeBaru;
    }
}

void insertLast(List &L, Song S){
    address nodeBaru = allocate(S);
    if(isEmpty(L)){
        L.head = L.tail = nodeBaru;
    } else {
        nodeBaru->prev = L.tail;
        L.tail->next = nodeBaru;
        L.tail = nodeBaru;
    }
}

void insertAfter(List &L, address Q, Song S){
    if(Q == Nil) return;
    if(Q == L.tail){
        insertLast(L, S);
        return;
    }
    address nodeBaru = allocate(S);
    nodeBaru->next = Q->next;
    nodeBaru->prev = Q;
    Q->next->prev = nodeBaru;
    Q->next = nodeBaru;
}

void insertBefore(List &L, address Q, Song S){
    if(Q == Nil) return;
    if(Q == L.head){
        insertFirst(L, S);
        return;
    }
    address nodeBaru = allocate(S);
    nodeBaru->prev = Q->prev;
    nodeBaru->next = Q;
    Q->prev->next = nodeBaru;
    Q->prev = nodeBaru;
}

void deleteFirst(List &L, Song &S){
    if(isEmpty(L)) return;
    address pDel = L.head;
    S = pDel->data;
    if(L.head == L.tail){
        L.head = L.tail = Nil;
    } else {
        L.head = pDel->next;
        L.head->prev = Nil;
        pDel->next = Nil;
    }
    deallocate(pDel);
}

void deleteLast(List &L, Song &S){
    if(isEmpty(L)) return;
    address pDel = L.tail;
    S = pDel->data;
    if(L.head == L.tail){
        L.head = L.tail = Nil;
    } else {
        L.tail = pDel->prev;
        L.tail->next = Nil;
        pDel->prev = Nil;
    }
    deallocate(pDel);
}

void deleteAfter(List &L, address Q, Song &S){
    if(isEmpty(L) || Q == Nil || Q->next == Nil) return;
    if(Q->next == L.tail){
        deleteLast(L, S);
        return;
    }
    address pDel = Q->next;
    S = pDel->data;
    Q->next = pDel->next;
    pDel->next->prev = Q;
    pDel->next = Nil;
    pDel->prev = Nil;
    deallocate(pDel);
}

void deleteBefore(List &L, address Q, Song &S){
    if(isEmpty(L) || Q == Nil || Q->prev == Nil) return;
    if(Q->prev == L.head){
        deleteFirst(L, S);
        return;
    }
    address pDel = Q->prev;
    S = pDel->data;
    Q->prev = pDel->prev;
    pDel->prev->next = Q;
    pDel->next = Nil;
    pDel->prev = Nil;
    deallocate(pDel);
}

void updateAtPosition(List &L, int posisi, Song S){
    if(isEmpty(L) || posisi <= 0) return;
    address p = L.head;
    int idx = 1;
    while(p != Nil && idx < posisi){
        p = p->next;
        idx++;
    }
    if(p != Nil){
        p->data = S;
    }
}

void updateBefore(List &L, address Q, Song S){
    if(Q == Nil || Q->prev == Nil) return;
    Q->prev->data = S;
}

void viewList(List L){
    if(isEmpty(L)){
        cout << "List kosong." << endl;
        return;
    }
    address p = L.head;
    int idx = 1;
    cout << "Daftar Lagu:" << endl;
    cout << "-------------------------------" << endl;
    while(p != Nil){
        p->data.PopularityScore = 0.8f * p->data.PlayCount + 20.0f * p->data.Rating;
        cout << "Lagu ke-" << idx << ":" << endl;
        cout << " Title       : " << p->data.Title << endl;
        cout << " Artist      : " << p->data.Artist << endl;
        cout << " DurationSec : " << p->data.DurationSec << endl;
        cout << " PlayCount   : " << p->data.PlayCount << endl;
        cout << " Rating      : " << p->data.Rating << endl;
        cout << " Popularity  : " << p->data.PopularityScore << endl;
        cout << "-------------------------------" << endl;
        p = p->next;
        idx++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore){
    if(isEmpty(L)){
        cout << "List kosong." << endl;
        return;
    }
    address p = L.head;
    int idx = 1;
    bool found = false;
    while(p != Nil){
        p->data.PopularityScore = 0.8f * p->data.PlayCount + 20.0f * p->data.Rating;
        if(p->data.PopularityScore >= minScore && p->data.PopularityScore <= maxScore){
            if(!found){
                cout << "Song dengan PopularityScore antara " << minScore << " dan " << maxScore << ":" << endl;
            }
            found = true;
            cout << "\nLagu ke-" << idx << ":" << endl;
            cout << " Title: " << p->data.Title << endl;
            cout << " Artist: " << p->data.Artist << endl;
            cout << " DurationSec: " << p->data.DurationSec << endl;
            cout << " PlayCount: " << p->data.PlayCount << endl;
            cout << " Rating: " << p->data.Rating << endl;
            cout << " PopularityScore: " << p->data.PopularityScore << endl;
        }
        p = p->next;
        idx++;
    }
    if(!found) cout << "Tidak ada lagu di range itu." << endl;
}

address getAddressAt(List &L, int posisi){
    if(posisi <= 0) return Nil;
    address p = L.head;
    int idx = 1;
    while(p != Nil && idx < posisi){
        p = p->next;
        idx++;
    }
    return p;
}