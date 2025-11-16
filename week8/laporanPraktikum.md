# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Queue merupakan salah satu struktur data linear yang berperan penting dalam pemrograman, khususnya untuk menangani proses atau data yang harus diproses berdasarkan urutan kedatangan. Queue bekerja dengan prinsip FIFO (First In First Out), yaitu elemen yang pertama kali masuk menjadi elemen pertama yang keluar. Prinsip ini banyak diterapkan pada berbagai mekanisme sistem komputer, seperti penjadwalan proses, buffer input/output, antrian printer, hingga pengaturan lalu lintas paket pada jaringan komputer [1]. Dalam ilmu komputer modern, pemahaman terhadap queue menjadi esensial karena struktur ini mampu memastikan data diproses secara teratur, adil, dan efisien sesuai urutan kedatangannya.

Dalam bahasa C++, queue dapat diimplementasikan menggunakan array maupun singly linked list. Kedua representasi ini memiliki cara kerja yang berbeda terutama dalam hal pengelolaan memori, efisiensi operasi, serta fleksibilitas. Modul praktikum menjelaskan bahwa queue menggunakan array termasuk dalam struktur data statis, karena ukuran array harus ditentukan sejak awal dan bersifat tetap selama program berlangsung. Pada konteks ini, operasi queue memanfaatkan dua indeks utama, yaitu head untuk menunjukkan elemen terdepan dan tail untuk menunjukkan elemen paling belakang dalam antrian. Implementasi queue berbasis array memiliki beberapa teknik yang berbeda, dan masing-masing memiliki karakteristik operasional tersendiri.

Implementasi pertama adalah queue alternatif 1, yaitu representasi sederhana di mana HEAD tetap berada pada indeks awal, sedangkan TAIL bergerak maju setiap kali dilakukan penyisipan elemen. Pada model ini, ketika terjadi operasi dequeue, elemen yang berada di depan harus dihapus dan seluruh elemen setelahnya digeser satu indeks ke depan agar HEAD tetap berada pada posisi tetap. Cara ini mudah dipahami, tetapi tidak efisien karena proses shifting tersebut membutuhkan waktu O(n) untuk setiap penghapusan elemen. Meskipun demikian, model ini sering digunakan untuk pemula karena bentuknya yang lebih intuitif.

Implementasi kedua adalah queue alternatif 2, yaitu representasi di mana HEAD dan TAIL sama-sama bergerak mengikuti operasi. Ketika sebuah elemen dihapus, HEAD cukup digeser satu indeks tanpa perlu memindahkan seluruh elemen lainnya. Hal ini membuat proses dequeue lebih efisien dibandingkan alternatif pertama. Namun, pendekatan ini dapat menimbulkan kondisi yang disebut penuh semu, yaitu ketika TAIL telah mencapai batas array, tetapi masih terdapat ruang kosong di awal array akibat pergerakan HEAD. Walaupun alternatif kedua lebih efisien daripada yang pertama, tetap ada ketergantungan pada kapasitas array yang terbatas.

Implementasi ketiga adalah queue alternatif 3, yang dikenal sebagai circular queue. Pada model ini, HEAD dan TAIL bergerak melingkar mengikuti indeks array. Ketika TAIL mencapai indeks terakhir, posisi berikutnya akan kembali ke indeks awal selama posisi tersebut kosong. Dengan cara ini, masalah “penuh semu” dapat dihindari karena penggunaan ruang array menjadi optimal tanpa memerlukan operasi shifting. Circular queue banyak digunakan dalam sistem nyata seperti penjadwalan proses pada sistem operasi, buffer jaringan, maupun sistem antrian real-time karena efisiensinya dalam memanfaatkan ruang memori statis [1].

Selain representasi array, queue juga dapat diimplementasikan menggunakan singly linked list (SLL). Pada representasi ini, setiap elemen queue disimpan dalam node yang terdiri dari data dan pointer ke node berikutnya. Queue dengan linked list bersifat dinamis, artinya penambahan elemen tidak dibatasi ukuran tertentu seperti pada array. Dua pointer utama digunakan yaitu head untuk elemen terdepan dan tail untuk elemen terakhir. Operasi enqueue dilakukan dengan menambahkan node baru di bagian tail, sedangkan operasi dequeue dilakukan dengan mengambil node dari head. Karena setiap operasi hanya memanipulasi pointer tanpa perlu memindahkan elemen lain, linked list memberikan efisiensi yang lebih baik dalam penghapusan maupun penyisipan elemen, terutama pada ukuran data yang besar.

Dalam penelitian Sihombing (2020), dijelaskan bahwa queue berbasis linked list memiliki fleksibilitas tinggi karena ukuran antrean dapat bertambah selama memori masih tersedia, sehingga representasi ini cocok untuk kasus yang tidak memiliki batas ukuran pasti. Meskipun demikian, linked list membutuhkan memori tambahan untuk menyimpan pointer dan aksesnya tidak secepat array dalam hal indeks langsung [2]. Namun, sifat dinamis ini membuat linked list lebih unggul pada kasus queue berskala besar atau ketika jumlah data tidak dapat diprediksi sebelumnya.

Selain itu, beberapa literatur menyatakan bahwa pemilihan representasi queue harus disesuaikan dengan konteks penggunaan. Queue yang bekerja pada sistem operasi dan pemrosesan real-time lebih sering menggunakan circular queue karena efisiensi ruang dan waktu yang stabil [1], sedangkan queue pada aplikasi bersifat dinamis, seperti manajemen tugas atau proses jaringan, lebih cocok menggunakan linked list [2]. Dengan demikian, baik array maupun singly linked list memiliki keunggulan masing-masing dan sama-sama umum digunakan dalam implementasi queue di C++.

Secara keseluruhan, implementasi queue dalam C++ memberikan gambaran penting mengenai bagaimana struktur data mengelola urutan eksekusi data menggunakan prinsip FIFO. Pemahaman terhadap representasi queue dengan array (melalui tiga alternatif implementasi) maupun dengan singly linked list tidak hanya membantu dalam praktik pemrograman, tetapi juga memberikan dasar untuk memahami mekanisme internal berbagai sistem komputasi modern, seperti penjadwalan proses, buffer komunikasi, dan sistem antrian terdistribusi [1][2]. Oleh karena itu, penguasaan konsep queue beserta implementasinya menjadi salah satu kompetensi mendasar dalam pembelajaran struktur data.

## Guided 

### 1.1 queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

### 1.2 queue.cpp

```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

### 1.3 main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Kode program pada file queue.h mendefinisikan struktur dasar dari sebuah queue yang diimplementasikan menggunakan singly linked list. Pada bagian awal, terdapat deklarasi header guard untuk mencegah proses pemanggilan file secara berulang. Struktur Node merepresentasikan satu elemen dalam queue, di mana setiap node menyimpan data berupa string nama dan sebuah pointer next yang menunjuk pada node berikutnya. Selanjutnya, struktur queue memuat dua pointer, yakni head dan tail, masing-masing berfungsi menunjuk elemen pertama dan elemen terakhir dalam antrian. Serangkaian fungsi prototipe juga dideklarasikan, antara lain fungsi untuk membuat queue baru, memeriksa kondisi kosong atau penuh, menambahkan elemen baru, menghapus elemen, menampilkan seluruh isi queue, serta menghapus seluruh elemen queue.

Pada file queue.cpp, seluruh fungsi yang telah dideklarasikan sebelumnya diimplementasikan. Fungsi createQueue bertugas menginisialisasi queue dengan mengatur pointer head dan tail ke nilai nullptr, menandakan bahwa antrian masih kosong. Fungsi isEmpty kemudian digunakan untuk mengecek apakah queue tidak memiliki elemen, yaitu dengan memeriksa apakah pointer head bernilai nullptr. Adapun fungsi isFull selalu mengembalikan nilai salah, karena queue berbasis linked list bersifat dinamis dan tidak memiliki batasan jumlah elemen selama memori masih tersedia.

Fungsi enQueue berperan untuk menambahkan elemen baru ke dalam queue. Proses ini dilakukan dengan mengalokasikan node baru dan mengisi data nama ke dalamnya. Jika queue masih kosong, node baru tersebut sekaligus menjadi head dan tail. Namun, jika queue sudah memiliki elemen, node baru ditambahkan pada bagian akhir dengan cara mengatur pointer next dari node tail ke node baru, kemudian memperbarui posisi tail. Fungsi ini juga menampilkan pesan bahwa data berhasil ditambahkan. Sementara itu, fungsi deQueue berfungsi menghapus elemen paling depan dari queue. Jika queue kosong, fungsi akan menampilkan pesan peringatan. Jika tidak, node pertama disimpan sementara dalam pointer hapus, kemudian pointer head digeser ke node berikutnya. Apabila setelah penghapusan tidak ada node tersisa, pointer tail juga diset ke nullptr. Node yang telah dihapus kemudian dilepaskan dari memori untuk mencegah kebocoran memori.

Fungsi viewQueue digunakan untuk menampilkan seluruh elemen dalam queue secara berurutan mulai dari head hingga tail. Setiap elemen dicetak bersama nomor urutnya. Jika queue kosong, fungsi akan menampilkan pesan bahwa queue tidak memiliki data. Adapun fungsi clearQueue bekerja dengan memanggil fungsi deQueue berulang kali hingga tidak ada elemen yang tersisa, sehingga seluruh node yang dialokasikan akan dilepaskan dari memori secara aman.

Pada file main.cpp, fungsi main berfungsi sebagai titik awal eksekusi program. Sebuah objek queue bernama Q dibuat dan diinisialisasi melalui fungsi createQueue. Selanjutnya, beberapa nama dimasukkan ke dalam antrian menggunakan fungsi enQueue. Setelah seluruh data ditambahkan, program menampilkan isi queue untuk menunjukkan kondisi antrian setelah proses penambahan. Program kemudian memanggil fungsi deQueue sebanyak empat kali untuk menghapus elemen-elemen terdepan secara berurutan. Setelah itu, isi queue kembali ditampilkan untuk memperlihatkan perubahan yang terjadi setelah beberapa elemen dihapus. Pada akhir program, fungsi clearQueue dipanggil untuk mengosongkan seluruh isi antrian sebelum program selesai dijalankan, sebagai bentuk praktik pengelolaan memori yang baik.


### 2.1 queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

### 1.2 queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}


//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

### 2.3 main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Kode program pada file queue.h mendefinisikan struktur queue berbasis array yang digunakan sebagai representasi antrian statis. Struktur queue terdiri atas sebuah array nama dengan kapasitas tetap sebanyak lima elemen serta dua variabel indeks head dan tail yang berfungsi untuk menandai posisi awal dan akhir dari antrian. Kapasitas yang bersifat tetap menyebabkan queue ini dikategorikan sebagai struktur data statis, sehingga manajemen ruang dilakukan melalui pengaturan indeks, bukan melalui alokasi memori dinamis. Pada bagian ini, dideklarasikan pula fungsi-fungsi dasar seperti pemeriksaan kondisi penuh dan kosong, prosedur pembentukan queue, penambahan elemen, penghapusan elemen, serta penampilan isi antrian.

Implementasi fungsi pada file queue.cpp dimulai dari fungsi isEmpty, yang mengembalikan nilai benar apabila kedua indeks, head dan tail, bernilai −1, yang menandakan bahwa queue tidak memiliki elemen. Fungsi isFull pada implementasi pertama dan kedua akan mengembalikan nilai benar jika tail telah mencapai indeks maksimum array, yaitu indeks ke-4. Hal ini mencerminkan sifat queue linear, yaitu bahwa ruang penyimpanan tidak dapat digunakan kembali meskipun terdapat celah di posisi awal array. Di sisi lain, terdapat pula versi alternatif isFull untuk implementasi ketiga, yaitu model circular queue. Pada model ini, queue dianggap penuh jika (tail + 1) % MAKSIMAL bernilai sama dengan head, sehingga seluruh ruang array dimanfaatkan secara melingkar tanpa menyisakan area kosong yang tidak dapat digunakan.

Fungsi CreateQueue menginisialisasi queue dengan menetapkan nilai head dan tail menjadi −1 sebagai penanda bahwa antrian baru saja dibentuk dan belum memiliki elemen. Pada fungsi enQueue yang merupakan implementasi pertama dan kedua, penambahan elemen dilakukan dengan menaikkan nilai tail. Jika queue masih kosong, kedua indeks diatur menjadi nol, dan elemen baru disimpan pada posisi tersebut. Namun, jika queue telah berisi data, nilai tail dinaikkan satu satuan sehingga elemen baru ditempatkan pada posisi paling akhir. Dalam implementasi ketiga, prosedur enQueue sedikit berbeda karena tail bergerak secara melingkar menggunakan operasi modulo, sehingga ketika indeks mencapai batas array, posisi berikutnya kembali ke indeks awal selama ruang tersebut kosong.

Proses penghapusan elemen queue pada implementasi pertama dilakukan dengan mekanisme shifting, yaitu memindahkan seluruh elemen yang berada di belakang head ke satu indeks lebih awal. Ketika elemen paling depan dihapus, seluruh elemen lain bergeser satu posisi ke kiri sehingga head tetap berada pada indeks nol. Pendekatan ini mudah dipahami namun kurang efisien karena melibatkan pergeseran array setiap kali elemen dihapus. Pada implementasi kedua, penghapusan dilakukan hanya dengan menaikkan nilai head. Setelah elemen pada posisi head dihapus, indeks head digeser ke depan tanpa memindahkan elemen lain, sehingga proses menjadi lebih efisien. Apabila nilai head melampaui nilai tail, kedua indeks dikembalikan menjadi −1 karena queue telah kosong. Pada implementasi ketiga, prosedur deQueue juga dilakukan secara melingkar. Jika head dan tail berada pada posisi yang sama, penghapusan elemen terakhir menyebabkan antrian kosong sehingga kedua indeks diset kembali menjadi −1. Namun, jika masih terdapat lebih dari satu elemen, head diubah menjadi (head + 1) % MAKSIMAL, sehingga penelusuran dan penghapusan dapat dilakukan dalam pola melingkar mengikuti struktur circular queue.

Fungsi viewQueue untuk implementasi pertama dan kedua menampilkan seluruh elemen dalam rentang indeks dari head hingga tail. Elemen dicetak secara berurutan dengan menyesuaikan penomoran agar dimulai dari angka satu. Pada implementasi ketiga, proses penampilan elemen juga dilakukan secara melingkar, dimulai dari indeks head dan bergerak maju menggunakan operasi modulo sampai mencapai indeks tail. Mekanisme ini memastikan bahwa seluruh elemen dapat ditampilkan secara benar meskipun posisi head tidak berada di awal array akibat pergerakan melingkar.

Pada main.cpp, proses eksekusi program dimulai dengan pembentukan queue baru melalui pemanggilan fungsi CreateQueue. Beberapa nama kemudian dimasukkan ke dalam antrian menggunakan prosedur enQueue. Karena kapasitas queue hanya lima elemen, penambahan elemen lebih dari jumlah tersebut menghasilkan pesan bahwa queue telah penuh. Setelah seluruh data ditambahkan, isi queue ditampilkan untuk menunjukkan keadaan antrian sebelum proses penghapusan dilakukan. Pemanggilan deQueue sebanyak empat kali menghapus beberapa elemen terdepan secara berurutan sesuai prinsip FIFO. Setelah proses ini, isi queue kembali ditampilkan untuk memperlihatkan perubahan pada antrian. Program kemudian berakhir setelah seluruh operasi dasar queue berhasil digunakan, sehingga memberikan gambaran lengkap mengenai cara kerja antrian berbasis array dalam ketiga model implementasi, yaitu queue linear statis, queue linear dinamis, dan queue circular yang memanfaatkan indeks melingkar untuk penggunaan ruang yang lebih efisien.


## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY di dalam file queue.h”. Lalu, uatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif
```

##### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail == MAX - 1);
}

void createQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue is full!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Empty queue" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << "  : empty queue" << endl;
    } else {
        cout << Q.head << " - " << Q.tail << "    : ";
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i];
            if(i < Q.tail) cout << " ";
        }
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week8/output/output-unguided1.png)
Kode program pada file queue.h mendefinisikan struktur dasar dari sebuah queue yang direpresentasikan menggunakan array statis berukuran tetap. Konstanta MAX menetapkan kapasitas antrian sebanyak lima elemen. Tipe data infotype didefinisikan sebagai int, sehingga antrian hanya menyimpan nilai bertipe bilangan bulat. Struktur queue terdiri atas sebuah array info yang berfungsi sebagai tempat penyimpanan elemen serta dua variabel indeks, yaitu head dan tail, yang secara berurutan menunjuk pada posisi elemen pertama dan elemen terakhir dalam antrian. File ini juga mencantumkan prototipe fungsi untuk membentuk antrian baru, memeriksa kondisi antrian kosong atau penuh, menambahkan elemen, menghapus elemen terdepan, serta menampilkan seluruh isi antrian.

Pada file queue.cpp, fungsi-fungsi yang telah dideklarasikan sebelumnya mulai diimplementasikan. Fungsi isEmptyQueue memeriksa apakah antrian tidak memiliki elemen dengan memastikan bahwa kedua indeks, head dan tail, bernilai −1. Kondisi ini merupakan penanda standar bahwa queue masih berada dalam keadaan awal atau telah dikosongkan sepenuhnya. Fungsi isFullQueue, di sisi lain, mengembalikan nilai benar ketika variabel tail telah mencapai indeks maksimum, yaitu MAX - 1. Karena struktur queue ini menggunakan array statis tanpa mekanisme pergerakan melingkar, antrian dianggap penuh ketika elemen telah mencapai batas akhir array, meskipun pelaksanaan operasi dequeue dapat meninggalkan ruang kosong pada indeks awal. Hal tersebut merupakan salah satu keterbatasan queue linear statis.

Fungsi createQueue berfungsi untuk menginisialisasi queue dengan cara mengatur nilai head dan tail menjadi −1. Inisialisasi ini memastikan bahwa queue berada dalam keadaan kosong sebelum digunakan. Fungsi enqueue kemudian digunakan untuk menambahkan elemen baru pada bagian belakang antrian. Jika antrian penuh, fungsi memberikan pesan bahwa penambahan elemen tidak dapat dilakukan. Namun, apabila antrian masih kosong, indeks head dan tail ditetapkan pada nilai 0 sebagai posisi awal dari elemen pertama. Jika antrian telah berisi elemen, nilai tail dinaikkan satu satuan dan data baru ditempatkan pada indeks tersebut.

Proses penghapusan elemen dalam queue, yang dilakukan oleh fungsi dequeue, mengikuti prinsip FIFO dengan menghapus elemen yang berada pada posisi head. Jika queue kosong, fungsi menampilkan pesan peringatan dan mengembalikan nilai −1 sebagai indikator bahwa tidak ada data yang dapat diambil. Jika antrian masih berisi elemen, nilai dari indeks head disimpan terlebih dahulu, kemudian seluruh elemen setelahnya digeser satu posisi ke depan. Proses pergeseran ini bertujuan agar head selalu berada pada indeks nol setelah penghapusan, sesuai karakteristik queue linear statis implementasi pertama. Setelah pergeseran selesai, indeks tail dikurangi satu satuan. Jika nilai tail menjadi kurang dari nol setelah penghapusan, antrian dinyatakan kosong kembali sehingga head dan tail direset ke nilai −1. Nilai elemen yang dihapus dikembalikan agar dapat digunakan pada proses selanjutnya.

Fungsi printInfo digunakan untuk menampilkan isi queue beserta nilai indeks head dan tail. Jika antrian kosong, fungsi menampilkan tulisan “empty queue” disertai posisi indeks. Jika antrian memiliki elemen, fungsi mencetak seluruh nilai dari indeks head hingga tail secara berurutan, sehingga pengguna dapat memantau kondisi antrian setelah setiap operasi dilakukan.

Pada file main.cpp, program dimulai dengan mencetak pesan pembuka serta membentuk queue baru melalui pemanggilan fungsi createQueue. Serangkaian operasi enqueue dan dequeue kemudian dilakukan untuk memperlihatkan bagaimana elemen ditambahkan, diproses, dan dihapus dari antrian. Setiap perubahan keadaan queue ditampilkan secara langsung menggunakan fungsi printInfo, sehingga alur perubahan indeks dan isi antrian dapat diamati dengan jelas. Program ini dengan demikian memberikan gambaran menyeluruh mengenai cara kerja queue linear statis menggunakan array, termasuk bagaimana kondisi penuh dan kosong ditangani serta bagaimana elemen digeser pada proses penghapusan.


### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif
```

##### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail == MAX - 1);
}

void createQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue is full!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Empty queue" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << "  : empty queue" << endl;
    } else {
        cout << Q.head << " - " << Q.tail << "    : ";
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i];
            if(i < Q.tail) cout << " ";
        }
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week8/output/output-unguided2.png)
Kode program pada file queue.h mendeskripsikan struktur queue berbasis array dengan kapasitas tetap yang ditetapkan melalui konstanta MAX bernilai lima. Tipe data infotype didefinisikan sebagai bilangan bulat untuk mempermudah penggunaan dan konsistensi tipe data pada seluruh fungsi. Struktur queue memuat sebuah array info sebagai tempat penyimpanan elemen serta dua variabel indeks, yaitu head dan tail, yang digunakan untuk menunjukkan posisi elemen terdepan dan elemen terakhir dari antrian. Selain itu, file ini mendeklarasikan sejumlah fungsi yang diperlukan untuk membangun dan memanipulasi queue, seperti inisialisasi, pengecekan kondisi kosong atau penuh, penambahan elemen, penghapusan elemen, serta tampilan isi antrian.

Pada file queue.cpp, fungsi pertama yang diimplementasikan adalah isEmptyQueue. Fungsi ini mengembalikan nilai benar apabila head dan tail bernilai −1, yang menunjukkan bahwa antrian belum menyimpan elemen apa pun. Fungsi isFullQueue memeriksa apakah antrian telah mencapai kapasitas penuh dengan melihat apakah nilai tail sama dengan indeks maksimum array, yaitu MAX - 1. Pada implementasi ini, queue dikategorikan sebagai queue linear dinamis, karena ruang kosong yang muncul akibat pergeseran head tidak dapat digunakan kembali oleh operasi enqueue, meskipun nilai head terus bergerak maju. Hal tersebut merupakan salah satu karakteristik dari queue linear yang tidak menggunakan mekanisme melingkar.

Fungsi createQueue bertugas menginisialisasi queue sehingga antrian berada dalam kondisi kosong sebelum digunakan. Inisialisasi dilakukan dengan menetapkan nilai awal head dan tail sebagai −1. Ketika fungsi enqueue dijalankan, program terlebih dahulu memeriksa apakah antrian sudah penuh. Jika penuh, operasi penambahan elemen dibatalkan dan sebuah pesan peringatan ditampilkan. Namun, apabila antrian masih kosong, indeks head dan tail diatur ke nilai nol untuk menandai bahwa elemen pertama ditempatkan pada indeks awal array. Jika antrian sudah berisi data, nilai tail dinaikkan satu satuan, kemudian elemen baru disimpan pada indeks tersebut. Mekanisme ini mencerminkan prinsip bahwa penambahan elemen pada queue selalu dilakukan di bagian belakang antrian.

Fungsi dequeue mengimplementasikan proses penghapusan elemen dari bagian depan queue. Apabila queue kosong, fungsi akan menampilkan pesan kesalahan dan mengembalikan nilai −1 sebagai indikator bahwa tidak ada elemen yang dapat dihapus. Jika terdapat elemen, fungsi menyimpan nilai elemen pada posisi head sebelum menambah nilai head satu satuan. Untuk mendeteksi apakah antrian menjadi kosong setelah penghapusan, program memeriksa apakah nilai head telah melampaui nilai tail. Jika kondisi tersebut terpenuhi, kedua indeks dikembalikan menjadi −1 sebagai penanda bahwa antrian kembali berada pada keadaan kosong. Secara keseluruhan, metode ini tidak melakukan proses shifting seperti pada implementasi pertama, sehingga operasi penghapusan lebih efisien namun tetap memiliki keterbatasan dalam penggunaan ulang ruang array.

Fungsi printInfo berfungsi untuk menampilkan isi queue beserta informasi letak indeks head dan tail. Ketika queue kosong, fungsi menampilkan penanda indeks dan keterangan bahwa antrian tidak memiliki elemen. Jika queue sedang berisi, seluruh elemen ditampilkan secara berurutan dari head hingga tail, memberikan gambaran visual mengenai kondisi internal antrian setelah setiap operasi dilakukan.

Dalam main.cpp, program dimulai dengan pembentukan dan inisialisasi queue melalui pemanggilan fungsi createQueue. Selanjutnya, serangkaian operasi enqueue dan dequeue dilakukan untuk menggambarkan perubahan kondisi queue secara bertahap. Setiap perubahan dicetak melalui printInfo, sehingga pengguna dapat melihat pergerakan indeks head dan tail serta perubahan isi antrian. Program ini memperlihatkan karakteristik utama dari implementasi queue linear dinamis, yaitu bahwa head dan tail bergerak maju mengikuti operasi penambahan dan penghapusan tanpa memanfaatkan kembali ruang kosong pada bagian awal array. Dengan demikian, contoh ini memberikan ilustrasi yang baik mengenai keterbatasan dan mekanisme kerja queue berbasis array pada representasi linear non-sirkular.


### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif
```

##### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return ((Q.tail + 1) % MAX == Q.head);
}

void createQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue is full!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Empty queue" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
        return x;
    }
}

void printInfo(queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << "  : empty queue" << endl;
    } else {
        int i = Q.head;
        cout << Q.head << " - " << Q.tail << "    : ";
        while(true){
            cout << Q.info[i] << " ";
            if( i == Q.tail){
                break;
            }
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week8/output/output-unguided3.png)
Kode program pada file queue.h mendefinisikan struktur queue berbasis array statis dengan kapasitas tetap yang ditentukan oleh konstanta MAX bernilai lima. Tipe data infotype didefinisikan sebagai int, sehingga elemen queue berupa bilangan bulat. Struktur queue memuat sebuah array info yang berfungsi sebagai wadah penyimpanan dan dua variabel indeks, head dan tail, yang bertugas menunjukkan posisi elemen pertama dan elemen terakhir dalam antrian. Selain itu, file ini mencantumkan deklarasi fungsi untuk membuat queue baru, memeriksa kondisi kosong dan penuh, menambah elemen, menghapus elemen, serta menampilkan isi queue. Seluruh deklarasi ini menjadi fondasi pengoperasian queue circular yang diimplementasikan pada file queue.cpp.

Pada file queue.cpp, fungsi isEmptyQueue memeriksa apakah queue tidak berisi elemen dengan melihat apakah kedua indeks head dan tail berada pada nilai −1. Kondisi ini berlaku baik ketika queue baru saja dibuat maupun ketika semua elemen telah dihapus. Fungsi isFullQueue mengimplementasikan logika khas queue circular, yaitu queue dianggap penuh apabila posisi berikutnya dari indeks tail, setelah dihitung menggunakan operasi modulo, berada pada posisi yang sama dengan head. Dengan demikian, mekanisme perputaran indeks memungkinkan pemanfaatan penuh ruang array tanpa terjadi keadaan “penuh semu” yang biasanya muncul pada queue linear statis.

Fungsi createQueue menginisialisasi queue dengan menetapkan nilai head dan tail pada −1, menandakan bahwa antrian berada pada keadaan kosong. Fungsi enqueue kemudian bertugas menambahkan elemen baru ke dalam queue. Jika queue berada dalam keadaan penuh, fungsi memberikan pesan peringatan. Namun, apabila queue masih kosong, baik head maupun tail diatur menjadi nol sebagai posisi awal dari elemen pertama. Jika queue telah berisi elemen, nilai tail diperbarui menggunakan operasi (Q.tail + 1) % MAX, sehingga pergerakan indeks tail dilakukan secara melingkar mengitari batas array. Elemen baru kemudian ditempatkan pada posisi tail, dan karena pergerakan melingkar ini, ruang kosong di bagian awal array dapat digunakan kembali setelah beberapa operasi dequeue dilakukan.

Fungsi dequeue menghapus elemen yang terletak pada posisi head sesuai prinsip FIFO. Apabila queue kosong, fungsi menampilkan pesan “Empty queue” dan mengembalikan nilai −1 sebagai indikator bahwa tidak ada elemen yang dapat dihapus. Jika elemen yang dihapus merupakan satu-satunya elemen dalam queue (ditandai dengan kondisi head == tail), kedua indeks dikembalikan ke nilai awal −1 untuk menandai bahwa antrian telah kosong. Namun, jika masih terdapat elemen lain, nilai head diperbarui menggunakan operasi (Q.head + 1) % MAX, sehingga pergerakan indeks dilakukan secara melingkar sama seperti pada proses penambahan. Dengan demikian, queue circular mampu mempertahankan struktur antrian tanpa membutuhkan pergeseran elemen, sekaligus memanfaatkan area array secara optimal.

Fungsi printInfo menampilkan isi queue beserta nilai indeks head dan tail. Apabila queue kosong, fungsi mencetak keterangan bahwa antrian tidak memiliki elemen. Jika queue berisi data, fungsi mencetak seluruh elemen secara berurutan mulai dari indeks head hingga tail, dengan memanfaatkan pergerakan melingkar menggunakan operasi modulo. Proses pencetakan dilakukan dalam sebuah loop yang berhenti tepat ketika indeks mencapai posisi tail, memastikan bahwa seluruh elemen tercetak tanpa melampaui batas array.

Pada main.cpp, program dimulai dengan mencetak pesan pembuka, kemudian membentuk sebuah queue baru melalui pemanggilan fungsi createQueue. Program kemudian melakukan serangkaian operasi enqueue dan dequeue, dan setiap perubahan keadaan antrian ditampilkan melalui fungsi printInfo. Pengguna dapat mengamati bagaimana indeks head dan tail bergerak sesuai operasi melingkar, serta bagaimana array digunakan secara efisien tanpa adanya penggeseran elemen. Perilaku ini menunjukkan karakteristik utama dari implementasi queue circular, yaitu pengelolaan ruang yang optimal melalui penggunaan sisa kapasitas array yang tidak lagi dimanfaatkan pada queue linear. Program ini memberikan ilustrasi nyata mengenai cara kerja dan keunggulan queue circular dalam pengelolaan antrian pada ruang memori terbatas.


## Kesimpulan
Berdasarkan uraian teori serta hasil pengamatan terhadap berbagai implementasi struktur data queue yang telah dipaparkan, dapat disimpulkan bahwa queue merupakan salah satu struktur data linear yang memiliki peranan penting dalam pengelolaan data berurutan, khususnya pada sistem yang menerapkan prinsip FIFO (First In First Out). Melalui implementasi yang berbeda, mulai dari queue berbasis array hingga queue berbasis singly linked list, dapat dipahami bahwa setiap pendekatan memiliki karakteristik, kelebihan, dan keterbatasan tersendiri dalam pengelolaan memori maupun efisiensi operasi.

Implementasi queue menggunakan array menunjukkan bahwa struktur data statis memerlukan pengaturan indeks yang tepat agar pemanfaatan ruang dapat berjalan secara optimal. Pada implementasi pertama, penghapusan elemen memerlukan proses pergeseran data, sehingga meskipun mudah dipahami, cara ini kurang efisien. Implementasi kedua memperbaiki hal ini dengan menggerakkan head dan tail tanpa pergeseran, namun tetap memiliki keterbatasan karena ruang kosong tidak dapat digunakan kembali. Sementara itu, implementasi ketiga, yaitu circular queue, mampu memanfaatkan seluruh ruang array secara lebih efektif melalui pergerakan indeks secara melingkar. Implementasi tersebut memperlihatkan bahwa konsep sederhana seperti operasi modulo dapat memberikan peningkatan signifikan terhadap efisiensi ruang.

Di sisi lain, queue yang diimplementasikan dengan singly linked list memperlihatkan bagaimana struktur data dinamis dapat memberikan fleksibilitas yang lebih besar. Dengan tidak bergantung pada ukuran memori statis, linked list memungkinkan penambahan elemen selama memori sistem masih tersedia. Setiap operasi penambahan maupun penghapusan elemen berlangsung tanpa perlu memindahkan data lain, sehingga struktur ini lebih efisien untuk penggunaan jangka panjang dan kondisi data yang tidak dapat diprediksi jumlahnya.

Dari ketiga varian implementasi array dan satu implementasi linked list yang telah dianalisis, dapat ditegaskan bahwa pemilihan struktur data queue yang tepat sepenuhnya bergantung pada kebutuhan sistem. Jika ruang memori terbatas dan ukuran antrian dapat diperkirakan, circular queue menjadi pilihan paling efektif. Jika kebutuhan penyimpanan bersifat dinamis dan jumlah data tidak tetap, queue berbasis linked list memberikan fleksibilitas terbaik. Seluruh implementasi yang dipelajari memperlihatkan bahwa pemahaman mengenai pergerakan indeks, pengelolaan memori, dan mekanisme FIFO sangat menentukan keberhasilan dalam merancang struktur data yang andal dan efisien.


## Referensi
<br>
[1] Trijayanti, A., dkk. (2025). Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi. Jurnal Publikasi Teknik Informatika, 4(2), 48–53.
</br>

<br>
[2] Sihombing, J. (2020). Penerapan Stack dan Queue pada Array dan Linked List dalam Java. Politeknik Piksi Ganesha.
</br>
