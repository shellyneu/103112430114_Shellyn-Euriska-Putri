# <h1 align="center">Laporan Praktikum Modul 5 - Doubly Linked List </h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Struktur data doubly linked list (DLL) merupakan bentuk lanjutan dari struktur data singly linked list (SLL) yang memungkinkan konektivitas dua arah antar-node, di mana setiap elemen memiliki dua pointer, yaitu prev yang menunjuk ke node sebelumnya dan next yang menunjuk ke node berikutnya. Dengan karakteristik tersebut, DLL memberikan fleksibilitas yang lebih tinggi dalam melakukan operasi dasar seperti penyisipan (insertion), pencarian (searching), dan penghapusan (deletion) dibandingkan dengan SLL yang hanya memiliki satu arah penelusuran [1]. Keunggulan utama dari DLL terletak pada kemampuannya untuk melakukan navigasi bolak-balik tanpa harus menelusuri daftar dari awal, sehingga operasi manipulasi data dapat dilakukan dengan efisien terutama dalam konteks sistem yang membutuhkan akses acak terhadap elemen data [2].

Dalam konteks operasi insertion, DLL memungkinkan penambahan simpul baru di berbagai posisi — baik di awal, tengah, maupun akhir daftar. Setiap proses penyisipan hanya memerlukan penyesuaian pointer pada node terkait tanpa perlu melakukan pergeseran data sebagaimana pada struktur array. Menurut penelitian Wijoyo et al. (2024), algoritma penyisipan dalam DLL memiliki kompleksitas waktu rata-rata O(1), yang berarti operasi dapat dilakukan dalam waktu konstan terlepas dari jumlah node dalam daftar [1]. Fleksibilitas ini membuat DLL banyak digunakan dalam sistem yang memerlukan penambahan data dinamis, seperti manajemen memori, sistem antrian dua arah, serta struktur penyimpanan cache. Implementasi praktis dari DLL dalam berbagai bahasa pemrograman seperti C++, Java, dan Python juga telah mendukung efisiensi manipulasi data melalui pustaka bawaan yang mengoptimalkan manajemen pointer secara otomatis [1].

Operasi searching pada DLL dilakukan dengan menelusuri daftar baik dari arah depan (head) maupun belakang (tail), memanfaatkan dua arah navigasi yang dimilikinya. Pendekatan ini memberikan kecepatan pencarian yang lebih efisien terutama ketika posisi data yang dicari berada di bagian akhir daftar, karena traversal dapat dilakukan dari sisi yang lebih dekat [2]. Selain pencarian berdasarkan nilai data, DLL juga memungkinkan pencarian berdasarkan alamat memori atau relasi antar-node, yang sangat berguna dalam sistem yang memanfaatkan alokasi memori dinamis. Penelitian yang dilakukan oleh Reddy dan Ramakrishnan (2007) menunjukkan bahwa kinerja pencarian pada DLL lebih baik dibandingkan dengan SLL ketika digunakan dalam implementasi struktur seperti symbol table, karena kemampuannya untuk menelusuri data dua arah dan memperkecil kebutuhan traversal linear penuh [1].

Adapun operasi deletion dalam DLL menjadi salah satu keunggulan utamanya dibandingkan dengan SLL. Proses penghapusan node tidak memerlukan traversal dari awal daftar karena setiap node memiliki akses langsung ke node sebelumnya. Dengan demikian, penghapusan node baik di awal, tengah, maupun akhir daftar dapat dilakukan hanya dengan memperbarui pointer next dan prev dari node di sekitar node yang dihapus. Berdasarkan hasil penelitian Wijoyo et al. (2024), efisiensi operasi deletion pada DLL juga memiliki kompleksitas waktu rata-rata O(1), karena tidak membutuhkan pergeseran data maupun penelusuran penuh [1]. Pendekatan ini menjadikan DLL lebih unggul dalam aplikasi yang memerlukan penghapusan dan pembaruan data secara real-time, seperti sistem basis data, buffer editor teks, serta sistem operasi yang memanfaatkan struktur data ini dalam pengelolaan proses dan memori [2].

Dengan demikian, dapat disimpulkan bahwa doubly linked list memberikan keseimbangan antara fleksibilitas dan efisiensi dalam pengelolaan data dinamis. Struktur ini memungkinkan operasi penyisipan, pencarian, dan penghapusan dilakukan dengan waktu yang relatif konstan, serta menyediakan kemudahan dalam traversal dua arah yang tidak dimiliki oleh SLL. Walaupun penggunaan memori pada DLL lebih besar akibat adanya dua pointer pada setiap node, peningkatan kinerja yang diberikan dalam hal efisiensi akses dan manipulasi data membuatnya menjadi pilihan optimal untuk berbagai aplikasi yang menuntut efisiensi tinggi dan manipulasi data yang kompleks.

## Guided 

### 1.1 listMakanan.h

```h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### 1.2 listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### 1.3 main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

Program yang terdiri dari tiga file, yakni listMakanan.h, listMakanan.cpp, dan main.cpp, merupakan implementasi dari struktur data Doubly Linked List (DLL) dengan fokus pada pengelolaan data bertipe makanan. Implementasi ini dirancang untuk memodelkan data makanan secara dinamis, dengan setiap simpul (node) merepresentasikan satu entitas makanan yang memiliki atribut nama, jenis, harga, dan rating. Melalui pendekatan ini, program dapat melakukan berbagai operasi manipulasi data seperti penambahan (insertion), pembaruan (update), dan penelusuran (traversal) secara efisien, sekaligus mencerminkan konsep fundamental dari struktur data berorientasi pointer dua arah.

File listMakanan.h berfungsi sebagai header file yang mendefinisikan struktur utama dan deklarasi fungsi yang digunakan dalam program. Di dalamnya terdapat deklarasi struktur makanan yang menjadi bentuk dasar dari setiap data yang disimpan. Struct ini berisi empat atribut utama, yakni nama, jenis, harga, dan rating. Selanjutnya, struct node merepresentasikan simpul dari Doubly Linked List yang terdiri dari dua pointer, next dan prev, yang masing-masing menunjuk ke simpul berikutnya dan simpul sebelumnya. Struktur linkedlist digunakan untuk menyimpan dua pointer utama yaitu first (kepala) dan last (ekor) yang memungkinkan akses cepat ke kedua ujung daftar. File ini juga mendefinisikan berbagai fungsi penting seperti isEmpty, createList, alokasi, dealokasi, serta fungsi insertion dan update yang menjadi dasar dari operasi utama Doubly Linked List.

File listMakanan.cpp berperan sebagai implementasi dari semua fungsi yang dideklarasikan dalam header file. Implementasi dimulai dengan fungsi isEmpty yang memeriksa apakah daftar makanan kosong atau tidak, serta createList yang menginisialisasi linked list dengan nilai awal Nil. Fungsi alokasi digunakan untuk membuat node baru dan mengalokasikan memori secara dinamis, kemudian menyimpan data makanan pada node tersebut. Fungsi dealokasi berfungsi untuk menghapus node dari memori ketika sudah tidak digunakan, mencegah terjadinya kebocoran memori (memory leak).

Proses penyisipan data (insertion) dijabarkan dalam beberapa fungsi, yakni insertFirst, insertLast, insertAfter, dan insertBefore. Setiap fungsi ini memiliki mekanisme yang berbeda tergantung pada posisi penyisipan node dalam daftar. Misalnya, insertFirst menambahkan node di awal daftar dengan memperbarui pointer first, sedangkan insertLast menambahkan node di akhir dengan memperbarui pointer last. Fungsi insertAfter dan insertBefore memberikan fleksibilitas lebih, memungkinkan penambahan node di antara dua node yang sudah ada dengan menyesuaikan arah pointer next dan prev. Implementasi ini mencerminkan efisiensi yang menjadi ciri khas Doubly Linked List karena tidak memerlukan pergeseran data sebagaimana pada array.

Selain itu, terdapat serangkaian fungsi pembaruan data (update) yang memungkinkan pengguna memperbarui isi node tanpa menghapusnya terlebih dahulu. Fungsi updateFirst dan updateLast digunakan untuk memperbarui data pada node pertama dan terakhir, sedangkan updateAfter dan updateBefore memungkinkan pembaruan data pada node yang berada di tengah daftar, baik setelah atau sebelum node tertentu. Proses update dilakukan dengan menerima input baru dari pengguna untuk menggantikan nilai atribut yang ada sebelumnya. Dengan adanya fungsi ini, struktur data tetap dinamis dan dapat diubah tanpa perlu melakukan operasi deletion atau reallocation.

File main.cpp berfungsi sebagai driver atau program utama yang mengatur jalannya eksekusi seluruh operasi. Di dalam fungsi main(), linked list diinisialisasi terlebih dahulu dengan pemanggilan fungsi createList, kemudian lima node baru dialokasikan menggunakan fungsi alokasi. Setiap node merepresentasikan satu jenis makanan yang memiliki nilai atribut berbeda. Fungsi penyisipan kemudian dipanggil untuk menempatkan node-node tersebut di posisi yang berbeda, baik di awal, akhir, setelah, maupun sebelum node lain, sehingga menghasilkan susunan data yang fleksibel dan dapat disesuaikan.

Setelah operasi penyisipan, program menampilkan isi daftar makanan menggunakan fungsi printList, yang menelusuri setiap node dari first hingga last dan mencetak data makanan secara berurutan. Program juga mendemonstrasikan kemampuan update dengan memanggil fungsi updateFirst, updateLast, updateBefore, dan updateAfter, yang memungkinkan pengguna memperbarui data makanan sesuai keinginan. Implementasi ini menegaskan sifat dinamis dari Doubly Linked List, di mana setiap node dapat dimodifikasi secara langsung melalui pengaturan ulang pointer tanpa mempengaruhi integritas struktur keseluruhan.

Secara keseluruhan, ketiga file ini menggambarkan penerapan konsep Doubly Linked List secara komprehensif. Struktur ini memberikan efisiensi tinggi dalam hal manipulasi data karena mendukung akses dua arah, kemudahan penyisipan dan penghapusan data di berbagai posisi, serta fleksibilitas dalam pembaruan elemen. Implementasi ini juga menyoroti pentingnya manajemen memori dinamis dalam pemrograman berbasis pointer, di mana pengalokasian dan dealokasi memori harus dilakukan dengan hati-hati untuk menjaga kestabilan program. Dengan demikian, program ini bukan hanya memberikan pemahaman praktis terhadap mekanisme kerja Doubly Linked List, tetapi juga memperlihatkan bagaimana konsep tersebut dapat diterapkan dalam konteks nyata seperti pengelolaan data makanan dengan berbagai atribut yang saling terhubung.


### 2.1 listMakanan.h

```h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

### 1.2 listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

### 1.3 main.cpp

```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

Ketiga file kode yang terdiri dari listMakanan.h, listMakanan.cpp, dan main.cpp pada dasarnya merupakan implementasi lengkap dari struktur data Doubly Linked List (DLL) dengan fokus pada proses penyisipan (insertion), pencarian (searching), pembaruan (updating), serta penghapusan data (deletion). Program ini dirancang untuk mengelola data bertipe makanan, yang masing-masing node-nya menyimpan informasi nama, jenis, harga, dan rating makanan. Implementasi ini menunjukkan bagaimana struktur data dinamis digunakan untuk menyimpan dan memanipulasi data secara efisien melalui mekanisme pointer dua arah, yang memungkinkan traversal maju maupun mundur di dalam daftar.

Pada file listMakanan.h, ditetapkan struktur utama yang menjadi fondasi dari keseluruhan implementasi. Struktur makanan menyimpan data utama berupa nama, jenis, harga, dan rating. Struktur node kemudian merepresentasikan elemen dalam Doubly Linked List yang terdiri atas satu variabel bertipe dataMakanan dan dua pointer, next serta prev, yang masing-masing menunjuk ke node berikutnya dan sebelumnya. Selanjutnya, struktur linkedlist berfungsi sebagai pengendali utama yang menyimpan dua pointer penting yaitu first dan last, yang menunjukkan node pertama dan terakhir pada list. File ini juga mendeklarasikan berbagai prosedur dan fungsi yang meliputi operasi dasar seperti insertFirst, insertAfter, findByName, hingga operasi penghapusan seperti deleteBefore dan deleteByName, yang semuanya berperan dalam memanipulasi elemen dalam list secara efisien.

Implementasi dari deklarasi tersebut terdapat dalam file listMakanan.cpp, yang memuat definisi fungsi secara lengkap. Proses dimulai dengan isEmpty untuk mengecek apakah list kosong, serta createList yang menginisialisasi list dengan nilai awal kosong (Nil). Fungsi alokasi digunakan untuk mengalokasikan memori secara dinamis bagi node baru, sementara dealokasi bertugas menghapus node dari memori guna mencegah memory leak. Operasi penyisipan data (insertFirst, insertLast, insertAfter, dan insertBefore) menggambarkan bagaimana pointer dalam DLL dapat dimodifikasi agar node baru dapat dimasukkan pada berbagai posisi tanpa perlu menggeser elemen lain seperti dalam array. Misalnya, insertAfter akan menambahkan node setelah node tertentu dengan menyesuaikan pointer next dan prev dari node yang terlibat, sedangkan insertBefore menambahkan node sebelum node tertentu dengan prinsip yang sama.

Fungsi printList digunakan untuk menampilkan seluruh isi list dengan melakukan traversal dari node pertama hingga node terakhir, menampilkan seluruh atribut dari setiap node. Selain itu, program juga mengimplementasikan serangkaian fungsi update seperti updateFirst, updateLast, updateAfter, dan updateBefore, yang memungkinkan pembaruan data node tanpa perlu menghapus dan menyisipkan kembali. Proses pembaruan dilakukan dengan mengganti nilai atribut nama, jenis, harga, dan rating berdasarkan input pengguna, menunjukkan fleksibilitas dari struktur data DLL dalam menangani perubahan data secara langsung.

Salah satu aspek penting dalam implementasi ini adalah fitur searching, yang dilakukan melalui tiga metode utama, yaitu findByName, findByJenis, dan findByMinRating. Fungsi-fungsi ini memperlihatkan kemampuan Doubly Linked List dalam melakukan penelusuran data secara selektif. Fungsi findByName mencari node berdasarkan nama makanan, findByJenis menelusuri list untuk menemukan makanan berdasarkan kategori atau jenisnya, sementara findByMinRating menampilkan makanan dengan rating minimum tertentu. Pencarian dilakukan dengan menelusuri pointer next dari node pertama hingga terakhir, menunjukkan efisiensi linear traversal yang menjadi ciri khas struktur ini.

Bagian terakhir dari implementasi berfokus pada operasi penghapusan (deletion) yang merupakan aspek krusial dalam manajemen data dinamis. Fungsi deleteFirst dan deleteLast digunakan untuk menghapus node pada ujung daftar, sedangkan deleteAfter dan deleteBefore memungkinkan penghapusan node yang berada di tengah list dengan menjaga konsistensi koneksi pointer sebelum dan sesudah node yang dihapus. Selain itu, terdapat pula fungsi deleteNode yang memungkinkan penghapusan node berdasarkan alamat tertentu, serta deleteByName yang menghapus node berdasarkan nilai nama yang dicari. Implementasi ini menunjukkan bagaimana Doubly Linked List memanfaatkan struktur pointer dua arah untuk meminimalkan kompleksitas penghapusan tanpa perlu memindahkan seluruh elemen seperti pada struktur data linear konvensional.

File main.cpp bertindak sebagai driver program yang mengintegrasikan seluruh fungsi dari file header dan implementasi. Di dalamnya, list diinisialisasi terlebih dahulu dengan createList, kemudian beberapa node dialokasikan menggunakan alokasi dengan berbagai nilai atribut makanan. Node-node ini kemudian disisipkan ke dalam list menggunakan kombinasi fungsi insertFirst, insertLast, insertAfter, dan insertBefore, menghasilkan susunan dinamis seperti D–A–C–E–B sesuai urutan eksekusi. Program kemudian melakukan serangkaian operasi pembaruan, pencarian, dan penghapusan. Fungsi findByName dan deleteByName mendemonstrasikan bagaimana pencarian dan penghapusan data dilakukan secara selektif berdasarkan kriteria tertentu. Hasil akhir dari setiap operasi ditampilkan melalui printList untuk menunjukkan perubahan struktur list secara visual.

Secara keseluruhan, ketiga file ini menggambarkan implementasi Doubly Linked List yang sangat komprehensif. Program tidak hanya mencakup operasi dasar seperti penyisipan dan penghapusan, tetapi juga mencakup fitur pencarian dan pembaruan yang memperkaya fungsionalitasnya. Dengan memanfaatkan dua pointer utama pada setiap node, operasi manipulasi data menjadi lebih fleksibel dan efisien dibandingkan dengan singly linked list. Implementasi ini mencerminkan prinsip dasar pengelolaan memori dinamis dan efisiensi akses data dalam ilmu komputer. Secara konseptual, penerapan Doubly Linked List dalam konteks pengelolaan data makanan ini dapat diperluas untuk berbagai aplikasi lain, seperti sistem manajemen data produk, inventori restoran, maupun sistem rekomendasi berbasis rating yang memanfaatkan traversal dua arah untuk optimasi pencarian dan pembaruan data.


## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”. Kemudian buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.

#### Doublylist.h

```h
#ifndef LISTKENDARAAN_H
#define LISTKENDARAAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat;
};

typedef kendaraan infoType;

typedef struct ElmList *address;

struct ElmList{
    infoType isidata;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &ElmList);

bool isNopolExist(List L, string nopol);
void insertLast(List &L, address ElmListBaru);

void printList(List L);

#endif
```

##### Doublylist.cpp

```C++
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nopol, string warna, int thnBuat) { 
    address nodeBaru = new ElmList;
    nodeBaru->isidata.nopol = nopol;
    nodeBaru->isidata.warna = warna; 
    nodeBaru->isidata.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

bool isNopolExist(List L, string nopol) {
    address p = L.first;
    while(p != Nil) {
        if(p->isidata.nopol == nopol) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void insertLast(List &L, address nodeBaru){
    if(isEmpty(L) == true){
        L.first = L.last = nodeBaru;
    } else {
        nodeBaru->prev = L.last;
        L.last->next = nodeBaru;
        L.last = nodeBaru;
    }
    cout << "Kendaraan dengan nomor polisi " << nodeBaru->isidata.nopol << " berhasil ditambahkan!" << endl;
}

void printList(List L) {
    if (isEmpty(L) == true) {
        cout << "L kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << "Nomor Polisi : " << nodeBantu->isidata.nopol << endl;
            cout << "Warna        : " << nodeBantu->isidata.warna << endl;
            cout << "Tahun        : " << nodeBantu->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

##### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    List L;
    createList(L);

    infoType dataKendaraan;
    string nopol, warna, cariNopol, hapusNopol;
    int thnBuat;
    int count = 0;
    
    while(count < 3) {
        cout << "\nKendaraan ke-" << (count + 1) << endl;
        cout << "Masukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;
        cin.ignore();
        
        if(!isNopolExist(L, nopol)) {
            address nodeBaru = alokasi(nopol, warna, thnBuat);
            insertLast(L, nodeBaru);
            count++;
        } else {
            cout << "Nomor polisi " << nopol << " sudah terdaftar!" << endl;
        }
    }
    
    cout << "\n=== DATA LIST ===" << endl;
    printList(L);

    return 0;
}
```

Ketiga file kode yang terdiri atas Doublylist.h, Doublylist.cpp, dan main.cpp merupakan implementasi dasar dari struktur data Doubly Linked List (DLL) yang digunakan untuk menyimpan dan mengelola data kendaraan secara dinamis. Implementasi ini memperlihatkan bagaimana konsep pointer dua arah (next dan prev) dimanfaatkan untuk menambah, menghapus, dan menelusuri data tanpa batasan ukuran seperti pada array statis. Doubly Linked List menjadi salah satu struktur data yang efisien dalam manajemen memori dan fleksibel dalam manipulasi data, khususnya pada konteks penyimpanan data yang berubah-ubah seperti daftar kendaraan yang dapat bertambah sewaktu-waktu.

Pada file Doublylist.h, didefinisikan struktur dan fungsi dasar yang membentuk fondasi dari program. Struktur kendaraan berfungsi sebagai wadah data utama (payload) yang menyimpan informasi berupa nomor polisi (nopol), warna kendaraan, dan tahun pembuatan. Data tersebut kemudian disimpan dalam node bertipe ElmList, yang memiliki dua pointer — next dan prev — untuk menghubungkan setiap elemen ke node berikutnya dan sebelumnya. Struktur List digunakan untuk menyimpan dua pointer utama, first dan last, yang masing-masing menunjuk ke elemen pertama dan terakhir dari list. Melalui pendekatan ini, traversal data dapat dilakukan dari dua arah, yaitu dari awal ke akhir maupun sebaliknya, sesuai dengan karakteristik utama Doubly Linked List.

File ini juga berisi deklarasi fungsi-fungsi utama seperti createList, alokasi, dealokasi, dan insertLast, yang merupakan operasi mendasar dalam pembentukan dan manipulasi list. Fungsi isEmpty digunakan untuk memeriksa apakah list masih kosong, sedangkan isNopolExist berperan penting dalam menjaga integritas data dengan memastikan tidak ada duplikasi nomor polisi kendaraan yang dimasukkan ke dalam list. Pendekatan ini mencerminkan penerapan prinsip validasi data yang umum digunakan pada sistem basis data atau sistem manajemen entitas unik, seperti registrasi kendaraan bermotor.

Implementasi dari deklarasi tersebut dapat ditemukan dalam file Doublylist.cpp, yang berfungsi merealisasikan logika dari setiap fungsi yang telah didefinisikan. Pada tahap awal, fungsi createList menginisialisasi list dengan nilai Nil (penanda null pointer) untuk memastikan list dimulai dalam keadaan kosong. Fungsi alokasi bertanggung jawab dalam pembuatan node baru secara dinamis menggunakan operator new, yang kemudian diisi dengan data kendaraan dan diinisialisasi dengan pointer next dan prev yang mengarah ke Nil. Sebaliknya, dealokasi digunakan untuk menghapus node dari memori ketika tidak lagi dibutuhkan, sebagai bentuk penerapan manajemen memori yang efisien.

Fungsi isNopolExist memiliki peran sentral dalam menjaga konsistensi data. Fungsi ini menelusuri seluruh elemen dalam list dengan traversal linear untuk memastikan tidak ada nomor polisi yang sama sebelum data baru dimasukkan. Hal ini menjadi penting dalam konteks aplikasi nyata, misalnya dalam sistem pendataan kendaraan di instansi pemerintahan, di mana setiap nomor polisi harus unik dan tidak boleh terduplikasi.

Operasi penyisipan dilakukan melalui fungsi insertLast, yang menambahkan node baru di akhir list. Implementasi fungsi ini menunjukkan fleksibilitas Doubly Linked List dalam menambahkan data tanpa perlu menggeser elemen-elemen yang sudah ada, berbeda dengan array konvensional. Jika list masih kosong, maka node baru akan menjadi elemen pertama sekaligus terakhir. Namun, jika sudah ada elemen sebelumnya, pointer prev pada node baru akan diarahkan ke elemen terakhir sebelumnya, dan pointer next pada elemen terakhir akan dihubungkan ke node baru. Setelah itu, pointer last pada list akan diperbarui untuk menunjuk ke node terakhir yang baru ditambahkan.

Seluruh data kendaraan yang telah dimasukkan dapat ditampilkan melalui fungsi printList. Fungsi ini menelusuri list dari node pertama (first) hingga node terakhir (Nil) sambil mencetak isi setiap elemen. Pendekatan ini menunjukkan bahwa struktur Doubly Linked List memungkinkan traversal dua arah, meskipun dalam implementasi ini hanya digunakan satu arah (maju). Fungsi ini juga menjadi ilustrasi sederhana bagaimana data dapat disimpan dan diakses secara berurutan menggunakan struktur data dinamis.

File main.cpp berperan sebagai driver program yang mengintegrasikan seluruh fungsi dari dua file sebelumnya. Pada bagian awal, list kendaraan diinisialisasi dengan memanggil fungsi createList. Selanjutnya, program meminta pengguna untuk memasukkan data kendaraan sebanyak tiga kali, yang terdiri dari nomor polisi, warna, dan tahun pembuatan. Sebelum data dimasukkan, dilakukan pengecekan menggunakan isNopolExist untuk memastikan tidak ada nomor polisi yang sama di dalam list. Jika data valid, maka fungsi alokasi dipanggil untuk membuat node baru, dan insertLast digunakan untuk menambahkan node tersebut ke bagian akhir list. Setelah seluruh data berhasil dimasukkan, fungsi printList digunakan untuk menampilkan seluruh isi list kendaraan beserta atributnya.

Secara konseptual, implementasi ini menggambarkan bagaimana Doubly Linked List dapat digunakan untuk membangun sistem penyimpanan data yang terstruktur, dinamis, dan efisien. Keunggulan utama struktur ini terletak pada kemampuannya untuk melakukan manipulasi data, seperti penyisipan dan penghapusan, dengan kompleksitas waktu yang lebih rendah dibandingkan struktur data statis. Selain itu, penggunaan pointer dua arah memungkinkan akses fleksibel dari kedua ujung list, yang dapat dimanfaatkan untuk pengembangan fitur lanjutan seperti penghapusan berdasarkan posisi, pencarian mundur, atau pengurutan data berdasarkan kriteria tertentu.

Dengan demikian, implementasi Doubly Linked List pada program ini tidak hanya berfungsi sebagai latihan dasar pemrograman berorientasi data, tetapi juga memberikan pemahaman mendalam tentang manajemen memori, struktur dinamis, dan penerapan prinsip data integrity dalam sistem informasi yang lebih kompleks, seperti pendataan kendaraan, manajemen inventori, dan sistem registrasi berbasis entitas unik.

### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week6/output/output-unguided1.png)


### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.
### fungsi findElm( L : List, x : infotype ) : address

#### Doublylist.h
```h
#ifndef LISTKENDARAAN_H
#define LISTKENDARAAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat;
};

typedef kendaraan infoType;

typedef struct ElmList *address;

struct ElmList{
    infoType isidata;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &ElmList);

bool isNopolExist(List L, string nopol);
void insertLast(List &L, address ElmListBaru);

void printList(List L);

// Searching
void findElm(List L, string nopol);

#endif
```

##### Doublylist.cpp

```C++
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nopol, string warna, int thnBuat) { 
    address nodeBaru = new ElmList;
    nodeBaru->isidata.nopol = nopol;
    nodeBaru->isidata.warna = warna; 
    nodeBaru->isidata.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

bool isNopolExist(List L, string nopol) {
    address p = L.first;
    while(p != Nil) {
        if(p->isidata.nopol == nopol) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void insertLast(List &L, address nodeBaru){
    if(isEmpty(L) == true){
        L.first = L.last = nodeBaru;
    } else {
        nodeBaru->prev = L.last;
        L.last->next = nodeBaru;
        L.last = nodeBaru;
    }
    cout << "Kendaraan dengan nomor polisi " << nodeBaru->isidata.nopol << " berhasil ditambahkan!" << endl;
}

void printList(List L) {
    if (isEmpty(L) == true) {
        cout << "L kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << "Nomor Polisi : " << nodeBantu->isidata.nopol << endl;
            cout << "Warna        : " << nodeBantu->isidata.warna << endl;
            cout << "Tahun        : " << nodeBantu->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// SEARCHING
void findElm(List L, string nopol){
    if(isEmpty(L)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = L.first;
    while(p != Nil){
        if(p->isidata.nopol == nopol){
            cout << "Ditemukan (berdasarkan nomor polisi):" << endl;
            cout << "Nomor Polisi : " << p->isidata.nopol << endl;
            cout << "Warna        : " << p->isidata.warna << endl;
            cout << "Tahun        : " << p->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            return;
        }
        p = p->next;
    }
    cout << "Kendaraan dengan nomor polisi \"" << nopol << "\" tidak ditemukan." << endl;
}
```

##### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    List L;
    createList(L);

    infoType dataKendaraan;
    string nopol, warna, cariNopol, hapusNopol;
    int thnBuat;
    int count = 0;
    
    while(count < 3) {
        cout << "\nKendaraan ke-" << (count + 1) << endl;
        cout << "Masukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;
        cin.ignore();
        
        if(!isNopolExist(L, nopol)) {
            address nodeBaru = alokasi(nopol, warna, thnBuat);
            insertLast(L, nodeBaru);
            count++;
        } else {
            cout << "Nomor polisi " << nopol << " sudah terdaftar!" << endl;
        }
    }
    
    cout << "\n=== DATA LIST ===" << endl;
    printList(L);

    cout << "\nMasukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    findElm(L, cariNopol);

    return 0;
}
```

Ketiga file kode yang terdiri atas Doublylist.h, Doublylist.cpp, dan main.cpp merepresentasikan implementasi dasar dari struktur data Doubly Linked List (DLL) dengan fokus utama pada penerapan fungsi pencarian elemen (findElm). Program ini dirancang untuk menyimpan, menampilkan, dan mencari data kendaraan berdasarkan atribut nomor polisi. Melalui pendekatan ini, ditunjukkan bagaimana operasi pencarian dalam struktur data dinamis dapat dilakukan secara efisien dengan memanfaatkan mekanisme penelusuran berantai menggunakan pointer dua arah.

Pada file Doublylist.h, didefinisikan tipe data dan struktur dasar yang menjadi fondasi bagi keseluruhan program. Struktur kendaraan digunakan sebagai payload yang menyimpan tiga atribut utama, yaitu nomor polisi (nopol), warna kendaraan, dan tahun pembuatan. Data ini kemudian disimpan di dalam node bertipe ElmList, yang dilengkapi dengan dua pointer, yakni next dan prev, untuk menghubungkan node satu dengan lainnya dalam arah maju dan mundur. Struktur List sendiri memiliki dua pointer utama — first untuk menunjuk ke elemen pertama dan last untuk menunjuk ke elemen terakhir. Desain ini menjadi ciri khas doubly linked list, yang memungkinkan traversal dua arah serta fleksibilitas tinggi dalam operasi manipulasi data.

Selain definisi struktur, file header ini juga mencantumkan deklarasi fungsi yang digunakan untuk operasi dasar, seperti createList untuk inisialisasi list, alokasi untuk membuat node baru, dealokasi untuk membebaskan memori, insertLast untuk menambahkan data di bagian akhir list, serta isNopolExist untuk memastikan tidak terjadi duplikasi nomor polisi. Di antara fungsi-fungsi tersebut, fungsi findElm menjadi komponen utama dalam konteks pencarian data kendaraan berdasarkan nomor polisi yang diinput oleh pengguna. Fungsi ini memiliki peran penting dalam membuktikan efisiensi penelusuran data dalam struktur dinamis seperti doubly linked list.

Pada file Doublylist.cpp, seluruh deklarasi fungsi dari header diimplementasikan secara konkret. Fungsi createList menginisialisasi pointer first dan last agar bernilai Nil, yang menandakan list masih kosong. Fungsi alokasi menggunakan operator new untuk membuat node baru secara dinamis, mengisi atribut kendaraan, serta mengatur pointer next dan prev agar bernilai Nil. Kemudian, insertLast digunakan untuk menambahkan data baru di bagian akhir list, di mana node terakhir sebelumnya dihubungkan ke node baru melalui pointer next, sedangkan pointer prev pada node baru menunjuk kembali ke node terakhir lama.

Fokus utama dari implementasi ini adalah pada fungsi findElm, yang dirancang untuk melakukan pencarian data berdasarkan nomor polisi. Proses pencarian dimulai dengan pemeriksaan kondisi apakah list kosong menggunakan fungsi isEmpty. Jika list kosong, maka program akan menampilkan pesan “List kosong!” dan proses pencarian dihentikan. Namun, jika list berisi data, maka dilakukan traversal dimulai dari node pertama (L.first) hingga node terakhir (Nil). Pada setiap iterasi, fungsi akan membandingkan nilai nopol yang dicari dengan p->isidata.nopol menggunakan operator kesetaraan (==).

Apabila ditemukan kecocokan, fungsi akan segera menampilkan detail kendaraan yang ditemukan, meliputi nomor polisi, warna, dan tahun pembuatan, disertai pesan konfirmasi bahwa data telah ditemukan. Setelah data ditemukan, fungsi segera mengembalikan kontrol dengan perintah return, sehingga traversal berhenti tanpa harus melanjutkan pencarian ke elemen-elemen berikutnya. Jika seluruh node telah diperiksa dan tidak ditemukan kecocokan, maka program akan menampilkan pesan “Kendaraan dengan nomor polisi [nopol] tidak ditemukan.”.

Pendekatan linear ini mencerminkan algoritma pencarian sekuensial (sequential search) yang umum diterapkan dalam struktur data berantai seperti linked list. Kompleksitas waktu dari fungsi findElm adalah O(n), di mana n adalah jumlah elemen dalam list. Hal ini disebabkan karena setiap elemen harus diperiksa satu per satu hingga ditemukan elemen yang sesuai atau hingga mencapai akhir list. Walaupun demikian, algoritma ini tetap efisien untuk jumlah data yang tidak terlalu besar dan sangat relevan dalam konteks pembelajaran dasar struktur data dinamis.

Pada file main.cpp, fungsi findElm diintegrasikan dalam alur interaktif program. Setelah inisialisasi list melalui createList, pengguna diminta untuk memasukkan data kendaraan sebanyak tiga kali, terdiri dari nomor polisi, warna kendaraan, dan tahun pembuatan. Sebelum data baru ditambahkan, fungsi isNopolExist digunakan untuk memastikan tidak ada duplikasi nomor polisi di dalam list. Setelah semua data berhasil dimasukkan, program menampilkan seluruh isi list menggunakan printList.

Selanjutnya, pengguna diminta memasukkan nomor polisi kendaraan yang ingin dicari. Input ini kemudian dikirim ke fungsi findElm, yang akan menampilkan hasil pencarian secara langsung di layar. Jika data ditemukan, seluruh atribut kendaraan tersebut ditampilkan dengan format terstruktur. Namun, jika data tidak ditemukan, program menampilkan pesan kesalahan yang informatif tanpa menghentikan eksekusi program secara tiba-tiba.

Secara keseluruhan, fungsi findElm dalam implementasi ini memiliki peranan fundamental dalam memperkenalkan konsep pencarian data pada struktur berantai dua arah (doubly linked list). Selain menunjukkan bagaimana traversal pointer dilakukan secara sistematis, fungsi ini juga mencontohkan penerapan error handling yang baik melalui pengecekan kondisi list kosong dan validasi hasil pencarian. Dalam konteks pembelajaran struktur data, fungsi ini memperlihatkan bagaimana operasi sederhana seperti pencarian dapat diimplementasikan secara efisien pada struktur data dinamis, serta menjadi dasar untuk pengembangan algoritma pencarian yang lebih kompleks seperti binary search atau hash-based search pada sistem yang lebih besar.

Dengan demikian, dapat disimpulkan bahwa fungsi findElm tidak hanya berfungsi sebagai mekanisme pencarian data dalam list kendaraan, tetapi juga menjadi contoh nyata penerapan prinsip-prinsip dasar struktur data, yaitu pengelolaan memori dinamis, traversal pointer, dan validasi logika algoritmik yang mendukung efisiensi dan integritas data dalam sistem penyimpanan berbasis Doubly Linked List.


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week6/output/output-unguided2.png)


### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.
#### - procedure deleteFirst( input/output L : List,
#### P : address )
#### - procedure deleteLast( input/output L : List,
#### P : address )
#### - procedure deleteAfter( input Prec : address,
#### input/output P : address )

#### Doublylist.h
```h
#ifndef LISTKENDARAAN_H
#define LISTKENDARAAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat;
};

typedef kendaraan infoType;

typedef struct ElmList *address;

struct ElmList{
    infoType isidata;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &ElmList);

bool isNopolExist(List L, string nopol);
void insertLast(List &L, address ElmListBaru);

void printList(List L);

// Searching
void findElm(List L, string nopol);

// Delete
void deleteFirst(List &List);
void deleteLast(List &List);
void deleteAfter(List &List, address Prev);

#endif
```

##### Doublylist.cpp

```C++
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nopol, string warna, int thnBuat) { 
    address nodeBaru = new ElmList;
    nodeBaru->isidata.nopol = nopol;
    nodeBaru->isidata.warna = warna; 
    nodeBaru->isidata.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

bool isNopolExist(List L, string nopol) {
    address p = L.first;
    while(p != Nil) {
        if(p->isidata.nopol == nopol) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void insertLast(List &L, address nodeBaru){
    if(isEmpty(L) == true){
        L.first = L.last = nodeBaru;
    } else {
        nodeBaru->prev = L.last;
        L.last->next = nodeBaru;
        L.last = nodeBaru;
    }
    cout << "Kendaraan dengan nomor polisi " << nodeBaru->isidata.nopol << " berhasil ditambahkan!" << endl;
}

void printList(List L) {
    if (isEmpty(L) == true) {
        cout << "L kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << "Nomor Polisi : " << nodeBantu->isidata.nopol << endl;
            cout << "Warna        : " << nodeBantu->isidata.warna << endl;
            cout << "Tahun        : " << nodeBantu->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// SEARCHING
void findElm(List L, string nopol){
    if(isEmpty(L)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = L.first;
    while(p != Nil){
        if(p->isidata.nopol == nopol){
            cout << "Ditemukan (berdasarkan nomor polisi):" << endl;
            cout << "Nomor Polisi : " << p->isidata.nopol << endl;
            cout << "Warna        : " << p->isidata.warna << endl;
            cout << "Tahun        : " << p->isidata.thnBuat<< endl;
            cout << "-------------------------------" << endl;
            return;
        }
        p = p->next;
    }
    cout << "Kendaraan dengan nomor polisi \"" << nopol << "\" tidak ditemukan." << endl;
}

// DELETE
void deleteFirst(List &L){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.first;
    if(L.first == L.last){
        L.first = L.last = Nil;
    } else {
        L.first = pDel->next;
        L.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(List &L){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.last;
    if(L.first == L.last){
        L.first = L.last = Nil;
    } else {
        L.last = pDel->prev;
        L.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(List &L, address Prev){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada kendaraan yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Kendaraan sebelumnya (Prev) tidak valid atau tidak ada kendaraan setelahnya!" << endl;
        return;
    }
    if(Prev->next == L.last){
        deleteLast(L);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus setelah kendaraan bernomor polisi " << Prev->isidata.nopol << "." << endl;
    dealokasi(pDel);
}
```

##### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    List L;
    createList(L);

    infoType dataKendaraan;
    string nopol, warna, cariNopol, hapusNopol;
    int thnBuat;
    int count = 0;
    
    while(count < 3) {
        cout << "\nKendaraan ke-" << (count + 1) << endl;
        cout << "Masukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;
        cin.ignore();
        
        if(!isNopolExist(L, nopol)) {
            address nodeBaru = alokasi(nopol, warna, thnBuat);
            insertLast(L, nodeBaru);
            count++;
        } else {
            cout << "Nomor polisi " << nopol << " sudah terdaftar!" << endl;
        }
    }
    
    cout << "\n=== DATA LIST ===" << endl;
    printList(L);

    cout << "\nMasukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    findElm(L, cariNopol);

    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    if(!isEmpty(L)) {
        address p = L.first;
        
        if(p->isidata.nopol == hapusNopol) {
            deleteFirst(L);
        } else if(L.last->isidata.nopol == hapusNopol) {
            deleteLast(L);
        } else {
            while(p != Nil && p->next != Nil) {
                if(p->next->isidata.nopol == hapusNopol) {
                    deleteAfter(L, p);
                    break;
                }
                p = p->next;
            }
        }
    }
    
    cout << "\n=== DATA LIST ===" << endl;
    printList(L);

    return 0;
}
```

Ketiga file kode yang terdiri atas Doublylist.h, Doublylist.cpp, dan main.cpp merepresentasikan implementasi struktur data Doubly Linked List (DLL) dengan fokus utama pada operasi penghapusan data (deletion), khususnya melalui tiga fungsi penting, yaitu deleteFirst, deleteLast, dan deleteAfter. Program ini dirancang untuk mengelola data kendaraan yang disimpan dalam bentuk node dinamis dengan dua arah penunjuk (pointer dua arah), yang memungkinkan efisiensi tinggi dalam manipulasi data, baik dari sisi awal, tengah, maupun akhir daftar.

Pada file Doublylist.h, ditetapkan struktur dasar dari list ganda. Struktur kendaraan berfungsi sebagai entitas data (payload) yang menyimpan tiga atribut penting yaitu nomor polisi (nopol), warna kendaraan, dan tahun pembuatan (thnBuat). Setiap data kendaraan ditempatkan dalam node bertipe ElmList yang memiliki dua pointer, next untuk menunjuk ke elemen berikutnya dan prev untuk menunjuk ke elemen sebelumnya. Struktur List sendiri memiliki dua pointer utama, yakni first dan last, yang mengindikasikan simpul pertama dan terakhir dalam list. Dengan desain ini, Doubly Linked List memiliki kemampuan traversal dua arah yang fleksibel, memungkinkan operasi penghapusan data dilakukan dengan efisien tanpa perlu memindahkan atau menyalin seluruh elemen seperti pada struktur array.

Selain deklarasi struktur, file ini juga mencantumkan prototipe fungsi untuk operasi dasar seperti createList, alokasi, dealokasi, insertLast, dan findElm. Namun, fokus utama terdapat pada tiga fungsi penghapusan, deleteFirst, deleteLast, dan deleteAfter yang masing-masing berperan dalam menghapus data di posisi awal, akhir, maupun setelah elemen tertentu di dalam list.

Pada file Doublylist.cpp, seluruh fungsi tersebut diimplementasikan secara konkret. Fungsi deleteFirst bertugas untuk menghapus node yang berada di posisi paling awal dalam list. Proses penghapusan dimulai dengan pengecekan apakah list kosong melalui fungsi isEmpty. Jika list kosong, maka program menampilkan pesan bahwa tidak ada node yang dapat dihapus. Jika list berisi data, maka node pertama (L.first) disimpan sementara dalam variabel pDel untuk kemudian dihapus. Jika hanya terdapat satu node dalam list (artinya L.first == L.last), maka kedua pointer first dan last diset menjadi Nil, menandakan list menjadi kosong. Namun, jika list memiliki lebih dari satu elemen, maka pointer first akan digeser ke node berikutnya (pDel->next), dan pointer prev dari node baru pertama diset ke Nil. Setelah pointer hubungan antar-node diperbarui, node yang dihapus di-dealokasi menggunakan fungsi dealokasi, dan pesan konfirmasi penghapusan ditampilkan.

Fungsi deleteLast memiliki prinsip kerja yang mirip, namun diterapkan pada node terakhir dalam list. Setelah memastikan list tidak kosong, fungsi menyimpan node terakhir (L.last) dalam variabel pDel. Jika hanya terdapat satu elemen, maka first dan last diatur menjadi Nil, mengosongkan list sepenuhnya. Namun, jika terdapat lebih dari satu elemen, pointer last akan digeser ke node sebelumnya (pDel->prev), dan pointer next dari node baru terakhir diset ke Nil. Node yang dihapus kemudian di-dealokasi dan pesan penghapusan ditampilkan. Dengan logika dua arah ini, penghapusan di bagian akhir list menjadi efisien karena tidak memerlukan traversal dari awal hingga akhir seperti yang terjadi pada struktur singly linked list.

Sementara itu, fungsi deleteAfter memiliki peran yang lebih kompleks karena melibatkan penghapusan node yang berada di posisi setelah node tertentu (Prev). Pertama, fungsi memeriksa kondisi apakah list kosong atau pointer Prev tidak valid. Jika kondisi tersebut terpenuhi, maka operasi dibatalkan dengan menampilkan pesan kesalahan. Selanjutnya, fungsi memeriksa apakah node setelah Prev merupakan node terakhir (L.last). Jika benar, maka fungsi deleteLast dipanggil untuk menghapus node terakhir. Namun, jika node yang akan dihapus berada di tengah list, maka pointer Prev->next diatur untuk melewati node yang akan dihapus (pDel) dan langsung menunjuk ke node setelahnya (pDel->next). Kemudian, pointer prev dari node setelah pDel diatur kembali untuk menunjuk ke Prev, sehingga hubungan dua arah antar-node tetap terjaga dengan baik. Node yang telah terputus dari list kemudian di-dealokasi untuk membebaskan memori, dan program menampilkan pesan bahwa penghapusan berhasil dilakukan setelah node tertentu.

Dari sisi efisiensi, ketiga fungsi penghapusan ini bekerja dengan kompleksitas waktu O(1) pada kasus penghapusan di awal (deleteFirst) dan akhir (deleteLast), karena tidak memerlukan traversal seluruh elemen. Namun, untuk deleteAfter, kompleksitas waktunya menjadi O(n) dalam konteks umum, sebab diperlukan traversal untuk menemukan node Prev terlebih dahulu. Meskipun demikian, setelah node Prev diketahui, proses penghapusan dilakukan dalam waktu konstan karena hanya melibatkan pengaturan ulang beberapa pointer.

file main.cpp berfungsi sebagai program pengujian yang mengintegrasikan seluruh fungsi tersebut dalam skenario interaktif. Program dimulai dengan inisialisasi list kosong melalui createList, kemudian meminta pengguna untuk memasukkan tiga data kendaraan berupa nomor polisi, warna kendaraan, dan tahun pembuatan. Data baru dimasukkan ke dalam list menggunakan fungsi insertLast. Setelah seluruh data dimasukkan, program menampilkan isi list dan memungkinkan pengguna untuk mencari data kendaraan tertentu menggunakan findElm.

Tahapan berikutnya adalah pengujian fungsi penghapusan. Pengguna diminta untuk memasukkan nomor polisi kendaraan yang ingin dihapus. Program kemudian memeriksa apakah data yang akan dihapus berada di posisi pertama (deleteFirst), terakhir (deleteLast), atau di tengah list (deleteAfter). Jika nomor polisi yang dimasukkan cocok dengan elemen pertama, maka deleteFirst dijalankan. Jika cocok dengan elemen terakhir, maka deleteLast dijalankan. Jika data berada di antara dua elemen, maka pointer akan melakukan traversal hingga menemukan posisi yang sesuai dan menjalankan deleteAfter. Setelah penghapusan selesai, isi list ditampilkan kembali untuk memperlihatkan perubahan yang terjadi.

Secara keseluruhan, ketiga fungsi penghapusan ini menggambarkan konsep penting dalam manajemen memori dan manipulasi pointer pada struktur Doubly Linked List. Dengan adanya pointer dua arah (next dan prev), proses penghapusan elemen menjadi lebih efisien karena tidak memerlukan traversal dari awal untuk menemukan elemen sebelumnya seperti pada singly linked list. Selain itu, fungsi-fungsi ini juga menunjukkan penerapan prinsip data integrity, di mana setiap penghapusan selalu diikuti dengan penyesuaian pointer agar tidak meninggalkan referensi yang rusak (dangling pointer).

Dengan demikian, implementasi deleteFirst, deleteLast, dan deleteAfter ini tidak hanya menunjukkan cara menghapus data dalam struktur berantai dua arah, tetapi juga memperlihatkan penerapan prinsip fundamental pemrograman terstruktur dan manajemen memori dinamis. Ketiga fungsi ini menjadi pondasi penting dalam memahami operasi deletion pada Doubly Linked List, yang merupakan bagian integral dari pembelajaran struktur data dalam konteks efisiensi algoritmik dan keamanan manipulasi pointer di dalam sistem berbasis C++.

### Output Unguided 5 :

##### Output 2
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week6/output/output-unguided3.png)



## Kesimpulan
Kesimpulan dari implementasi struktur data Doubly Linked List (DLL) yang telah dilakukan adalah bahwa struktur ini merepresentasikan evolusi penting dari konsep linked list konvensional melalui penambahan pointer dua arah (bidirectional pointer) yang memberikan fleksibilitas tinggi dalam manipulasi data. Melalui serangkaian file yang terdiri dari header file, implementation file, dan driver program, konsep DLL tidak hanya diterapkan dalam operasi dasar seperti penyisipan (insertion) dan pencetakan data (traversal), tetapi juga dikembangkan secara komprehensif dengan mengintegrasikan fitur pembaruan data (update), pencarian (searching), dan penghapusan (deletion) dalam berbagai posisi. Pendekatan ini memperlihatkan bagaimana struktur data fundamental dapat dioptimalkan untuk berbagai kebutuhan manipulasi data dinamis yang kompleks, khususnya dalam konteks pengelolaan data kendaraan dengan atribut nomor polisi, warna, dan tahun pembuatan.

Hasil analisis terhadap implementasi program menunjukkan bahwa penggunaan struktur data Doubly Linked List memberikan keunggulan signifikan dalam efisiensi pengelolaan memori dan fleksibilitas operasi data. Setiap elemen atau node dalam list terdiri dari tiga komponen utama, yaitu data payload, pointer next yang menunjuk ke node berikutnya, dan pointer prev yang menunjuk ke node sebelumnya. Struktur ini memungkinkan traversal dua arah, sehingga operasi penambahan dan penghapusan elemen dapat dilakukan tanpa perlu melakukan penelusuran ulang dari awal list seperti pada Singly Linked List. Proses penyisipan node dapat dilakukan pada berbagai posisi (awal, tengah, setelah, dan sebelum node tertentu) dengan efisiensi tinggi melalui pengaturan pointer dua arah, sedangkan penghapusan node juga dapat dilaksanakan dengan menjaga konsistensi koneksi bidireksional antar-node. Hal ini menunjukkan bahwa Doubly Linked List unggul dalam operasi yang membutuhkan perubahan struktur data secara dinamis dan akses data dari berbagai arah selama waktu eksekusi program.

Fitur update yang diimplementasikan pada program ini memperlihatkan bagaimana nilai di dalam node dapat dimodifikasi secara langsung tanpa mengubah struktur list. Fungsi updateFirst(), updateLast(), updateAfter(), dan updateBefore() memberikan fleksibilitas bagi pengguna untuk memperbarui data pada posisi tertentu dengan memanfaatkan akses dua arah yang dimiliki DLL. Sementara itu, bagian searching yang diimplementasikan melalui fungsi findElm() mendemonstrasikan kemampuan DLL dalam melakukan penelusuran data berdasarkan kriteria tertentu, dalam hal ini nomor polisi kendaraan. Penerapan fungsi pencarian ini menegaskan bahwa Doubly Linked List dapat digunakan tidak hanya untuk penyimpanan, tetapi juga untuk validasi dan pengambilan data secara selektif. Dengan pendekatan traversal linear yang dapat dilakukan dari dua arah, sistem pencarian tetap efisien terutama ketika posisi data yang dicari berada di bagian akhir list, karena penelusuran dapat dimulai dari pointer last.

Implementasi operasi deletion merupakan aspek krusial yang membedakan Doubly Linked List dari struktur data linear lainnya. Program ini mengimplementasikan tiga fungsi penghapusan utama, yaitu deleteFirst() untuk menghapus node pertama, deleteLast() untuk menghapus node terakhir, dan deleteAfter() untuk menghapus node setelah node tertentu. Ketiga fungsi ini bekerja dengan kompleksitas waktu O(1) untuk penghapusan di ujung list, karena tidak memerlukan traversal seluruh elemen. Keunggulan utama terletak pada kemampuan DLL untuk mengakses node sebelumnya secara langsung melalui pointer prev, sehingga proses penghapusan dapat dilakukan dengan efisien tanpa perlu menelusuri list dari awal untuk menemukan node predecessor. Implementasi ini juga menunjukkan penerapan prinsip data integrity yang baik, di mana setiap operasi penghapusan selalu diikuti dengan penyesuaian pointer next dan prev untuk mencegah terjadinya dangling pointer dan menjaga konsistensi struktur list.

Selain itu, program ini menerapkan mekanisme validasi data melalui fungsi isNopolExist() yang memastikan tidak terjadi duplikasi nomor polisi kendaraan dalam list. Pendekatan ini mencerminkan penerapan prinsip data consistency dan referential integrity yang umum diterapkan dalam sistem manajemen basis data, di mana setiap entitas harus memiliki identifier unik. Dengan adanya mekanisme validasi ini, struktur Doubly Linked List tidak hanya berfungsi sebagai wadah penyimpanan data pasif, melainkan juga sebagai sistem yang mampu menjaga kualitas dan integritas data secara aktif melalui pengecekan kondisi sebelum operasi insertion dilakukan.

Dari keseluruhan implementasi dan analisis yang telah dilakukan, dapat disimpulkan bahwa pemanfaatan Doubly Linked List dalam program ini berhasil menggambarkan prinsip dasar serta potensi pengembangannya dalam sistem yang lebih kompleks. Struktur data ini terbukti efektif dalam pengelolaan data dinamis dengan kemampuan traversal dua arah, efisien dalam penggunaan memori melalui alokasi dinamis, serta fleksibel untuk berbagai jenis operasi seperti penyisipan multi-posisi, pembaruan selektif, pencarian berbasis kriteria, dan penghapusan efisien. Pendekatan modular melalui pemisahan file header, implementasi, dan program utama mencerminkan penerapan konsep structured programming dan software engineering yang baik, sehingga memudahkan pemeliharaan, pembacaan, serta pengembangan kode di masa mendatang. Implementasi Doubly Linked List dalam konteks pengelolaan data kendaraan ini dapat diperluas untuk berbagai aplikasi lain, seperti sistem manajemen inventori, buffer editor teks, implementasi undo-redo mechanism, serta struktur data cache yang memanfaatkan traversal dua arah untuk optimasi pencarian dan pembaruan data dalam sistem yang lebih besar dan kompleks.


## Referensi
[1] Wijoyo, A., Farhan, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., Putra, R. T. S., & Arifin, T. (2024). Penggunaan Algoritma Doubly Linked List untuk Insertion dan Deletion. Jurnal Riset Informatika dan Inovasi (JRIIN), 1(12), 1329–1331. https://jurnalmahasiswa.com/index.php/jriin
<br>
[2] Knuth, D. E. (2011). The Art of Computer Programming, Volume 1: Fundamental Algorithms (3rd ed.). Addison-Wesley Professional.
</br>