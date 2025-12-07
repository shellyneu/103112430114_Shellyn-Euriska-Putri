#include "MultiLL.h"
#include <iostream>
#include <string>

using namespace std;

bool isEmptyParent(listParent LParent){
    if(LParent.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyChild(listChild LChild){
    if(LChild.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = NULL;
}

NodeParent alokasiNodeParent(string idGol, string namaGol) {
    NodeParent newNParent = new nodeParent;
    newNParent->isidata.idGolongan = idGol;
    newNParent->isidata.namaGolongan = namaGol;
    newNParent->next = NULL;
    newNParent->prev = NULL;
    createListChild(newNParent->L_Child);
    return newNParent;
}

NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNChild = new nodeChild;
    newNChild->isidata.idHewan = idHwn;
    newNChild->isidata.namaHewan = namaHwn;
    newNChild->isidata.habitat = habitat;
    newNChild->isidata.ekor = tail;
    newNChild->isidata.bobot = weight;
    newNChild->next = NULL;
    newNChild->prev = NULL;
    return newNChild;
}

void dealokasiNodeChild(NodeChild &NChild) {
    if(NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void dealokasiNodeParent(NodeParent &NParent) {
    if(NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
    cout << "Node parent "<< newNParent->isidata.namaGolongan << " berhasil ditambahkan kedalam urutan pertama di list Parent!" << endl;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
    cout << "Node parent "<< newNParent->isidata.namaGolongan << " berhasil ditambahkan kedalam urutan terakhir di list Parent!" << endl;
}

void deleteFirstParent(listParent &LParent){
    if(isEmptyParent(LParent) == true){
        cout << "List Parent kosong!" << endl;
    } else {
        NodeParent nodeHapus = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Child.first != NULL){
            deleteListChild(nodeHapus->L_Child);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list parent berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(isEmptyParent(LParent) == true){
        cout << "List parent kosong!" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL){
            NodeParent nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = NPrev;
            } else {
                LParent.last = NPrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Child.first != NULL){
                deleteListChild(nodeHapus->L_Child);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << NPrev->isidata.namaGolongan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
    cout << "Node child "<< newNChild->isidata.namaHewan << " berhasil ditambahkan kedalam urutan pertama di list Child!" << endl;
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
    cout << "Node child "<< newNChild->isidata.namaHewan << " berhasil ditambahkan kedalam urutan terakhir di list Child!" << endl;
}

void deleteFirstChild(listChild &LChild){
    if(isEmptyChild(LChild) == true){
        cout << "List child kosong!" << endl;
    } else {
        NodeChild nodeHapus = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list child berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(isEmptyChild(LChild) == true){
        cout << "List child kosong!" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL){
            NodeChild nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = NPrev;
            } else {
                LChild.last = NPrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << NPrev->isidata.namaHewan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void printMLLStructure(listParent &LParent) {
    if(isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Golongan : " << nodeBantuParent->isidata.idGolongan << endl;
            cout << "Nama Golongan : " << nodeBantuParent->isidata.namaGolongan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Hewan : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "      Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "      Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "      Ekor : " << (nodeBantuChild->isidata.ekor ? "TRUE" : "FALSE") << endl;
                    cout << "      Bobot : " << nodeBantuChild->isidata.bobot << " kg" << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

// No. 2
void searchHewanByEkor(listParent &LParent, bool tail) {
    if(isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        bool found = false;
        
        while(nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            int indexChild = 1;
            
            while(nodeBantuChild != NULL) {
                if(nodeBantuChild->isidata.ekor == tail) {
                    found = true;
                    cout << "Data ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaGolongan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "Ekor : " << (nodeBantuChild->isidata.ekor ? "TRUE" : "FALSE") << endl;
                    cout << "Bobot : " << nodeBantuChild->isidata.bobot << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama golongan : " << nodeBantuParent->isidata.namaGolongan << endl;
                    cout << "---------------------------" << endl;
                }
                nodeBantuChild = nodeBantuChild->next;
                indexChild++;
            }
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
        
        if(!found) {
            cout << "Tidak ada hewan dengan ekor " << (tail ? "TRUE" : "FALSE") << endl;
        }
    }
}

