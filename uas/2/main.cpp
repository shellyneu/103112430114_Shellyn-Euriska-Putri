#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    listInduk L;
    
    cout << "1) createListParent()" << endl;
    createListParent(L);
    cout << "List parent berhasil dibuat!" << endl;
    cout << endl << endl;

    cout << "2) insertFirstParent() & insertLastChild()" << endl;
    cout << endl << endl;
    
    NodeParent G001 = alokasiNodeParent("G001", "Action");
    NodeParent G002 = alokasiNodeParent("G002", "Comedy");
    NodeParent G003 = alokasiNodeParent("G003", "Horror");
    NodeParent G004 = alokasiNodeParent("G004", "Romance");
    
    insertFirstParent(L, G004);
    insertFirstParent(L, G003);
    insertFirstParent(L, G002);
    insertFirstParent(L, G001);
    
    NodeChild FA001 = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(G001->L_Anak, FA001);
    
    NodeChild FC001 = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    NodeChild FC002 = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(G002->L_Anak, FC001);
    insertLastChild(G002->L_Anak, FC002);
    
    NodeChild FH001 = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(G003->L_Anak, FH001);
    
    NodeChild FR001 = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    NodeChild FR002 = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(G004->L_Anak, FR001);
    insertLastChild(G004->L_Anak, FR002);
    
    cout << "3) printStrukturMLL()" << endl;
    printStrukturMLL(L);
    cout << endl << endl;
    
    cout << "4) searchFilmByRatingRange() -> 8.0 - 8.5" << endl;
    searchFilmByRatingRange(L, 8.0, 8.5);
    cout << endl << endl;
    
    cout << "5) deleteAfterParent()" << endl;
    deleteAfterParent(L, G001);
    cout << "Node parent G002 (Comedy) beserta list child-nya berhasil dihapus!" << endl;
    cout << endl << endl;
    
    cout << "6) printStrukturMLL()" << endl;
    printStrukturMLL(L);
    
    return 0;
}