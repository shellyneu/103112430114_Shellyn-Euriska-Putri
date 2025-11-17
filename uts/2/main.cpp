#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    createList(L);

    Song s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2, 0.0};
    Song s2 = {"Langkahmu", "Delta", 185, 320, 4.8, 0.0};
    Song s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9, 0.0};
    Song update = {"Pelita", "Luna", 200, 260, 4.5, 0.0};
    Song insert = {"Senandung", "Mira", 175, 120, 4.0, 0.0};
    Song update2 = {"Matahari", "Bintang", 190, 140, 4.1, 0.0};

    insertLast(L, s1);
    insertLast(L, s2);
    insertLast(L, s3);

    viewList(L);

    deleteLast(L, s3);

    updateAtPosition(L, 2, update);

    viewList(L);

    address addr = getAddressAt(L, 2);
    insertBefore(L, addr, insert);
    viewList(L);

    addr = getAddressAt(L, 2);
    updateBefore(L, addr, update2);
    viewList(L);

    address addr3 = getAddressAt(L, 3);;
    Song del;
    deleteBefore(L, addr3, del);
    cout << "Dihapus sebelum posisi 3: " << del.Title << endl;
    viewList(L);

    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}
