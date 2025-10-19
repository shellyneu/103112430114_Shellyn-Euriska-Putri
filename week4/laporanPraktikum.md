# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Struktur data linked list merupakan salah satu bentuk struktur data dinamis yang banyak digunakan dalam pemrograman untuk mengelola data secara efisien. Tidak seperti array yang memiliki ukuran tetap, linked list dapat menyesuaikan ukuran memorinya secara dinamis selama program berjalan [2]. Pada singly linked list, setiap elemen disebut node yang terdiri dari dua bagian utama, yaitu data dan pointer yang menunjuk ke node berikutnya. Sifatnya yang unidirectional membuat traversal hanya dapat dilakukan dari awal hingga akhir daftar. Konsep ini memungkinkan efisiensi dalam proses penyisipan (insertion) dan penghapusan (deletion) data tanpa perlu menggeser elemen lain sebagaimana terjadi pada struktur array [2]. Dengan demikian, singly linked list menjadi dasar penting dalam pembelajaran struktur data karena memberikan pemahaman praktis tentang pengelolaan memori dan manipulasi pointer secara dinamis.

Beberapa penelitian memperluas konsep dasar singly linked list menjadi bentuk yang lebih efisien. Naidu dan Prasad (2014) memperkenalkan konsep Enhanced Singly Linked List dengan memanfaatkan operasi exclusive-OR (XOR) untuk memungkinkan penelusuran dua arah tanpa perlu menambah memori seperti pada doubly linked list [1]. Pendekatan ini memperlihatkan bagaimana modifikasi kecil dalam pengelolaan pointer dapat memberikan dampak besar terhadap efisiensi memori dan performa sistem, khususnya pada perangkat dengan keterbatasan sumber daya. Konsep serupa juga muncul dalam penelitian pengembangan bahasa pemrograman terarah struktur yang berfokus pada manipulasi data dinamis menggunakan domain-specific language (DSL), yang memperlihatkan bagaimana operasi seperti penyisipan dan penghapusan dapat dilakukan secara otomatis dengan aturan transformasi struktural yang efisien [3]. Dengan demikian, pemahaman mendalam terhadap singly linked list menjadi landasan penting dalam mempelajari struktur data yang lebih kompleks serta penerapannya di dunia nyata.


## Guided 

### 1.1 list.h

```h
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

#endif
```

File header ini mendefinisikan struktur data untuk implementasi singly linked list yang menyimpan data mahasiswa. Pertama, ada include guard (LIST_H) dan macro Nil sebagai NULL, #include <iostream> serta using namespace std. Struct mahasiswa (nama, nim, umur) diberi alias dataMahasiswa, node berisi dataMahasiswa isidata dan pointer next dengan alias address, serta struct linkedList yang menyimpan first (head). Di bagian bawah terdapat deklarasi beberapa prosedur dan fungsi untuk operasi dasar list (isEmpty, createList, alokasi/dealokasi node, printInfo, dan tiga operasi sisip: insertFirst, insertAfter, insertLast).

### 1.2 list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

File ini adalah implementasi C++ untuk menyimpan data mahasiswa (field nama, nim, umur) yang menggunakan definisi tipe dan konstanta dari header "list.h" (linkedList, address, node, Nil). Menyediakan operasi dasar seperti pemeriksaan kekosongan (isEmpty), inisialisasi list (createList), alokasi dan dealokasi node (alokasi, dealokasi), penyisipan di awal, setelah node tertentu, dan di akhir (insertFirst, insertAfter, insertLast), serta pencetakan isi list ke cout (printList). 


### 1.3 main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

File main.cpp ini berfungsi untuk menguji implementasi linked list yang didefinisikan di "list.h". Pertama program membuat sebuah linkedList bernama List, mendeklarasikan beberapa address node (nodeA–nodeE), memanggil createList(List), mengalokasi lima objek dataMahasiswa lewat alokasi(name, NIM, umur), lalu menyusun daftar dengan kombinasi insertFirst, insertLast, dan insertAfter untuk menguji fungsi dan prosedur yang telah dibuat. Setelah itu menampilkan sebuat kalimat dan memanggil printList(List) untuk mencetak isi daftar ke terminal sebelum mengakhiri program dengan return 0.


### 2.1 list.h

```h
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```
File header ini mendefinisikan struktur data untuk implementasi singly linked list  yang menyimpan data mahasiswa. Pertama ada include guard (LIST_H) dan define Nil sebagai NULL, #include <iostream> serta using namespace std. Struct mahasiswa (nama, nim, umur) diberi alias dataMahasiswa, node berisi dataMahasiswa isidata dan pointer next dengan alias address, serta struct linkedList yang menyimpan first (head). Di bagian bawah terdapat deklarasi beberapa prosedur dan fungsi untuk operasi dasar list (isEmpty, createList, alokasi/dealokasi node, printInfo, dan tiga operasi sisip: insertFirst, insertAfter, insertLast). Header ini juga mendeklarasikan operasi penghapusan seperti delFirst untuk menghapus node pertama, delLast untuk menghapus node terakhir, delAfter untuk menghapus node setelah node sebelumnya, nbList yang mengembalikan jumlah elemen dalam list, serta deleteList untuk mengosongkan seluruh list.


### 2.2 list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
        F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
        F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
File ini adalah implementasi C++ untuk menyimpan data mahasiswa (field nama, NIM, umur) yang menggunakan definisi tipe dan konstanta dari header "list.h". Dimulai dari fungsi pembuatan list kosong (createList), pengecekan kekosongan (isEmpty), alokasi/dealokasi node (alokasi, dealokasi), operasi sisip (insertFirst, insertAfter, insertLast), operasi hapus (delFirst, delAfter, delLast), serta untuk menampilkan isi (printList), menghitung jumlah node (nbList) dan menghapus seluruh list (deleteList).


### 2.2 main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
File main.cpp berfungsi untuk menguji implementasi linked list yang sudah dibuat sebelumnya untuk data mahasiswa. Setelah meng-include header "list.h" dan menggunakan namespace std, program membuat list kosong, mengalokasi beberapa node berisi nama, NIM, dan umur menggunakan fungsi alokasi, kemudian memasukkan node ke list dengan kombinasi insertFirst, insertLast, dan insertAfter. Kemudian program menampilkan isi dan jumlah node, lalu melakukan operasi penghapusan (delFirst, delLast, delAfter), menampilkan kembali isi dan jumlah, lalu mengosongkan seluruh list dengan deleteList sebelum keluar dengan return 0.


## Unguided 

### 1. Buatlah ADT Singly linked list yang disimpan ke dalam file header dengan nama file "Singlylist.h". Kemudian buatlah implementasi dari procedure-procedure yang akan digunakan ke dalam file "Singlylist.cpp". Kemudian buat program utama di dalam file "main.cpp".

#### singlylist.h

```h
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct infoType {
    int number;
};

typedef infoType dataNumber; 
typedef struct node *address; 

struct node { 
    dataNumber info;
    address next;
};

struct linkedList { 
    address first;
};


bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(int number);
void dealokasi(address &node);
void printInfo(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

#endif
```

File header ini mendefinisikan struktur data untuk implementasi singly linked list yang menyimpan data mahasiswa. Pertama, ada include guard (LIST_H) dan define Nil sebagai NULL, #include <iostream> serta using namespace std. Struct infoType (number) diberi alias dataNumber, node berisi dataNumber info dan pointer next dengan alias address, serta struct linkedList yang menyimpan first (head). Di bagian bawah terdapat deklarasi beberapa prosedur dan fungsi untuk operasi dasar list (isEmpty, createList, alokasi/dealokasi node, printInfo, dan tiga operasi sisip: insertFirst, insertAfter, insertLast).

##### singlylist.cpp

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(int number) { 
    address nodeBaru = new node; 
    nodeBaru->info.number = number;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printInfo(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->info.number << " ";
            nodeBantu = nodeBantu->next;
        }
    }
}
```

File ini adalah implementasi C++ untuk menyimpan data angka (number) yang menggunakan definisi tipe dan konstanta dari header "singlylist.h" (linkedList, address, node, Nil). Menyediakan operasi dasar seperti pemeriksaan kekosongan (isEmpty), inisialisasi list (createList), alokasi dan dealokasi node (alokasi, dealokasi), penyisipan di awal, setelah node tertentu, dan di akhir (insertFirst, insertAfter, insertLast), serta pencetakan isi list ke cout (printList).


##### main.cpp
```C++
#include "singlylist.h"

#include<iostream>
using namespace std;

int main(){
    linkedList L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

File main.cpp ini berfungsi untuk menguji implementasi linked list yang didefinisikan di "singlylist.h". Pertama program membuat sebuah linkedList bernama L, mendeklarasikan beberapa address node (P1-P5), memanggil createList(L), mengalokasi lima objek data angka lewat alokasi(number), lalu menyusun daftar dengan kombinasi insertFirst untuk menguji fungsi dan prosedur yang telah dibuat. Setelah itu memanggil printList(L) untuk mencetak isi daftar ke terminal sebelum mengakhiri program dengan return 0.


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week4/output/output-unguided1.png)


### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

#### singlylist.h

```h
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct infoType {
    int number;
};

typedef infoType dataNumber; 
typedef struct node *address; 

struct node { 
    dataNumber info;
    address next;
};

struct linkedList { 
    address first;
};


bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(int number);
void dealokasi(address &node);
void printInfo(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

#endif
```

File header ini mendefinisikan struktur data untuk implementasi singly linked list yang menyimpan data mahasiswa. Pertama, ada include guard (LIST_H) dan define Nil sebagai NULL, #include <iostream> serta using namespace std. Struct infoType (number) diberi alias dataNumber, node berisi dataNumber info dan pointer next dengan alias address, serta struct linkedList yang menyimpan first (head). Di bagian bawah terdapat deklarasi beberapa prosedur dan fungsi untuk operasi dasar list (isEmpty, createList, alokasi/dealokasi node, printInfo, dan tiga operasi sisip: insertFirst, insertAfter, insertLast). Header ini juga mendeklarasikan operasi penghapusan seperti delFirst untuk menghapus node pertama, delLast untuk menghapus node terakhir, delAfter untuk menghapus node setelah node sebelumnya, nbList yang mengembalikan jumlah elemen dalam list, serta deleteList untuk mengosongkan seluruh list.


##### singlylist.cpp

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(int number) { 
    address nodeBaru = new node; 
    nodeBaru->info.number = number;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printInfo(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->info.number << " ";
            nodeBantu = nodeBantu->next;
        }
    }
}
```

File ini adalah implementasi C++ untuk menyimpan data angka (number) yang menggunakan definisi tipe dan konstanta dari header "singlylist.h" (linkedList, address, node, Nil). Menyediakan operasi dasar seperti pemeriksaan kekosongan (isEmpty), inisialisasi list (createList), alokasi dan dealokasi node (alokasi, dealokasi), penyisipan di awal, setelah node tertentu, dan di akhir (insertFirst, insertAfter, insertLast), operasi hapus (delFirst, delAfter, delLast), serta untuk menampilkan isi (printList), menghitung jumlah node (nbList) dan menghapus seluruh list (deleteList).


##### main.cpp
```C++
#include "singlylist.h"

#include<iostream>
using namespace std;

int main(){
    linkedList L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

File main.cpp ini berfungsi untuk menguji implementasi linked list yang didefinisikan di "singlylist.h". Pertama program membuat sebuah linkedList bernama L, mendeklarasikan beberapa address node (P1-P5), memanggil createList(L), mengalokasi lima objek data angka lewat alokasi(number), lalu menyusun daftar dengan kombinasi insertFirst untuk menguji fungsi dan prosedur yang telah dibuat. Kemudian program melakukan operasi penghapusan (delFirst, delLast, delAfter), menampilkan kembali isi dan jumlah, lalu mengosongkan seluruh list dengan deleteList sebelum keluar dengan return 0.


### Output Unguided 2 - Reference :

##### Output 1
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week4/output/output-unguided2.png)


## Kesimpulan
Kesimpulannya, praktikum ini telah memperkenalkan dan mengimplementasikan ADT singly linked list melalui pembuatan header dan implementasi (.h/.cpp) serta program pengujinya, mencakup operasi dasar seperti inisialisasi, alokasi/dealokasi, penyisipan (first/after/last), penghapusan (first/after/last), penghitung jumlah node (nbList) dan pengosongan seluruh list (deleteList). Dari hasil uji terlihat fungsi-fungsi bekerja sesuai dengan yang diharapkan oleh soal.


## Referensi
[1] Naidu, D., & Prasad, A. (2014). Implementation of Enhanced Singly Linked List Equipped with DLL Operations: An Approach Towards Enormous Memory Saving. International Journal of Future Computer and Communication, 3(2), 98–101. https://doi.org/10.7763/IJFCC.2014.V3.276
<br>
[2] Kaluti, M. K., Govindaraju, Y., Shashank, A. R., & Harshith, K. S. (2018). Dynamic Implementation of Stack Using Single Linked List. International Research Journal of Engineering and Technology (IRJET), 5(3), 1923–1926. https://www.irjet.net/archives/V5/i3/IRJET-V5I3434.pdf
<br>
[3] Stokke, K. A., Barash, M., & Järvi, J. (2023). A Domain-Specific Language for Structure Manipulation. Journal of Computer Languages, 74, 101175. https://doi.org/10.1016/j.cola.2023.101175