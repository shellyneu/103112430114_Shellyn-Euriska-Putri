# <h1 align="center">Laporan Praktikum Modul 10 - MULTI LINKED LIST </h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Struktur data multi linked list merupakan bentuk lanjutan dari linked list yang memungkinkan setiap node memiliki lebih dari satu pointer sehingga dapat terhubung pada struktur list lain yang masih saling berelasi. Berbeda dengan singly maupun doubly linked list yang hanya menghubungkan elemen secara linear satu arah atau dua arah, multi linked list dapat membentuk hubungan bertingkat seperti induk–anak atau kategori–subkategori melalui pointer tambahan di dalam setiap node [2]. Dengan adanya lebih dari satu pointer, satu elemen pada multi linked list tidak hanya menjadi bagian dari satu linear list, tetapi dapat mengelola hubungan ke sejumlah list turunan lain tanpa harus menduplikasi data.

Dalam implementasinya, multi linked list terdiri atas list induk dan list anak, di mana satu elemen pada list induk dapat menunjuk ke satu list anak yang berisi data terkait. Contohnya dapat ditemukan pada kasus pendataan pegawai dan data anaknya: setiap node pegawai menjadi induk dan menyimpan pointer menuju list anak yang berisi data anak pegawai tersebut [2]. Pendekatan ini memungkinkan pengelolaan data relasional secara terstruktur dan efisien karena struktur penyimpanan mengikuti pola hubungan yang nyata, bukan hanya urutan linier seperti pada linked list biasa.

Operasi dasar seperti insert, delete, dan search pada multi linked list tetap mengikuti konsep linked list pada umumnya, namun terdapat aturan tambahan karena keberadaan hubungan antar list. Misalnya, saat melakukan operasi insert anak, sistem harus memastikan elemen induk telah ditemukan terlebih dahulu sebelum node anak dapat ditautkan. Begitu pula pada operasi delete, penghapusan elemen induk harus diikuti oleh penghapusan seluruh node anak yang berada di bawahnya untuk mencegah pointer menggantung (dangling pointer) dan inkonsistensi data [2]. Dengan mekanisme tersebut, multi linked list memberikan fleksibilitas dalam pengelolaan data yang memiliki hierarki, namun tetap mempertahankan keunggulan linked list yaitu efisiensi dalam penambahan dan penghapusan tanpa perlu pergeseran elemen seperti pada array.

Beberapa literatur menyatakan bahwa multi linked list termasuk kategori multiply linked structure, yaitu struktur data dengan dua atau lebih link field dalam satu node yang digunakan untuk menghubungkan data berdasarkan urutan atau relasi berbeda [1]. Model ini banyak digunakan dalam representasi data kompleks seperti relasi banyak-ke-banyak (many-to-many), sistem basis data sederhana, dan struktur informasi hierarkis.

Dengan sifatnya yang fleksibel dan mampu mengelola data bertingkat secara dinamis, multi linked list menjadi salah satu struktur data penting untuk memahami hubungan antar data dalam konteks pemrograman yang lebih kompleks dibandingkan linked list dasar.

## Guided 
### 1.1. mll.h

```h
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

### 1.2. mll.cpp

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        bool ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
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

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

### 1.3 main.cpp

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
Pada program ini, struktur data diimplementasikan menggunakan multi linked list. Struktur utama yang digunakan adalah listInduk sebagai list parent dan listAnak sebagai list child. Relasi antar parent dan child memanfaatkan pointer sehingga satu node induk dapat memiliki banyak node anak yang saling terhubung. Pada bagian awal, file mll.h berisi definisi struktur data, fungsi, serta prosedur yang digunakan dalam pengelolaan node. Struktur nodeParent menyimpan data berupa ID kategori dan nama kategori, serta memiliki pointer next, prev, dan sebuah list anak (L_Anak) yang menampung data makanan di bawah kategori tersebut. Sementara itu, nodeChild menyimpan data makanan seperti ID makanan, nama makanan, dan harga, serta pointer next dan prev sehingga memungkinkan traversal dua arah.

Bagian mll.cpp berfungsi sebagai implementasi dari deklarasi yang ada di header. Program dimulai dengan fungsi createListInduk dan createListAnak yang menginisialisasi list menjadi kosong dengan men-set pointer first dan last ke NULL. Setelah itu, fungsi alokasiNodeParent dan alokasiNodeChild bertugas membuat node baru di memori secara dinamis menggunakan new. Setiap node yang dialokasikan akan diisi dengan data yang diberikan melalui parameter, kemudian pointer-nya diatur agar siap dimasukkan ke dalam struktur list. Terdapat juga prosedur dealokasiNodeParent dan dealokasiNodeChild yang bertujuan untuk menghapus node dari memori ketika sudah tidak digunakan lagi, sehingga mencegah terjadinya memory leak.

Proses pengelolaan struktur data dilakukan melalui berbagai operasi seperti insert, delete, find, dan update. Operasi insert pada parent dan child memiliki beberapa varian, yaitu insert di awal (insertFirstParent/Child), insert di akhir (insertLastParent/Child), dan insert setelah node tertentu (insertAfterParent/Child). Setiap proses insert memperhatikan kondisi list kosong atau tidak, agar pointer dapat disesuaikan dengan benar. Dengan demikian, struktur linked list dapat tetap konsisten dan dapat ditelusuri dua arah.

Operasi delete juga diimplementasikan dengan memperhatikan beberapa kondisi, misalnya apakah list hanya berisi satu node atau lebih dari satu. Ketika parent dihapus, sistem juga harus menghapus seluruh list anak yang berada di bawahnya melalui prosedur hapusListAnak, sehingga tidak ada pointer anak yang terlepas dan menyebabkan struktur rusak. Selain itu, fungsi findParentByID dan findChildByID diimplementasikan untuk melakukan pencarian berdasarkan ID, serta memberikan output posisi node di dalam list jika ditemukan. Sedangkan fungsi update seperti updateDataParentByID dan updateDataChildByID memungkinkan perubahan data tanpa harus menghapus node atau membuat node baru.

Pada bagian main.cpp, struktur multi linked list mulai dimanfaatkan secara nyata melalui simulasi menu restoran. Program menginisialisasi list induk dan kemudian menambahkan beberapa kategori makanan sebagai node parent. Setelah kategori ditambahkan, beberapa menu makanan dimasukkan ke kategori masing-masing sebagai node child. Program juga menampilkan isi list, melakukan operasi pencarian, pembaruan data, serta penghapusan node tertentu untuk menguji seluruh fungsi yang sudah dibuat. Pada akhir program, hasil perubahannya ditampilkan kembali agar terlihat bagaimana kondisi struktur data setelah operasi dilakukan.

## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”. Kemudian, buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”. Lalu, pada file “main.cpp” lakukan operasi INSERT. Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur printMLLStructure().

#### MultiLL.h

```h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot; 
};

typedef struct nodeParent *NodeParent;

typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent alokasiNodeParent(string idGol, string namaGol);
NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void dealokasiNodeParent(NodeParent &NParent);
void dealokasiNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

#endif
```

##### MultiLL.cpp

```C++
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
```

##### main.cpp
```C++
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

    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week11/output/output-unguided1.1.png)
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week11/output/output-unguided1.2.png)
Program ini mengimplementasikan struktur data Multi Linked List yang terdiri dari dua tingkat hubungan node, yaitu parent dan child. Pada konteks yang digunakan dalam program, parent merepresentasikan kelompok atau golongan hewan, sedangkan child merupakan hewan-hewan yang termasuk dalam golongan tersebut. Pendekatan ini menggambarkan suatu sistem data hirarkis, di mana setiap parent dapat memiliki satu atau lebih child yang terhubung secara logis dalam sebuah daftar berantai ganda (doubly linked list).

Struktur listParent menyimpan kumpulan nodeParent, masing-masing berisi informasi golongan hewan seperti ID dan nama kategorinya. Setiap nodeParent juga memiliki atribut berupa listChild, yang merupakan daftar berantai ganda dari kumpulan hewan di bawah golongan tersebut. Sementara itu, nodeChild menyimpan informasi detail mengenai hewan, seperti ID hewan, nama, habitat, keberadaan ekor, hingga bobotnya. Pemisahan data antara parent dan child memperlihatkan pemodelan data yang baik karena menghindari redundansi serta memudahkan proses pengelolaan data berdasarkan kategorinya.

Pada implementasinya, kode telah memfasilitasi berbagai operasi dasar pada struktur data linked list, di antaranya pengecekan kekosongan list, pengalokasian dan dealokasi memori node, serta operasi insert dan delete pada posisi awal maupun akhir baik untuk parent maupun child. Selain itu, program menyediakan fungsi deleteListChild yang memastikan bahwa ketika sebuah parent dihapus, seluruh child yang berada di bawah parent tersebut ikut dihapus untuk mencegah terjadinya kebocoran memori (memory leak). Hal ini menunjukkan bahwa program memperhatikan aspek efisiensi dan keamanan dalam manajemen memori dinamis.

Pada fase eksekusi utama (main function), program membuat beberapa golongan hewan seperti Aves, Mamalia, Pisces, Amfibi, dan Reptil sebagai parent nodes. Selanjutnya, dilakukan penambahan beberapa data hewan pada masing-masing golongan secara bertahap menggunakan operasi insert first dan insert last. Di akhir program, struktur hirarki data ditampilkan melalui fungsi printMLLStructure, sehingga hubungan antara setiap golongan dan hewan-hewannya dapat diamati secara jelas dan terstruktur.


### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.

#### MultiLL.h

```h
void searchHewanByEkor(listParent &LParent, bool tail);
```

##### MultiLL.cpp

```C++
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

```

##### main.cpp
```C++
    // No. 2
    searchHewanByEkor(L, false);
    cout << endl;
```
### Output Unguided :
##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week11/output/output-unguided2.png)
Prosedur searchHewanByEkor dirancang untuk melakukan proses pencarian data hewan berdasarkan atribut ekor yang direpresentasikan dalam bentuk tipe data boolean. Atribut ini menyatakan apakah hewan tersebut memiliki ekor (true) atau tidak (false). Prosedur ini bekerja pada struktur data Multi Linked List, di mana setiap node parent memiliki daftar child yang menyimpan data hewan sesuai kategori golongan hewan.

Tahapan pertama dari prosedur ini adalah melakukan pemeriksaan terhadap list parent menggunakan fungsi isEmptyParent(). Pemeriksaan ini penting untuk menghindari terjadinya kesalahan akses memori ketika list dalam keadaan kosong. Jika list tidak memiliki data parent sama sekali, maka pesan “List parent kosong!” akan ditampilkan dan proses pencarian tidak akan dilanjutkan.

Setelah memastikan bahwa list berisi data, prosedur mulai melakukan penelusuran dari node parent pertama. Variabel bantu seperti nodeBantuParent dan indexParent digunakan untuk menyimpan lokasi node parent yang sedang diproses dan posisinya dalam daftar parent. Selain itu, variabel found juga digunakan sebagai penanda apabila data yang sesuai kriteria berhasil ditemukan selama proses pencarian berlangsung.

Setiap node parent yang diperiksa kemudian mengarah pada penelusuran node child dalam golongan tersebut, menggunakan pointer bantu nodeBantuChild dan variabel indexChild untuk mendeteksi posisi node child dalam daftar. Pada tahap ini, dilakukan pengecekan apakah nilai atribut ekor pada nodeBantuChild->isidata.ekor sesuai dengan nilai parameter tail yang diberikan sebagai input fungsi. Jika ditemukan kecocokan, maka prosedur akan menampilkan informasi lengkap mengenai hewan tersebut, termasuk: Identitas hewan, Nama hewan, Habitat, Status keberadaan ekor, Bobot tubuh. Serta menampilkan informasi node parent yang menaungi hewan tersebut seperti ID golongan dan nama kategorinya. Hal ini memberikan konteks yang jelas mengenai di mana letak data ditemukan dalam struktur Multi Linked List.

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure().

#### MultiLL.h

```h
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
```

##### MultiLL.cpp

```C++
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
```

##### main.cpp
```C++
    // No. 3
    deleteAfterParent(L, G3);
    cout << endl;
    
    printMLLStructure(L);
    cout << endl;
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week11/output/output-unguided3.1.png)
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week11/output/output-unguided3.2.png)
Prosedur deleteAfterParent merupakan salah satu mekanisme penghapusan node pada level parent dalam struktur Multi Linked List. Sesuai namanya, prosedur ini bertugas untuk menghapus satu node parent yang terletak tepat setelah node parent yang diberikan sebagai parameter, yaitu NPrev. Dengan kata lain, fungsi ini menghapus successor node dari node parent yang telah ditentukan posisinya oleh pengguna.

Tahapan pertama dalam prosedur ini adalah melakukan validasi terhadap kondisi list menggunakan fungsi isEmptyParent(). Apabila list induk kosong, maka proses penghapusan tidak dapat dilakukan dan program langsung menampilkan pesan yang menandakan bahwa tidak ada data yang dapat dihapus. Validasi ini penting untuk mencegah terjadinya null reference yang dapat menyebabkan kerusakan pada struktur memori.

Jika list memiliki data, langkah berikutnya adalah memeriksa apakah NPrev merupakan node yang valid dan memiliki node penerus (next). Kondisi ini harus dipenuhi karena penghapusan hanya dapat dilakukan apabila terdapat node yang posisinya berada setelah NPrev. Apabila kondisi tidak terpenuhi, maka sistem memberikan peringatan bahwa data yang dijadikan acuan tidak valid.

Ketika node yang akan dihapus teridentifikasi sebagai nodeHapus = NPrev->next, operasi penghapusan dilakukan melalui proses pemutusan hubungan pointer. Pointer next dari NPrev dihubungkan langsung dengan node yang berada setelah nodeHapus. Jika node tersebut masih ada, maka pointer prev pada node tersebut akan diperbarui untuk menunjuk ke NPrev. Namun, apabila node yang akan dihapus merupakan node terakhir dalam list, maka posisi last dari list harus diperbarui sehingga menunjuk ke NPrev.

Selain pemutusan relasi parent, prosedur ini juga memastikan bahwa seluruh node child yang berada di bawah node parent yang dihapus ikut dibersihkan melalui pemanggilan fungsi deleteListChild. Hal ini bertujuan untuk mencegah terjadinya kebocoran memori (memory leak), karena setiap parent menyimpan daftar anak yang dialokasikan secara dinamis. Setelah semua node child dihapus, langkah terakhir yaitu membebaskan memori nodeHapus dengan memanggil dealokasiNodeParent.

Setelah penghapusan berhasil, sistem akan memberikan informasi berupa pesan keberhasilan yang menyebutkan node parent yang dijadikan acuan.

## Kesimpulan
ChatGPT said:

Keseluruhan kode dan pembahasan mengenai multi linked list pada program ini menunjukkan bagaimana struktur data dapat digunakan untuk merepresentasikan hubungan hierarkis antara satu data induk dengan beberapa data anak secara dinamis. Berdasarkan dasar teori yang telah dijelaskan sebelumnya, multi linked list berbeda dengan linked list biasa karena setiap node induk tidak hanya menyimpan pointer ke node berikutnya dan sebelumnya, tetapi juga memiliki sebuah list anak yang dapat berisi banyak elemen. Konsep ini terbukti efektif ketika digunakan untuk kasus yang membutuhkan relasi satu-ke-banyak, seperti pada contoh program ini yang memodelkan golongan hewan sebagai parent dan daftar hewan sebagai child.

Melalui implementasi program, terlihat bahwa operasi-operasi dasar seperti insert, delete, search, dan traversal dapat diterapkan tidak hanya pada satu tingkat list, tetapi juga pada list di dalam list. Prosedur seperti insertFirstParent, insertLastChild, searchHewanByEkor, hingga deleteAfterParent memperlihatkan bagaimana pointer digunakan untuk memanipulasi node tanpa perlu memindahkan data lain, sehingga proses pengelolaan data menjadi lebih fleksibel dan efisien. Selain itu, adanya pengecekan kondisi list kosong, validasi pointer, dan dealokasi node menunjukkan bahwa pengelolaan memori menjadi hal penting dalam struktur data dinamis agar terhindar dari error maupun memory leak.

Program juga menunjukkan bagaimana operasi pada parent dapat berdampak pada child yang terkait. Contohnya, ketika sebuah node parent dihapus, seluruh data anak yang ada di dalamnya juga harus ikut dihapus agar struktur data tetap konsisten. Hal ini membuktikan bahwa multi linked list tidak hanya sekadar menyimpan data, tetapi juga menjaga hubungan antar data yang saling bergantung.


## Referensi
<br>
[1] Thapa, P. (2014). Study on Linked List. International Journal of Innovative Research in Technology, 1(7), 361–364.
</br>

<br>
[2] Modul Praktikum Struktur Data – Multi Linked List. (n.d.). Universitas Telkom
</br>
