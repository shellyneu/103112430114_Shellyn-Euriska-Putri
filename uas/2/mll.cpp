#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

void createListParent(listInduk &LInduk) {
    LInduk.first = NULL;
    LInduk.last = NULL;
}

void createListChild(listAnak &LAnak) {
    LAnak.first = NULL;
    LAnak.last = NULL;
}

NodeParent alokasiNodeParent(string IDGenre, string namaGenre) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.IDGenre = IDGenre;
    nodeBaruParent->isidata.namaGenre = namaGenre;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListChild(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.IDFilm = IDFilm;
    nodeBaruChild->isidata.judulFilm = judulFilm;
    nodeBaruChild->isidata.durasiFilm = durasiFilm;
    nodeBaruChild->isidata.tahunTayang = tahunTayang;
    nodeBaruChild->isidata.ratingFilm = ratingFilm;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = NULL;
        nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = NULL;
        nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(LInduk.first == NULL) {
        LInduk.first = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(LAnak.first == NULL) {
        LAnak.first = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev) {
    if(nodePrev != NULL && nodePrev->next != NULL) {
        NodeParent nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        if(nodeHapus->next != NULL) {
            nodeHapus->next->prev = nodePrev;
        } else {
            LInduk.last = nodePrev;
        }
        nodeHapus->next = NULL;
        nodeHapus->prev = NULL;
        
        if(nodeHapus->L_Anak.first != NULL) {
            hapusListChild(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
    }
}

void hapusListChild(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = NULL;
    LAnak.last = NULL;
}

void searchFilmByRatingRange(listInduk LInduk, float minRating, float maxRating) {
    if(LInduk.first == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    NodeParent nodeBantuParent = LInduk.first;
    bool found = false;
    int indexParent = 1;
    
    while(nodeBantuParent != NULL) {
        NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
        int indexChild = 1;
        
        while(nodeBantuChild != NULL) {
            if(nodeBantuChild->isidata.ratingFilm >= minRating && 
                nodeBantuChild->isidata.ratingFilm <= maxRating) {
                cout << "Data Film ditemukan pada list child dari node parent " << nodeBantuParent->isidata.namaGenre << " pada posisi ke-" << indexChild << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << nodeBantuChild->isidata.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << indexChild << endl;
                cout << "ID Film : " << nodeBantuChild->isidata.IDFilm << endl;
                cout << "Durasi Film : " << nodeBantuChild->isidata.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << nodeBantuChild->isidata.tahunTayang << endl;
                cout << "Rating Film : " << nodeBantuChild->isidata.ratingFilm << endl;
                cout << "---------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << nodeBantuParent->isidata.IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << indexParent << endl;
                cout << "Nama Genre : " << nodeBantuParent->isidata.namaGenre << endl;
                cout << "=========================================" << endl;
                found = true;
            }
            nodeBantuChild = nodeBantuChild->next;
            indexChild++;
        }
        nodeBantuParent = nodeBantuParent->next;
        indexParent++;
    }
    
    if(!found) {
        cout << "Tidak ada film dengan rating antara " << minRating << " dan " << maxRating << endl;
    }
}

void printStrukturMLL(listInduk LInduk) {
    if(LInduk.first == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    NodeParent nodeBantuParent = LInduk.first;
    int indexParent = 1;
    
    while(nodeBantuParent != NULL) {
        cout << "=== Parent " << indexParent << " ===" << endl;
        cout << "ID Genre : " << nodeBantuParent->isidata.IDGenre << endl;
        cout << "Nama Genre : " << nodeBantuParent->isidata.namaGenre << endl;
        
        NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "  (tidak ada film)" << endl;
        } else {
            int indexChild = 1;
            while(nodeBantuChild != NULL) {
                cout << "  - Child " << indexChild << " :" << endl;
                cout << "      ID Film : " << nodeBantuChild->isidata.IDFilm << endl;
                cout << "      Judul Film : " << nodeBantuChild->isidata.judulFilm << endl;
                cout << "      Durasi Film : " << nodeBantuChild->isidata.durasiFilm << " menit" << endl;
                cout << "      Tahun Tayang : " << nodeBantuChild->isidata.tahunTayang << endl;
                cout << "      Rating Film : " << nodeBantuChild->isidata.ratingFilm << endl;
                nodeBantuChild = nodeBantuChild->next;
                indexChild++;
            }
        }
        cout << "---------------------------" << endl;
        nodeBantuParent = nodeBantuParent->next;
        indexParent++;
    }
}