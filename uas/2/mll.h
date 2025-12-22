#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataFilm {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

struct DataGenre {
    string IDGenre;
    string namaGenre;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataFilm isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    DataGenre isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

void createListParent(listInduk &LInduk);
void createListChild(listAnak &LAnak);
NodeParent alokasiNodeParent(string IDGenre, string namaGenre);
NodeChild alokasiNodeChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void dealokasiNodeParent(NodeParent &nodeInduk);
void dealokasiNodeChild(NodeChild &nodeAnak);
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void hapusListChild(listAnak &LAnak);
void searchFilmByRatingRange(listInduk LInduk, float minRating, float maxRating);
void printStrukturMLL(listInduk LInduk);

#endif