#include <iostream>
using namespace std;

//Deklarasi List
struct Node {
    float info;
    Node* next;
};

struct List {
    Node* first;
};

//Membuat list kosong
void createList(List &L) {
    L.first = NULL;
}

//Membuat elemen baru
Node* createElement(float X) {
    Node* elm = new Node;
    elm->info = X;
    elm->next = NULL;
    return elm;
}

//Menyisipkan elemen secara ascending
void insertAscending(List &L, Node* elm) {
    if (L.first == NULL) {
        L.first = elm;
    } 
    else if (elm->info < L.first->info) {
        elm->next = L.first;
        L.first = elm;
    } 
    else {
        Node* p = L.first;
        while (p->next != NULL && p->next->info < elm->info) {
            p = p->next;
        }
        elm->next = p->next;
        p->next = elm;
    }
}

void printList(List L) {
    Node* p = L.first;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    List L;
    createList(L);

    insertAscending(L, createElement(10.5));
    insertAscending(L, createElement(12.0));
    insertAscending(L, createElement(20.9));
    insertAscending(L, createElement(25.1));
    insertAscending(L, createElement(15.5)); // insert tambahan untuk cek urutan

    cout << "Isi Linked List (Ascending): ";
    printList(L);

    return 0;
}
