#include "MultiLL.h"
#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    // No. 1
    NodeParent G1 = alokasiNodeParent("G001", "Aves");
    insertFirstParent(L, G1);
    NodeParent G2 = alokasiNodeParent("G002", "Mamalia");
    insertLastParent(L, G2);
    NodeParent G3 = alokasiNodeParent("G003", "Pisces");
    insertLastParent(L, G3);
    NodeParent G4 = alokasiNodeParent("G004", "Amfibi");
    insertLastParent(L, G4);
    NodeParent G5 = alokasiNodeParent("G005", "Reptil");
    insertLastParent(L, G5);
    
    cout << endl;

    NodeChild AV001 = alokasiNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(G1->L_Child, AV001);
    NodeChild AV002 = alokasiNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(G1->L_Child, AV002);
    NodeChild M001 = alokasiNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(G2->L_Child, M001);
    NodeChild M003 = alokasiNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(G2->L_Child, M003);
    NodeChild M002 = alokasiNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(G2->L_Child, M002);
    NodeChild AM001 = alokasiNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(G4->L_Child, AM001);

    cout << endl;

    printMLLStructure(L);
    cout << endl;

    // No. 2
    searchHewanByEkor(L, false);
    cout << endl;

    // No. 3
    deleteAfterParent(L, G3);
    cout << endl;
    
    printMLLStructure(L);
    cout << endl;

    return 0;
}