#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
    float PopularityScore;
};

typedef struct ElmList *address;

struct ElmList{
    Song data;
    address next;
    address prev;
};

struct List{
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address &P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi, Song S);
void updateBefore(List &L, address Q, Song S);

void viewList(List L); 
void searchByPopularityRange(List L, float minScore, float maxScore);

address getAddressAt(List &L, int posisi);

#endif