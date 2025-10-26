# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Struktur data linked list merupakan salah satu bentuk struktur data dinamis yang digunakan untuk menyimpan kumpulan data dalam bentuk node-node yang saling terhubung melalui pointer atau referensi. Berbeda dengan array yang memiliki ukuran tetap dan alokasi memori statis, linked list bersifat fleksibel karena setiap elemen (node) dialokasikan secara dinamis di memori dan dihubungkan satu sama lain menggunakan pointer [2]. Struktur ini memungkinkan penambahan dan penghapusan data tanpa perlu menggeser elemen lain sebagaimana terjadi pada array. Dalam konteks efisiensi manajemen memori, linked list dinilai lebih adaptif terhadap perubahan ukuran data dan lebih optimal dalam pengelolaan data yang sering berubah, meskipun memiliki waktu akses yang lebih lambat karena proses traversal yang harus dilakukan secara berurutan [3].

Pada singly linked list, setiap node terdiri atas dua bagian utama: bagian pertama menyimpan data, dan bagian kedua menyimpan pointer menuju node berikutnya. Arah penelusuran hanya dapat dilakukan satu arah, yaitu dari node pertama (head) menuju node terakhir (tail) [3]. Struktur ini sederhana namun efisien untuk operasi seperti penyisipan (insertion) dan penghapusan (deletion) di bagian awal atau akhir daftar, karena kedua operasi tersebut dapat diselesaikan dengan kompleksitas waktu O(1), sementara operasi pada bagian tengah tetap membutuhkan waktu O(n) akibat proses traversal [1].

Penelitian yang dilakukan oleh Banerjee dan Kumar (2022) memperkenalkan model abstraksi baru pada struktur linked list yang mampu meningkatkan efisiensi operasi dasar seperti pushAtFront, pushAtBack, popAtFront, dan popAtBack. Dalam model ini, penggunaan dua pointer utama, yaitu head dan tail, memungkinkan operasi penyisipan dan penghapusan di awal maupun di akhir daftar dilakukan dalam waktu konstan O(1) tanpa perlu menelusuri seluruh node [1]. Pendekatan ini juga memanfaatkan pengaturan pointer ganda untuk mendukung pembuatan daftar secara efisien dengan waktu O(n), berbeda dengan pendekatan klasik yang memerlukan waktu O(n²) jika dilakukan dengan traversal berulang. Selain itu, penggunaan variabel global count sebagai penghitung jumlah node memungkinkan penghitungan ukuran linked list dilakukan secara langsung dalam O(1) [1].

Dalam konteks pencarian (searching) pada singly linked list, operasi dilakukan dengan cara traversal dari node pertama menuju node terakhir hingga elemen yang dicari ditemukan. Proses ini memiliki kompleksitas waktu O(n) karena memerlukan pengecekan setiap node satu per satu. Hasil penelitian Mbejo et al. (2025) menunjukkan bahwa performa pencarian sangat dipengaruhi oleh posisi data—semakin dekat posisi elemen dengan head, semakin cepat waktu eksekusinya. Namun, jika data berada di bagian akhir, maka waktu eksekusi meningkat secara proporsional dengan jumlah elemen dalam daftar [3]. Penelitian tersebut juga menekankan bahwa operasi pencarian dalam data dinamis seperti data mahasiswa dapat dioptimalkan dengan penambahan pointer penunjuk tail atau dengan struktur tambahan seperti indeks bantu untuk mempercepat pencarian [3].

Selain digunakan untuk operasi penyimpanan dan pencarian, singly linked list juga dapat diimplementasikan dalam operasi matematika, seperti penjumlahan atau pengurangan bilangan besar yang setiap digitnya disimpan dalam node tersendiri. Pendekatan ini memungkinkan representasi angka dengan jumlah digit yang tidak terbatas, karena tidak dibatasi oleh ukuran tipe data numerik standar. Setiap node menyimpan satu digit, dan operasi aritmetika dilakukan dengan menelusuri setiap node dari awal atau akhir tergantung jenis operasi yang dilakukan. Teknik ini memanfaatkan sifat dinamis linked list dalam mengelola data numerik berukuran besar secara efisien dibandingkan array yang bersifat statis [1].

Lebih lanjut, Wijoyo et al. (2024) menegaskan bahwa keunggulan utama linked list dibanding array terletak pada fleksibilitasnya dalam mengelola memori secara dinamis. Dalam aplikasi yang membutuhkan penambahan dan penghapusan data secara terus-menerus, linked list memberikan performa yang lebih stabil dibandingkan array karena tidak memerlukan pergeseran elemen lain selama proses modifikasi data [2]. Namun, kecepatan akses menjadi kelemahan utama karena setiap elemen harus diakses secara berurutan. Oleh karena itu, pemilihan antara linked list dan array bergantung pada kebutuhan spesifik aplikasi; untuk aplikasi dengan ukuran data tetap dan kebutuhan akses cepat, array lebih sesuai, sedangkan linked list unggul dalam aplikasi dengan perubahan data yang dinamis dan frekuensi operasi modifikasi tinggi [2].

Dalam implementasi praktis, Mbejo et al. (2025) menunjukkan bahwa penerapan singly linked list untuk pengelolaan data mahasiswa menghasilkan kinerja yang efisien dalam operasi add, search, display, dan delete pada data berjumlah 1000 elemen, dengan rata-rata waktu penyisipan sekitar 4549,2 nanodetik per data [3]. Hal ini membuktikan bahwa linked list cocok digunakan dalam sistem berskala kecil hingga menengah, terutama untuk data yang sering berubah-ubah.

Dengan demikian, dapat disimpulkan bahwa singly linked list merupakan dasar penting dalam studi struktur data karena fleksibilitas dan efisiensinya dalam pengelolaan data dinamis. Perkembangan model algoritmik seperti yang dikemukakan oleh Banerjee et al. [1] menunjukkan potensi besar dalam mempercepat operasi dasar, sementara studi eksperimental seperti yang dilakukan oleh Mbejo et al. [3] memperlihatkan penerapannya dalam konteks dunia nyata. Kombinasi dari teori kompleksitas dan penerapan praktis ini menjadikan singly linked list sebagai fondasi utama dalam pemrograman dan pengembangan sistem informasi berbasis struktur data dinamis.

## Guided 

### 1.1 listBuah.h

```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### 1.2 listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 1.3 main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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

Ketiga file program yang terdiri dari listBuah.h, listBuah.cpp, dan main.cpp merupakan satu kesatuan implementasi dari konsep singly linked list dalam bahasa pemrograman C++. Program ini dirancang untuk memodelkan pengelolaan data buah, yang mencakup operasi dasar seperti penyisipan, penghapusan, pembaruan, pencarian, dan penghapusan keseluruhan data dalam sebuah struktur data berantai tunggal. Pendekatan ini menggambarkan bagaimana konsep teoretis linked list dapat diterapkan secara praktis dalam pengelolaan data dinamis menggunakan pendekatan berorientasi struktur.

file listBuah.h berfungsi sebagai header file yang berisi definisi struktur data, deklarasi tipe, dan prototipe fungsi yang digunakan dalam program. Pada bagian awal, terdapat header guard dengan makro #ifndef LISTBUAH_H, #define LISTBUAH_H, dan #endif yang bertujuan untuk mencegah file header di-include lebih dari satu kali dalam satu program. Selanjutnya, struktur buah didefinisikan sebagai entitas dasar yang menyimpan informasi mengenai nama, jumlah, dan harga buah. Struktur ini kemudian diberi alias dataBuah untuk memudahkan penggunaannya dalam kode utama. Setelah itu, didefinisikan struktur node, yang merupakan representasi satu elemen dalam linked list. Setiap node berisi data bertipe dataBuah dan satu pointer next yang menunjuk ke node berikutnya. Struktur linkedlist menjadi wadah utama yang hanya menyimpan satu pointer first, yang menunjuk ke node pertama dari daftar. file ini juga mendeklarasikan seluruh fungsi yang diimplementasikan dalam listBuah.cpp, mulai dari operasi dasar seperti pembuatan list, pengecekan kekosongan, alokasi dan dealokasi node, hingga fungsi yang lebih kompleks seperti pembaruan data (update), pencarian node berdasarkan kriteria tertentu, serta operasi penghapusan list secara keseluruhan.

Implementasi dari seluruh fungsi tersebut terdapat dalam file listBuah.cpp. file ini memuat logika utama pengelolaan linked list dan menerapkan prinsip manajemen memori dinamis menggunakan operator new dan delete. Fungsi isEmpty() digunakan untuk memeriksa apakah list dalam keadaan kosong dengan cara mengecek apakah pointer first bernilai Nil atau tidak. Fungsi createList() menginisialisasi linked list baru dengan mengatur first agar bernilai Nil, menandakan bahwa belum ada data yang tersimpan. Prosedur alokasi() bertugas membuat node baru di memori, mengisi nilai-nilai atributnya, dan mengembalikan alamat node tersebut. Sebaliknya, dealokasi() digunakan untuk menghapus node dari memori heap agar tidak terjadi kebocoran memori.

Operasi penyisipan node terbagi menjadi tiga jenis, yaitu insertFirst(), insertAfter(), dan insertLast(). Ketiganya menggambarkan perbedaan posisi penempatan node baru, baik di awal, di tengah setelah node tertentu, maupun di akhir list. Prosedur ini memanfaatkan manipulasi pointer untuk menghubungkan node baru tanpa perlu melakukan pergeseran elemen sebagaimana terjadi pada struktur data array. Sementara itu, operasi penghapusan mencakup delFirst(), delLast(), dan delAfter(), yang bertugas menghapus node dari posisi tertentu di dalam list dengan memperbarui relasi pointer antar node.

Selanjutnya, prosedur printList() digunakan untuk menampilkan seluruh isi list secara berurutan dari node pertama hingga node terakhir, sementara fungsi nbList() menghitung jumlah node dalam list dengan cara menelusuri setiap elemen hingga menemukan pointer Nil. Prosedur deleteList() berfungsi untuk menghapus seluruh node dalam list sekaligus, mengembalikan kondisi list ke keadaan awal yang kosong.

Bagian berikutnya dari listBuah.cpp memuat materi lanjutan yang berkaitan dengan operasi update dan searching pada singly linked list. Fungsi updateFirst(), updateLast(), dan updateAfter() memberikan kemampuan untuk memperbarui data pada node pertama, node terakhir, maupun node setelah node tertentu. Ketiga fungsi ini memperlihatkan fleksibilitas linked list dalam memodifikasi data tanpa perlu mengubah keseluruhan struktur. Pada bagian pencarian, terdapat tiga metode yaitu FindNodeByData(), FindNodeByAddress(), dan FindNodeByRange(). Ketiganya menunjukkan berbagai pendekatan dalam melakukan searching, baik berdasarkan nilai data yang tersimpan, alamat node dalam memori, maupun berdasarkan rentang nilai harga buah. Setiap pencarian dilakukan melalui traversal linear dari node pertama hingga akhir dengan kompleksitas waktu O(n), yang merupakan karakteristik khas dari singly linked list.

file main.cpp berfungsi sebagai driver program yang menjalankan seluruh fungsi yang telah didefinisikan dalam kedua file sebelumnya. Di dalamnya, dibuat beberapa node buah seperti “Jeruk”, “Apel”, “Pir”, “Semangka”, dan “Durian” dengan atribut jumlah dan harga yang berbeda. Node-node ini dialokasikan secara dinamis dan kemudian disisipkan ke dalam linked list melalui kombinasi operasi insertFirst, insertAfter, dan insertLast, yang menunjukkan kemampuan linked list untuk menerima data di berbagai posisi tanpa memerlukan penataan ulang elemen lain. Setelah proses penyisipan, program mencetak isi list untuk menampilkan hasilnya serta jumlah total node yang tersimpan.

Tahapan selanjutnya menampilkan implementasi operasi update untuk memperbarui data pada node pertama, node terakhir, dan node setelah node tertentu. Setelah pembaruan selesai, isi list kembali dicetak untuk menunjukkan perubahan data secara langsung. Selanjutnya, dilakukan operasi pencarian data melalui tiga metode yang berbeda, yaitu pencarian berdasarkan nama buah, alamat node, serta range harga. Tahap akhir dari program memperlihatkan implementasi operasi penghapusan node dari berbagai posisi dan diakhiri dengan prosedur deleteList() yang menghapus seluruh isi list secara menyeluruh.

Secara keseluruhan, ketiga file ini menunjukkan implementasi terstruktur dari konsep singly linked list dengan penerapan operasi fundamental dan lanjutan yang lengkap. Program ini tidak hanya menampilkan efisiensi dalam pengelolaan data dinamis, tetapi juga mencerminkan penerapan prinsip-prinsip dasar struktur data seperti alokasi memori dinamis, traversal, serta manipulasi pointer. Pendekatan yang digunakan menggambarkan bahwa linked list merupakan struktur data yang fleksibel dan efisien untuk aplikasi yang memerlukan penambahan, penghapusan, dan pembaruan data secara berulang, tanpa perlu alokasi ulang seluruh elemen seperti pada array.



## Unguided 

### Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h”. Kemudian buatlah implementasi function & procedure tersebut pada file “listAngka.cpp”. Kemudian lakukan hal berikut pada file “main.cpp” sehingga memberikan output sesuai contoh.

#### ListAngka.h

```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka; //Memberikan nama alias dataAngka untuk struct angka.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataAngka isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 5
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int angka);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

##### ListAngka.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(int angka) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
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
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}
```

##### main.cpp
```C++
#include "ListAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);

    return 0;
}
```

Ketiga file program yang terdiri atas ListAngka.h, ListAngka.cpp, dan main.cpp merupakan implementasi terstruktur dari konsep singly linked list dalam bahasa pemrograman C++. Program ini difokuskan pada pengelolaan kumpulan data numerik secara dinamis, dengan tujuan memperlihatkan bagaimana konsep dasar linked list dapat diimplementasikan dalam operasi-operasi manipulasi data seperti penyisipan, penghapusan, serta penelusuran data. Struktur kode ini menggambarkan pendekatan modular yang baik, di mana setiap file memiliki tanggung jawab tersendiri untuk mendukung prinsip pemrograman terpisah antara definisi, implementasi, dan eksekusi utama.

file ListAngka.h berfungsi sebagai header file yang mendefinisikan struktur data, tipe data baru, serta deklarasi fungsi dan prosedur yang digunakan di seluruh program. Pada bagian awal, terdapat penggunaan header guard dengan direktif #ifndef, #define, dan #endif, yang bertujuan untuk mencegah duplikasi ketika file ini di-include lebih dari satu kali di dalam program utama. Struktur data utama yang digunakan adalah struct angka, yang hanya menyimpan satu variabel bertipe integer bernama num. Struktur ini kemudian diberi alias dataAngka untuk mempermudah referensi dalam implementasi selanjutnya. Kemudian, didefinisikan struktur node yang berperan sebagai elemen tunggal dari linked list. Setiap node memiliki dua komponen utama, yaitu isidata yang berisi data bertipe dataAngka dan next yang merupakan pointer menuju node berikutnya. Sementara itu, struktur linkedlist menjadi representasi daftar berantai yang menyimpan satu pointer first sebagai penunjuk node pertama. Seluruh fungsi yang digunakan untuk mengelola linked list, seperti alokasi memori, insert, delete, dan print, dideklarasikan dalam file ini agar dapat digunakan oleh file implementasi (source file).

file ListAngka.cpp merupakan file implementasi yang memuat seluruh definisi fungsi yang telah dideklarasikan pada header file. Implementasi diawali dengan fungsi isEmpty(), yang berfungsi untuk memeriksa apakah linked list dalam keadaan kosong dengan mengembalikan nilai boolean berdasarkan kondisi pointer first. Fungsi createList() bertanggung jawab untuk menginisialisasi sebuah linked list kosong dengan mengatur pointer first agar bernilai Nil, menandakan bahwa list belum memiliki elemen. Prosedur alokasi() digunakan untuk menciptakan node baru di memori dengan operator new. Setiap node yang dibuat akan diisi dengan data numerik yang diberikan dan diatur agar pointer next-nya bernilai Nil, menandakan akhir dari list. Sebaliknya, fungsi dealokasi() digunakan untuk menghapus node dari memori heap agar tidak terjadi kebocoran memori (memory leak) setelah sebuah node tidak lagi digunakan.

Pada bagian operasi manipulasi data, prosedur insertFirst(), insertAfter(), dan insertLast() bertugas untuk menambahkan node baru ke dalam linked list pada posisi tertentu. insertFirst() menambahkan node baru di awal list dengan cara menghubungkan node baru ke node pertama yang sudah ada dan menjadikannya node pertama yang baru. Prosedur insertAfter() memungkinkan penyisipan node setelah node tertentu yang telah diketahui posisinya, sedangkan insertLast() berfungsi menambahkan node di bagian akhir list dengan melakukan penelusuran dari awal hingga menemukan node terakhir yang pointer next-nya bernilai Nil. Ketiga prosedur ini menggambarkan fleksibilitas linked list dalam menambahkan elemen baru tanpa perlu melakukan pergeseran elemen lain, seperti yang harus dilakukan pada struktur array konvensional.

Selain penyisipan, program juga menyediakan prosedur delAfter() untuk menghapus node setelah node tertentu. Operasi ini dilakukan dengan memeriksa apakah list dalam keadaan kosong dan apakah node sebelumnya (previous node) valid. Jika valid, pointer next dari node sebelumnya akan diarahkan ke node setelah node yang akan dihapus, kemudian node yang dihapus akan di-dealokasi dari memori. Dengan demikian, struktur rantai list tetap terjaga tanpa terputus. Prosedur printList() digunakan untuk menampilkan seluruh isi list secara berurutan mulai dari node pertama hingga node terakhir, dengan menampilkan setiap nilai angka yang tersimpan dalam list. Fungsi nbList() digunakan untuk menghitung jumlah elemen dalam linked list dengan menelusuri seluruh node hingga mencapai node terakhir. Fungsi-fungsi ini menunjukkan prinsip dasar dari traversal data pada linked list yang bersifat linear dengan kompleksitas waktu O(n), di mana setiap elemen harus diakses satu per satu.

file main.cpp berperan sebagai driver program yang menjalankan seluruh prosedur dan fungsi yang telah didefinisikan dalam dua file sebelumnya. Program dimulai dengan pembuatan sebuah linked list kosong menggunakan fungsi createList(), kemudian dilakukan alokasi beberapa node yang berisi data bilangan bulat seperti 8, 13, 18, 25, 33, dan 40. Setiap node disisipkan ke dalam list menggunakan kombinasi dari operasi insertFirst(), insertAfter(), dan insertLast(), yang masing-masing menggambarkan penyisipan data di awal, tengah, dan akhir list. Setelah proses penyisipan selesai, dilakukan operasi delAfter() untuk menghapus node tertentu setelah node yang ditentukan. Proses ini memperlihatkan bagaimana manipulasi pointer memungkinkan penghapusan elemen secara efisien tanpa harus melakukan pergeseran data secara fisik di memori. Setelah proses penghapusan selesai, isi list ditampilkan melalui prosedur printList() untuk menunjukkan hasil akhir dari operasi yang dilakukan.

Secara keseluruhan, ketiga file ini menunjukkan implementasi konsep fundamental singly linked list dengan penerapan prinsip-prinsip manajemen memori dinamis dan manipulasi pointer secara langsung. Melalui kombinasi dari operasi penyisipan, penghapusan, dan penelusuran, program ini membuktikan fleksibilitas linked list dalam mengelola data yang bersifat dinamis tanpa perlu melakukan alokasi ulang atau pergeseran elemen. Pendekatan modular dengan pemisahan antara header file, source file, dan driver program juga menunjukkan praktik pemrograman yang baik dan terstruktur, sesuai dengan prinsip software engineering. Implementasi seperti ini menjadi dasar penting dalam memahami struktur data dinamis dan menjadi landasan bagi pengembangan struktur data yang lebih kompleks seperti doubly linked list, circular linked list, dan berbagai variasi lainnya dalam bidang rekayasa perangkat lunak.

### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week5/output/output-unguided.png)


### 1. Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian sebagai berikut:
### Procedure updateFirst ( input / output L : List )
### Procedure updateLast ( input / output L : List )
### Procedure updateAfter ( input / output L : List, input nodePrev : address )
### Kemudian pada "main.cpp" lakukanlah :
### Update data 40 menjadi 50
### Update data 8 menjadi 29
### Update data 33 menjadi 45
### Update data 18 menjadi 20
### Tampilkan seluruh list setelah diupdate

#### ListAngka.h
```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka; //Memberikan nama alias dataAngka untuk struct angka.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataAngka isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 5
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int angka);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```

##### ListAngka.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(int angka) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
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
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.num << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.num;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

##### main.cpp
```C++
#include "ListAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);

    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    printList(List);

    cout << endl;
    
    return 0;
}
```

Ketiga file kode program yang terdiri atas ListAngka.h, ListAngka.cpp, dan main.cpp merupakan implementasi komprehensif dari struktur data singly linked list menggunakan bahasa pemrograman C++. Program ini dirancang untuk memanipulasi kumpulan data numerik secara dinamis dengan menerapkan prinsip-prinsip dasar struktur data berantai tunggal, seperti penyisipan, penghapusan, pembaruan, dan penelusuran data. Melalui pemisahan antara file header, file implementasi, dan file utama, program ini menunjukkan penerapan prinsip modular programming yang baik, di mana setiap komponen memiliki tanggung jawab yang terpisah namun saling melengkapi untuk membentuk sistem yang utuh.

file ListAngka.h berfungsi sebagai header file yang mendefinisikan struktur data dan mendeklarasikan seluruh fungsi serta prosedur yang digunakan dalam program. Pada bagian awal file, terdapat penggunaan header guard dengan direktif #ifndef, #define, dan #endif, yang berguna untuk mencegah terjadinya duplikasi pemanggilan header saat file di-include lebih dari satu kali di berbagai bagian program. Struktur utama yang didefinisikan adalah struct angka, yang berisi satu elemen data bertipe int bernama num. Struktur ini diberi alias dataAngka untuk mempermudah penggunaannya dalam definisi node. Selanjutnya, dideklarasikan struct node, yang berperan sebagai elemen dasar dari linked list. Setiap node terdiri dari dua bagian: bagian pertama menyimpan data bertipe dataAngka, dan bagian kedua adalah pointer next yang menunjuk ke node berikutnya. Struktur linkedlist kemudian digunakan sebagai wadah utama yang menyimpan satu pointer first, yaitu pointer yang menunjuk ke node pertama dalam daftar.

Dalam file ini juga tercantum deklarasi fungsi-fungsi penting seperti isEmpty(), createList(), alokasi(), dealokasi(), printList(), insertFirst(), insertAfter(), insertLast(), delAfter(), nbList(), dan deleteList(). Selain itu, terdapat pula tiga prosedur tambahan — updateFirst(), updateLast(), dan updateAfter() — yang termasuk dalam materi lanjutan untuk memperbarui isi data dari node tertentu. Dengan adanya deklarasi ini, file header bertindak sebagai antarmuka (interface) antara definisi struktur data dan implementasi logika program di file berikutnya.

file ListAngka.cpp berperan sebagai source file yang berisi implementasi lengkap dari seluruh fungsi dan prosedur yang telah dideklarasikan sebelumnya. Implementasi dimulai dengan fungsi isEmpty(), yang digunakan untuk memeriksa apakah linked list kosong atau tidak dengan mengembalikan nilai true jika pointer first bernilai Nil. Fungsi createList() berfungsi untuk menginisialisasi linked list baru dengan cara mengatur pointer first agar bernilai Nil, menandakan bahwa list belum memiliki elemen. Prosedur alokasi() bertugas untuk menciptakan node baru di memori secara dinamis menggunakan operator new. Node yang terbentuk akan diisi dengan nilai integer yang diberikan oleh pengguna dan diatur agar pointer next-nya menunjuk ke Nil. Sebaliknya, prosedur dealokasi() berfungsi menghapus node dari memori heap untuk mencegah kebocoran memori, dengan menghapus hubungan pointer sebelum node dihapus.

Operasi penyisipan data dilakukan melalui tiga prosedur utama, yaitu insertFirst(), insertAfter(), dan insertLast(). Prosedur insertFirst() menempatkan node baru di posisi awal dengan cara menghubungkannya ke node pertama yang sudah ada. Prosedur insertAfter() digunakan untuk menyisipkan node baru setelah node tertentu yang telah diketahui posisinya, sedangkan insertLast() menambahkan node di akhir list dengan menelusuri setiap node hingga menemukan node terakhir yang pointer next-nya bernilai Nil. Seluruh prosedur penyisipan ini menunjukkan bagaimana linked list dapat menambahkan data baru tanpa perlu melakukan pergeseran elemen seperti pada struktur array.

Selain penyisipan, terdapat prosedur delAfter() yang berfungsi untuk menghapus node setelah node tertentu. Prosedur ini bekerja dengan memeriksa kondisi kekosongan list dan kevalidan pointer nodePrev. Jika valid, pointer next dari node sebelumnya akan diarahkan ke node setelah node yang akan dihapus, dan node yang dihapus akan di-dealokasi untuk melepaskan memori yang digunakan. Prosedur printList() digunakan untuk menampilkan isi list secara berurutan dari node pertama hingga node terakhir. Fungsi nbList() digunakan untuk menghitung jumlah node dalam list dengan cara melakukan traversal dari awal hingga akhir.

Selain operasi dasar, file ListAngka.cpp juga memuat implementasi tiga prosedur tambahan untuk memperbarui nilai data pada node, yaitu updateFirst(), updateLast(), dan updateAfter(). Ketiga prosedur ini menunjukkan bagaimana linked list dapat dimodifikasi secara langsung tanpa mengubah struktur hubungannya. updateFirst() digunakan untuk memperbarui nilai node pertama, updateLast() memperbarui nilai node terakhir dengan cara melakukan traversal hingga akhir list, sedangkan updateAfter() digunakan untuk memperbarui node setelah node tertentu yang diberikan. Ketiga prosedur ini menunjukkan fleksibilitas linked list dalam menangani perubahan data secara efisien, dengan waktu eksekusi yang bergantung pada posisi node yang diubah.

file main.cpp berfungsi sebagai driver program yang mengimplementasikan seluruh fungsi dan prosedur yang telah didefinisikan pada dua file sebelumnya. Program dimulai dengan pembuatan sebuah linked list kosong melalui pemanggilan createList(). Selanjutnya, dibuat enam node baru yang masing-masing menyimpan data numerik 8, 13, 18, 25, 33, dan 40 menggunakan fungsi alokasi(). Node-node ini kemudian dimasukkan ke dalam list menggunakan kombinasi operasi penyisipan: insertFirst(), insertAfter(), dan insertLast(). Kombinasi ini memperlihatkan kemampuan linked list untuk menempatkan elemen di berbagai posisi tanpa memerlukan pemindahan data secara keseluruhan. Setelah semua node berhasil dimasukkan, prosedur delAfter() digunakan untuk menghapus node tertentu setelah node yang ditentukan.

Setelah operasi penyisipan dan penghapusan selesai dilakukan, program menampilkan isi list melalui printList(), yang menelusuri setiap node dan mencetak nilainya secara berurutan. Selanjutnya, dilakukan serangkaian operasi pembaruan data menggunakan fungsi updateFirst(), updateAfter(), dan updateLast(). Proses ini memungkinkan pengguna untuk mengubah nilai pada node tertentu secara interaktif melalui input dari console. Setelah seluruh pembaruan dilakukan, isi list kembali ditampilkan untuk memperlihatkan hasil akhir dari operasi yang dilakukan.

Secara keseluruhan, ketiga file ini membentuk satu sistem terpadu yang merepresentasikan konsep singly linked list dalam bentuk implementasi praktis. File header mendefinisikan struktur dan fungsi, file implementasi mengatur logika operasional, dan file utama menjadi pusat eksekusi program. Implementasi ini menunjukkan fleksibilitas linked list dalam mengelola data numerik secara dinamis tanpa batasan ukuran tetap seperti pada array. Selain itu, program ini juga memperlihatkan penerapan prinsip manajemen memori yang efisien, penggunaan pointer untuk penghubung antar data, serta kemampuan pembaruan dan penghapusan data secara langsung. Dengan demikian, program ini tidak hanya menjadi contoh penerapan dasar struktur data dinamis, tetapi juga mencerminkan pentingnya modularitas dan efisiensi dalam perancangan perangkat lunak berbasis struktur data.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week5/output/output-unguided1.png)


### 2. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan rincian sebagai berikut :
### Procedure SearchByData( input L : List, input data : integer )
### Procedure SearchByAddress( input L : List, input node : address )
### Procedure SearchByRange( input L : List, input nilaiMin : integer )
### Kemudian pada “main.cpp” lakukanlah :
### Mencari data nilai 20
### Mencari data nilai 55
### Mencari data alamat nodeB
### Mencari data alamat nodeA
### Mencari data dengan nilai minimal 40

#### ListAngka.h
```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka; //Memberikan nama alias dataAngka untuk struct angka.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataAngka isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 5
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int angka);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void SearchNodeByData(linkedlist list, int data);
void SearchNodeByAddress(linkedlist list, address node);
void SearchNodeByMinValue(linkedlist list, int nilaiMin);

#endif
```

##### ListAngka.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(int angka) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
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
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.num << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.num;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void SearchNodeByData(linkedlist list, int data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.num == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void SearchNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node dengan alamat " << node << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan minimum nilai
void SearchNodeByMinValue(linkedlist list, int nilaiMin) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float nilai = nodeBantu->isidata.num;
            if(nilai >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nilai << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data diatas nilai tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

##### main.cpp
```C++
#include "ListAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);

    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    printList(List);

    cout << endl;

    SearchNodeByData(List, 20);
    SearchNodeByData(List, 55);
    SearchNodeByAddress(List, nodeA);
    SearchNodeByAddress(List, nodeB);
    SearchNodeByMinValue(List, 40);

    return 0;
}
```

Ketiga file kode program yang terdiri atas ListAngka.h, ListAngka.cpp, dan main.cpp merupakan implementasi terstruktur dari konsep singly linked list menggunakan bahasa pemrograman C++. Program ini dirancang untuk mengelola kumpulan data numerik secara dinamis dengan menerapkan operasi dasar seperti penyisipan, penghapusan, pembaruan, dan pencarian data. Melalui pembagian kode ke dalam tiga file terpisah, program ini mencerminkan prinsip modular programming yang menekankan pemisahan tanggung jawab antara definisi struktur data, implementasi logika, dan pelaksanaan program utama, sehingga kode menjadi lebih mudah dipahami, diuji, serta dikembangkan.

file ListAngka.h berfungsi sebagai header file yang berisi deklarasi struktur data dan prototipe fungsi yang digunakan di seluruh program. Pada bagian awal, terdapat header guard menggunakan direktif #ifndef, #define, dan #endif yang berperan penting dalam mencegah terjadinya duplikasi saat file di-include lebih dari satu kali dalam program. Struktur data utama yang digunakan adalah struct angka, yang menyimpan satu atribut bertipe int bernama num. Struktur ini kemudian diberi alias dataAngka untuk memudahkan referensi pada bagian lain dari program. Selanjutnya, didefinisikan struktur node yang menjadi komponen dasar dari linked list, terdiri atas dua bagian: isidata, yang berisi data bertipe dataAngka, dan next, yaitu pointer yang menunjuk ke node berikutnya. Sementara itu, struct linkedlist menjadi struktur pengendali utama yang menyimpan satu pointer first sebagai penunjuk ke node pertama dalam daftar.

Dalam file ini, juga terdapat deklarasi seluruh fungsi dan prosedur yang digunakan dalam program, yang mencakup operasi dasar seperti isEmpty(), createList(), alokasi(), dealokasi(), serta berbagai operasi manipulasi node seperti insertFirst(), insertAfter(), insertLast(), delAfter(), nbList(), dan deleteList(). Selain itu, terdapat pula bagian khusus yang ditandai sebagai “materi modul 5”, yang memuat fungsi-fungsi lanjutan seperti updateFirst(), updateLast(), dan updateAfter() untuk memperbarui isi node, serta SearchNodeByData(), SearchNodeByAddress(), dan SearchNodeByMinValue() untuk melakukan pencarian berdasarkan kriteria tertentu. Keberadaan fungsi-fungsi ini menunjukkan perluasan kemampuan linked list, tidak hanya untuk menyimpan data secara dinamis, tetapi juga untuk melakukan pengolahan data yang lebih kompleks.

file ListAngka.cpp merupakan source file yang berisi implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan dalam header. Implementasi dimulai dengan fungsi isEmpty() yang digunakan untuk memeriksa kondisi kekosongan linked list dengan mengembalikan nilai true jika pointer first bernilai Nil. Fungsi createList() bertugas menginisialisasi list baru dengan mengatur pointer first menjadi Nil, menandakan bahwa list belum memiliki elemen. Prosedur alokasi() digunakan untuk membuat node baru di memori heap menggunakan operator new. Node baru yang dibuat akan diisi dengan data numerik yang diberikan, dan pointer next diatur agar bernilai Nil. Sebaliknya, prosedur dealokasi() digunakan untuk menghapus node dari memori heap guna menghindari kebocoran memori, dengan menghapus koneksi pointer terlebih dahulu sebelum menghapus node.

Bagian berikutnya dari file ini berisi implementasi operasi penyisipan (insertion) dan penghapusan (deletion) node. Prosedur insertFirst() menambahkan node baru di bagian awal list dengan menghubungkannya ke node pertama yang sudah ada. Prosedur insertAfter() digunakan untuk menambahkan node setelah node tertentu yang sudah diketahui posisinya, sedangkan insertLast() menambahkan node di bagian akhir dengan cara menelusuri seluruh node hingga menemukan node terakhir yang pointer next-nya bernilai Nil. Ketiga prosedur ini memperlihatkan efisiensi linked list dalam menambah elemen tanpa harus menggeser elemen lain sebagaimana terjadi pada array. Prosedur delAfter() berfungsi untuk menghapus node setelah node tertentu dengan cara mengubah arah pointer dari node sebelumnya agar melewati node yang akan dihapus, kemudian node yang dihapus di-dealokasi dari memori.

Selain operasi dasar, file ini juga mengandung implementasi operasi update dan searching. Pada bagian update, terdapat tiga prosedur yaitu updateFirst(), updateLast(), dan updateAfter(). Ketiganya berfungsi untuk memperbarui nilai data pada node pertama, node terakhir, dan node setelah node tertentu. Prosedur-prosedur ini menunjukkan bagaimana linked list dapat dimodifikasi secara langsung tanpa mengubah struktur hubungan antar node. Selanjutnya, bagian searching mencakup tiga metode pencarian berbeda. Prosedur SearchNodeByData() mencari node berdasarkan nilai data yang disimpan, dengan melakukan traversal linear dari node pertama hingga node terakhir. Prosedur SearchNodeByAddress() mencari node berdasarkan alamat memorinya, yang bermanfaat dalam konteks debugging atau validasi data. Terakhir, SearchNodeByMinValue() digunakan untuk menampilkan seluruh node yang memiliki nilai lebih besar atau sama dengan batas minimum yang diberikan. Ketiga metode pencarian ini memiliki kompleksitas waktu O(n), sesuai dengan karakteristik traversal linear pada struktur singly linked list.

file main.cpp berperan sebagai driver program yang menjalankan seluruh operasi yang telah didefinisikan pada dua file sebelumnya. Program dimulai dengan pembuatan sebuah linked list kosong menggunakan fungsi createList(), kemudian dilanjutkan dengan pembuatan enam node baru menggunakan fungsi alokasi() dengan nilai data 8, 13, 18, 25, 33, dan 40. Node-node ini dimasukkan ke dalam list melalui kombinasi operasi insertFirst(), insertAfter(), dan insertLast(), yang menunjukkan kemampuan linked list dalam menambahkan elemen di berbagai posisi. Setelah itu, prosedur delAfter() digunakan untuk menghapus node tertentu dari list, memperlihatkan bagaimana penghapusan data dapat dilakukan secara efisien tanpa perlu pergeseran elemen lain. Selanjutnya, isi list ditampilkan melalui printList() untuk memperlihatkan hasil operasi penyisipan dan penghapusan.

Tahapan berikutnya menampilkan penggunaan fungsi update untuk memperbarui isi data pada node pertama, node terakhir, serta node setelah node tertentu. Pengguna dapat memberikan input baru secara langsung melalui terminal, dan hasil pembaruan tersebut ditampilkan kembali menggunakan printList(). Setelah proses pembaruan selesai, bagian akhir program memperlihatkan implementasi operasi pencarian menggunakan ketiga prosedur searching yang telah dijelaskan sebelumnya. Pencarian dilakukan berdasarkan nilai data (SearchNodeByData()), alamat node (SearchNodeByAddress()), dan nilai minimum (SearchNodeByMinValue()), sehingga memperlihatkan variasi metode akses data dalam linked list.

Secara keseluruhan, ketiga file ini menggambarkan implementasi lengkap dari konsep singly linked list dalam pengelolaan data numerik secara dinamis. File header mendefinisikan struktur data dan fungsi, file implementasi memuat logika operasional, dan file utama menjadi pusat eksekusi yang mengintegrasikan seluruh komponen. Program ini menunjukkan bagaimana linked list dapat digunakan untuk operasi penyisipan, penghapusan, pembaruan, dan pencarian data dengan efisien tanpa memerlukan alokasi ulang atau pergeseran elemen. Selain itu, program ini juga merepresentasikan penerapan prinsip manajemen memori dinamis dan manipulasi pointer yang menjadi dasar penting dalam pemahaman struktur data dan algoritma. Pendekatan modular yang digunakan menjadikan program ini tidak hanya efektif dari sisi fungsional, tetapi juga memenuhi prinsip rekayasa perangkat lunak dalam hal keterbacaan, pemeliharaan, dan perluasan di masa mendatang.

### Output Unguided 5 :

##### Output 2
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week5/output/output-unguided2.png)



### 3. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.

#### ListAngka.h
```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka; //Memberikan nama alias dataAngka untuk struct angka.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataAngka isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 5
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int angka);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void SearchNodeByData(linkedlist list, int data);
void SearchNodeByAddress(linkedlist list, address node);
void SearchNodeByMinValue(linkedlist list, int nilaiMin);

//operasi aritmetika
int penjumlahan(linkedlist List);
int pengurangan(linkedlist List);
int perkalian(linkedlist List);

#endif
```

##### ListAngka.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(int angka) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
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
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.num << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.num;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void SearchNodeByData(linkedlist list, int data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.num == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void SearchNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node dengan alamat " << node << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan minimum nilai
void SearchNodeByMinValue(linkedlist list, int nilaiMin) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float nilai = nodeBantu->isidata.num;
            if(nilai >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nilai << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data diatas nilai tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

int penjumlahan(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        int total = 0;
        address p = List.first;
        while (p != Nil) {
            total = total + p->isidata.num;
            p = p->next;
        }
        return total;
    }
}

int pengurangan(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        address p = List.first;
        int total = 0;
        while (p != Nil) {
            total += p->isidata.num;
            p = p->next;
        }
        p = List.first;
        int hasil = p->isidata.num - total;

        return hasil;
    }
}


int perkalian(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        int total = 1;
        address p = List.first;
        while (p != Nil) {
            total = total * p->isidata.num;
            p = p->next;
        }
        return total;
    }
}
```

##### main.cpp
```C++
#include "ListAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);

    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    printList(List);

    cout << endl;

    SearchNodeByData(List, 20);
    SearchNodeByData(List, 55);
    SearchNodeByAddress(List, nodeA);
    SearchNodeByAddress(List, nodeB);
    SearchNodeByMinValue(List, 40);

    cout << "Total Penjumlahan : " << penjumlahan(List) << endl;
    cout << "Total Pengurangan : " << pengurangan(List) << endl;
    cout << "Total Perkalian : " << perkalian(List) << endl;
    
    return 0;
}
```
ChatGPT said:

Ketiga file kode program yang terdiri dari ListAngka.h, ListAngka.cpp, dan main.cpp merupakan implementasi lengkap dari struktur data singly linked list dalam bahasa pemrograman C++, yang digunakan untuk memanipulasi kumpulan data numerik secara dinamis. Program ini tidak hanya menampilkan operasi dasar seperti penyisipan dan penghapusan data, tetapi juga mengimplementasikan pembaruan (update), pencarian (searching), serta operasi aritmetika seperti penjumlahan, pengurangan, dan perkalian terhadap elemen-elemen yang tersimpan di dalam list. Melalui pembagian kode ke dalam tiga file, program ini memperlihatkan penerapan prinsip modular programming yang mengutamakan keteraturan, keterbacaan, serta kemudahan dalam pengembangan kode.

file ListAngka.h berfungsi sebagai header file yang mendefinisikan struktur data, tipe data, serta mendeklarasikan seluruh fungsi dan prosedur yang digunakan dalam program. Pada bagian awal, terdapat penggunaan header guard dengan direktif #ifndef, #define, dan #endif yang berfungsi untuk mencegah file header di-include lebih dari sekali dalam satu program. Struktur utama yang digunakan adalah struct angka, yang berisi satu atribut bertipe integer bernama num untuk menyimpan nilai numerik setiap node. Struktur ini diberi alias dataAngka guna mempermudah pemanggilan pada bagian implementasi. Kemudian, didefinisikan struct node yang menjadi representasi satu elemen dari linked list, terdiri atas dua bagian utama: isidata, yang berisi data bertipe dataAngka, dan next, yaitu pointer yang menunjuk ke node berikutnya dalam daftar. Struktur linkedlist bertugas menyimpan satu pointer first, yang menunjuk ke node pertama dalam list dan menjadi titik awal setiap operasi traversal.

File ini juga mendeklarasikan seluruh fungsi yang akan digunakan, termasuk operasi dasar seperti isEmpty(), createList(), alokasi(), dealokasi(), insertFirst(), insertAfter(), insertLast(), dan delAfter(), serta operasi pendukung seperti nbList() dan deleteList() untuk menghitung jumlah node dan menghapus seluruh list. Selain operasi dasar tersebut, terdapat juga bagian khusus yang dikelompokkan berdasarkan materi modul pembelajaran, yaitu operasi update dan searching. Fungsi updateFirst(), updateLast(), dan updateAfter() digunakan untuk memperbarui nilai data pada node pertama, node terakhir, atau node setelah node tertentu. Di sisi lain, fungsi pencarian (SearchNodeByData(), SearchNodeByAddress(), dan SearchNodeByMinValue()) memungkinkan pengguna melakukan pencarian data berdasarkan nilai, alamat memori, atau nilai minimum tertentu. Tambahan paling signifikan dalam file ini adalah deklarasi tiga fungsi aritmetika — penjumlahan(), pengurangan(), dan perkalian() — yang menunjukkan perluasan konsep linked list ke arah pemrosesan numerik.

file ListAngka.cpp merupakan implementasi dari seluruh fungsi yang telah dideklarasikan dalam header file. Implementasi dimulai dengan fungsi isEmpty(), yang digunakan untuk memeriksa apakah list kosong dengan cara mengecek nilai pointer first. Fungsi createList() berfungsi menginisialisasi linked list kosong dengan menetapkan nilai awal pointer first menjadi Nil. Prosedur alokasi() bertugas membuat node baru di memori heap menggunakan operator new, mengisi nilainya dengan data yang diberikan, dan menetapkan pointer next ke Nil, menandakan akhir dari list. Sebaliknya, prosedur dealokasi() digunakan untuk menghapus node yang tidak lagi digunakan dan mengembalikan memorinya ke sistem.

Operasi penyisipan node diimplementasikan melalui tiga prosedur utama, yaitu insertFirst(), insertAfter(), dan insertLast(). Prosedur insertFirst() menempatkan node baru di awal list dengan cara menghubungkannya langsung ke node pertama yang sudah ada. insertAfter() memungkinkan penyisipan node di tengah-tengah list setelah node tertentu, sedangkan insertLast() digunakan untuk menambahkan node di akhir list dengan menelusuri node satu per satu hingga menemukan node terakhir yang pointer-nya bernilai Nil. Sementara itu, prosedur delAfter() menghapus node setelah node tertentu dengan memperbarui arah pointer node sebelumnya agar langsung menunjuk ke node setelahnya, kemudian node yang dihapus di-dealokasi untuk menghindari kebocoran memori.

Selain operasi dasar, ListAngka.cpp juga mengimplementasikan operasi update yang memungkinkan perubahan data tanpa perlu mengubah struktur list. Fungsi updateFirst() memperbarui nilai node pertama, updateLast() memperbarui nilai node terakhir dengan cara melakukan traversal hingga mencapai node terakhir, sedangkan updateAfter() memperbarui node setelah node tertentu yang diberikan sebagai argumen. Ketiga prosedur ini memperlihatkan fleksibilitas linked list dalam memodifikasi data secara efisien.

Pada bagian searching, terdapat tiga fungsi pencarian yang masing-masing menggunakan metode traversal linear. Fungsi SearchNodeByData() mencari node berdasarkan nilai integer yang tersimpan di dalamnya dan menampilkan posisi di mana data tersebut ditemukan. Fungsi SearchNodeByAddress() mencari node berdasarkan alamat memori yang spesifik, berguna dalam konteks debugging atau validasi. Sementara itu, SearchNodeByMinValue() menampilkan semua node yang memiliki nilai lebih besar atau sama dengan batas minimum yang ditentukan pengguna. Ketiga metode pencarian ini memiliki kompleksitas waktu O(n) karena dilakukan dengan menelusuri node satu per satu dari awal hingga akhir list.

file ini juga memuat tiga fungsi operasi aritmetika, yaitu penjumlahan(), pengurangan(), dan perkalian(). Fungsi penjumlahan() menghitung total dari seluruh nilai node dalam list dengan menjumlahkan setiap elemen secara berurutan. Fungsi pengurangan() bekerja dengan cara menjumlahkan semua elemen terlebih dahulu, kemudian menguranginya dari elemen pertama. Fungsi perkalian() melakukan operasi perkalian secara berurutan pada setiap elemen dalam list, menghasilkan hasil perkalian dari seluruh node yang ada. Ketiga fungsi ini memperluas penggunaan singly linked list dari sekadar penyimpanan data menjadi alat untuk melakukan perhitungan numerik terstruktur.

file main.cpp berfungsi sebagai driver program yang mengintegrasikan seluruh fungsi dari kedua file sebelumnya. Program diawali dengan pembuatan linked list kosong melalui pemanggilan createList(). Selanjutnya, beberapa node dialokasikan menggunakan fungsi alokasi() dengan nilai numerik berbeda, yaitu 8, 13, 18, 25, 33, dan 40. Node-node tersebut kemudian dimasukkan ke dalam list menggunakan kombinasi prosedur insertFirst(), insertAfter(), dan insertLast(), sehingga membentuk urutan elemen yang terhubung dinamis. Prosedur delAfter() kemudian digunakan untuk menghapus salah satu node setelah node tertentu guna menunjukkan bagaimana manipulasi pointer dapat mengubah struktur list tanpa perlu memindahkan data secara fisik.

Setelah operasi penyisipan dan penghapusan, program menampilkan isi list menggunakan printList(). Tahapan berikutnya menampilkan penerapan operasi pembaruan melalui updateFirst(), updateAfter(), dan updateLast(), yang memungkinkan pengguna memperbarui nilai pada node tertentu. Hasil dari pembaruan ditampilkan kembali melalui pemanggilan printList() untuk memperlihatkan perubahan data secara langsung. Kemudian, dilakukan serangkaian operasi pencarian, yaitu pencarian berdasarkan nilai (SearchNodeByData()), pencarian berdasarkan alamat node (SearchNodeByAddress()), serta pencarian berdasarkan batas nilai minimum (SearchNodeByMinValue()).

Bagian akhir program menampilkan penerapan operasi aritmetika terhadap data yang tersimpan dalam list. Fungsi penjumlahan(), pengurangan(), dan perkalian() dipanggil untuk menghitung hasil matematis dari seluruh elemen dalam list, yang kemudian ditampilkan di layar. Dengan demikian, program ini tidak hanya menunjukkan kemampuan linked list dalam pengelolaan data dinamis, tetapi juga memperlihatkan bagaimana struktur ini dapat diadaptasi untuk melakukan perhitungan berbasis data secara langsung.

Secara keseluruhan, ketiga file ini mencerminkan implementasi komprehensif dari konsep singly linked list dalam konteks pengelolaan dan pemrosesan data numerik. Struktur data ini memungkinkan penyimpanan elemen secara dinamis dengan efisiensi tinggi, tanpa batasan ukuran tetap seperti array. Selain itu, fitur pembaruan, pencarian, dan operasi aritmetika yang ditambahkan memperkaya fungsionalitas linked list sehingga dapat digunakan untuk aplikasi yang lebih kompleks. Pendekatan modular yang digunakan juga mencerminkan praktik rekayasa perangkat lunak yang baik, di mana pemisahan antara definisi, implementasi, dan eksekusi memungkinkan sistem menjadi lebih terstruktur, efisien, serta mudah dikembangkan di masa mendatang.

### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week5/output/output-unguided3.png)


## Kesimpulan
Kesimpulan nya adalah implementasi struktur data singly linked list merupakan salah satu bentuk konkret dari pengelolaan data dinamis yang efisien dalam pemrograman. Melalui tiga file utama, yaitu ListAngka.h, ListAngka.cpp, dan main.cpp, konsep linked list tidak hanya diterapkan dalam konteks dasar seperti penyisipan (insertion), penghapusan (deletion), serta pencetakan data (traversal), tetapi juga dikembangkan lebih lanjut dengan menambahkan fitur pembaruan data (update), pencarian (searching), dan operasi aritmetika (mathematical operations). Pendekatan ini memperlihatkan bagaimana struktur data fundamental dapat dioptimalkan untuk berbagai kebutuhan manipulasi data numerik tanpa mengandalkan struktur penyimpanan statis seperti array.

Hasil analisis terhadap kode program menunjukkan bahwa penggunaan struktur data singly linked list memberikan fleksibilitas tinggi dalam pengelolaan memori. Setiap elemen atau node dalam list terdiri dari dua komponen utama, yaitu data dan pointer yang menunjuk ke node berikutnya, sehingga memungkinkan penambahan dan penghapusan elemen tanpa perlu melakukan pergeseran data secara keseluruhan. Proses penyisipan node pada berbagai posisi (awal, tengah, dan akhir) dapat dilakukan dengan efisien melalui pengaturan pointer, sedangkan penghapusan node juga dapat dilaksanakan dengan menjaga konsistensi alur koneksi antar-node. Hal ini menunjukkan bahwa singly linked list unggul dalam operasi yang membutuhkan perubahan struktur data secara dinamis selama waktu eksekusi program.

Fitur update yang diimplementasikan pada program ini memperlihatkan bagaimana nilai di dalam node dapat dimodifikasi secara langsung tanpa mengubah struktur list. Fungsi updateFirst(), updateLast(), dan updateAfter() memberikan fleksibilitas bagi pengguna untuk memperbarui data pada posisi tertentu. Sementara itu, bagian searching menyediakan tiga metode pencarian berbeda — pencarian berdasarkan nilai data, alamat memori, dan batas nilai minimum. Penerapan fungsi pencarian ini menegaskan bahwa singly linked list dapat digunakan tidak hanya untuk penyimpanan, tetapi juga untuk analisis dan pengambilan data secara selektif. Dengan pendekatan traversal linear, sistem pencarian tetap efisien untuk ukuran data yang relatif kecil hingga menengah.

Selain itu, pengembangan program ini mencakup operasi aritmetika berupa penjumlahan, pengurangan, dan perkalian terhadap seluruh data yang tersimpan dalam list. Penambahan fungsi ini memperluas penerapan linked list ke arah pemrosesan numerik, di mana setiap node tidak hanya berperan sebagai wadah data, tetapi juga sebagai bagian dari perhitungan matematis yang terintegrasi. Dengan demikian, singly linked list dalam konteks ini tidak hanya berfungsi sebagai struktur data pasif, melainkan juga sebagai komponen aktif dalam proses komputasi.

Dari keseluruhan implementasi dan analisis yang telah dilakukan, dapat disimpulkan bahwa pemanfaatan singly linked list dalam program ini berhasil menggambarkan prinsip dasar serta potensi pengembangannya dalam sistem yang lebih kompleks. Struktur data ini terbukti efektif dalam pengelolaan data dinamis, efisien dalam penggunaan memori, serta fleksibel untuk berbagai jenis operasi seperti penyisipan, pembaruan, pencarian, dan perhitungan. Pendekatan modular melalui pemisahan file header, implementasi, dan program utama mencerminkan penerapan konsep structured programming dan software engineering yang baik, sehingga memudahkan pemeliharaan, pembacaan, serta pengembangan kode di masa mendatang. Dengan demikian, penelitian dan implementasi ini memberikan pemahaman komprehensif tentang bagaimana struktur data singly linked list dapat digunakan sebagai fondasi dalam perancangan sistem data yang efisien, adaptif, dan aplikatif dalam bidang informatika.


## Referensi
[1] Banerjee, A., & Kumar, P. K. (2022). A New Vista of Performing Insertion and Deletion in Linked Lists. International Journal of Computer Science and Mobile Computing, 11(7), 83–97. https://doi.org/10.47760/ijcsmc.2022.v11i07.008
<br>
[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan Struktur Data Linked List dan Array dalam Manajemen Memori. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin
</br>
[3] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan (JSIT), 2(2), 441–444. https://rcf-indonesia.org/home/