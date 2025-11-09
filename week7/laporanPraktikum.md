# <h1 align="center">Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Struktur data stack merupakan salah satu struktur data linier yang banyak digunakan dalam berbagai bidang pemrograman karena kemampuannya mengatur data dengan prinsip Last In First Out (LIFO), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan [5]. Menurut Soffya Ranti (2022), operasi dasar pada stack meliputi push untuk menambahkan elemen ke puncak tumpukan, pop untuk menghapus elemen teratas, peek untuk melihat elemen teratas tanpa menghapusnya, serta isEmpty untuk memeriksa apakah stack kosong [4]. Struktur ini menjadi komponen penting dalam proses komputasi seperti evaluasi ekspresi matematika, pengelolaan memori, pemrosesan rekursif, dan fitur undo/redo dalam aplikasi perangkat lunak [5].

Dalam implementasinya, stack dapat dibangun menggunakan dua pendekatan utama, yaitu array dan linked list. Pendekatan array menggunakan alokasi memori statis, di mana seluruh elemen disimpan dalam blok memori berurutan dan ukuran stack harus ditentukan sejak awal. Menurut Indah Kusuma Astuti (2019), array merupakan tipe data terstruktur yang mampu menyimpan sejumlah elemen dengan tipe data yang sama di lokasi memori yang kontinu serta diakses melalui indeks [5]. Kelebihan utama pendekatan ini adalah efisiensi waktu akses yang tinggi karena elemen dapat diakses secara langsung menggunakan indeks dengan kompleksitas waktu O(1). Selain itu, implementasinya relatif sederhana karena tidak memerlukan pengelolaan memori dinamis. Namun, kekurangannya terletak pada ukuran yang tetap sehingga tidak dapat menyesuaikan diri dengan perubahan jumlah data selama program berjalan, serta kemungkinan terjadinya stack overflow jika kapasitas maksimum terlampaui [5].

Sementara itu, pendekatan berbasis linked list memungkinkan pengelolaan stack secara dinamis melalui alokasi memori yang fleksibel. Menurut Joko Musridho (2024), singly linked list terdiri dari simpul-simpul (nodes) yang masing-masing memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya [5]. Dengan pendekatan ini, ukuran stack tidak perlu ditentukan di awal karena setiap elemen baru dapat ditambahkan secara dinamis dengan memanfaatkan alokasi memori saat program berjalan. Hal ini membuat stack berbasis linked list lebih efisien ketika jumlah data bersifat berubah-ubah atau tidak dapat diprediksi. Selain itu, operasi push dan pop dapat dilakukan tanpa perlu pergeseran elemen seperti pada array, karena hanya melibatkan perubahan pointer antar simpul.

Meski demikian, pendekatan ini memiliki kelemahan berupa penggunaan memori tambahan untuk menyimpan pointer di setiap simpul, serta kompleksitas waktu O(n) untuk mengakses elemen tertentu karena harus dilakukan penelusuran dari simpul awal (head) hingga elemen yang diinginkan [5]. Oleh sebab itu, pemilihan antara pendekatan array atau linked list sangat bergantung pada kebutuhan dan karakteristik aplikasi yang dikembangkan.

Hasil penelitian oleh Setiyawan dkk. (2024) menunjukkan bahwa pendekatan array lebih unggul dalam hal kecepatan akses dan efisiensi memori untuk data berukuran tetap, sementara pendekatan linked list lebih unggul dalam fleksibilitas ukuran dan kemampuan pengelolaan data dinamis [5]. Dalam studi tersebut, implementasi stack berbasis array digunakan untuk mengonversi ekspresi matematika dari notasi infix ke postfix, sedangkan stack berbasis linked list digunakan untuk fitur undo/redo pada aplikasi pengolah teks. Perbandingan ini menunjukkan bahwa tidak ada satu pendekatan yang selalu lebih baik dari yang lain, karena efisiensi sangat dipengaruhi oleh konteks penggunaan.

Pendekatan stack array sangat sesuai untuk aplikasi dengan data berukuran tetap dan membutuhkan akses cepat, seperti penghitungan ekspresi aritmetika. Sebaliknya, stack linked list lebih sesuai untuk aplikasi dengan data dinamis yang sering mengalami perubahan ukuran, seperti sistem pengeditan teks atau manajemen memori dinamis. Naidu dan Prasad (2014) menegaskan bahwa efisiensi struktur data bergantung pada strategi pengelolaan memori dan jenis operasi yang dominan dilakukan pada sistem [1]. Sementara itu, Kaluti dkk. (2018) menambahkan bahwa implementasi stack berbasis linked list juga dapat dioptimalkan melalui pengelolaan pointer yang efisien untuk mengurangi overhead memori dan meningkatkan performa sistem [2].

Selain itu, Stokke, Barash, dan Järvi (2023) memperkenalkan pendekatan berbasis Domain-Specific Language (DSL) untuk manipulasi struktur data yang memungkinkan otomatisasi dalam operasi stack seperti push dan pop secara efisien tanpa campur tangan langsung dari programmer [3]. Pendekatan ini menegaskan pentingnya pemahaman mendalam terhadap konsep stack dan pengelolaan memori dinamis dalam pengembangan sistem modern. Dengan demikian, pemahaman terhadap kedua pendekatan ini tidak hanya penting untuk keperluan akademik, tetapi juga menjadi dasar dalam penerapan praktis di dunia industri, terutama pada sistem yang menuntut efisiensi tinggi dalam manajemen data dan memori.

## Guided 

### 1.1 stack.h

```h
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### 1.2 stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### 1.3 main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Kode program di atas merupakan implementasi struktur data stack menggunakan pendekatan singly linked list dalam bahasa pemrograman C++. Implementasi ini dibagi ke dalam tiga file utama, yaitu stack.h sebagai file header yang berisi deklarasi struktur data dan fungsi, stack.cpp sebagai file implementasi dari fungsi-fungsi tersebut, serta main.cpp sebagai program utama yang menjalankan dan menguji fungsionalitas dari struktur stack yang telah dibuat.

Pada file stack.h, didefinisikan dua struktur utama, yakni node dan stack. Struktur node terdiri atas dua elemen, yaitu variabel dataAngka yang menyimpan nilai bertipe integer dan pointer next yang menunjuk ke simpul berikutnya. Struktur ini merepresentasikan satu elemen dalam stack. Sementara itu, struktur stack hanya memiliki satu anggota, yaitu pointer top yang berfungsi sebagai penunjuk elemen teratas dari stack. Selain itu, dalam file ini juga dideklarasikan berbagai fungsi untuk operasi dasar stack, antara lain isEmpty() untuk memeriksa apakah stack kosong, createStack() untuk menginisialisasi stack baru, alokasi() dan dealokasi() untuk mengatur alokasi memori pada node, serta push(), pop(), update(), view(), dan searchData() sebagai fungsi manipulasi data dalam stack.

file stack.cpp berisi definisi fungsi-fungsi yang sebelumnya telah dideklarasikan dalam header. Fungsi isEmpty() berperan memeriksa apakah stack memiliki elemen atau tidak dengan melihat kondisi pointer top. Jika top bernilai Nil, maka stack dianggap kosong dan fungsi mengembalikan nilai true, sedangkan sebaliknya akan mengembalikan false. Fungsi createStack() digunakan untuk menginisialisasi stack baru dengan menjadikan pointer top bernilai Nil, yang menandakan bahwa stack belum memiliki elemen apa pun.

Selanjutnya, fungsi alokasi() bertanggung jawab membuat node baru di memori dengan menggunakan operator new. Node yang baru dialokasikan ini diberi nilai data sesuai dengan parameter yang diterima, dan pointer next-nya diatur agar bernilai Nil karena belum terhubung ke simpul lainnya. Fungsi dealokasi() digunakan untuk menghapus node yang tidak lagi digunakan dari memori dengan operator delete, sehingga mencegah kebocoran memori (memory leak).

Operasi push() bertugas menambahkan elemen baru ke bagian atas stack. Proses ini dilakukan dengan mengubah pointer next dari node baru agar menunjuk ke node yang sebelumnya berada di posisi teratas, kemudian memperbarui pointer top agar menunjuk ke node baru tersebut. Dengan demikian, elemen baru akan menjadi node teratas dalam stack. Program juga memberikan keluaran di layar yang menyatakan bahwa node berhasil ditambahkan.

Sebaliknya, fungsi pop() digunakan untuk menghapus elemen teratas dari stack. Fungsi ini terlebih dahulu memeriksa apakah stack kosong dengan memanggil isEmpty(). Jika kosong, program akan menampilkan pesan bahwa stack kosong dan tidak melakukan penghapusan. Namun, jika tidak kosong, node teratas akan disimpan sementara di variabel nodeHapus, kemudian pointer top diperbarui agar menunjuk ke node berikutnya. Node yang dihapus tersebut dihapus dari memori melalui fungsi dealokasi(), dan program menampilkan pesan bahwa elemen berhasil dihapus.

Fungsi update() digunakan untuk memperbarui nilai pada node tertentu berdasarkan posisi yang diberikan. Proses ini dimulai dengan pengecekan apakah stack kosong atau tidak. Jika tidak kosong, pointer bantu nodeBantu digunakan untuk menelusuri node dari posisi teratas hingga posisi yang dimaksud. Jika posisi ditemukan, program meminta pengguna untuk memasukkan nilai baru melalui input dan memperbarui data pada node tersebut. Bila posisi yang dimasukkan tidak valid, program akan menampilkan pesan kesalahan.

Fungsi view() berfungsi menampilkan seluruh elemen yang ada di dalam stack mulai dari elemen teratas hingga terbawah. Apabila stack kosong, maka akan ditampilkan pesan “List kosong!”. Namun, jika stack memiliki isi, fungsi akan melakukan iterasi melalui pointer next untuk mencetak semua nilai dataAngka dari setiap node hingga akhir daftar.

Sementara itu, fungsi searchData() digunakan untuk mencari data tertentu di dalam stack. Fungsi ini menelusuri seluruh node mulai dari bagian atas hingga akhir stack, sambil membandingkan nilai dataAngka setiap node dengan data yang dicari. Jika data ditemukan, program akan menampilkan posisi di mana data tersebut berada. Namun, jika tidak ditemukan, program memberikan pesan bahwa data yang dicari tidak ada di dalam stack.

Pada bagian main.cpp, program utama dimulai dengan pembuatan variabel listStack dan lima buah pointer node (nodeA hingga nodeE) yang akan digunakan untuk menyimpan elemen-elemen stack. Pertama-tama, fungsi createStack() dipanggil untuk menginisialisasi stack agar siap digunakan. Selanjutnya, masing-masing node dialokasikan nilai menggunakan fungsi alokasi() dengan data berupa angka 1 hingga 5. Setelah semua node dibuat, fungsi push() dipanggil secara berurutan untuk menambahkan setiap node ke dalam stack, sehingga node dengan nilai 5 akan menjadi elemen teratas karena ditambahkan terakhir.

Setelah proses push, fungsi view() dipanggil untuk menampilkan isi stack. Kemudian dilakukan dua kali operasi pop() untuk menghapus dua elemen teratas, yang secara otomatis mengurangi jumlah elemen dalam stack. Program kemudian kembali memanggil view() untuk menampilkan kondisi stack setelah penghapusan. Setelah itu, fungsi update() dipanggil tiga kali untuk memperbarui nilai pada posisi ke-2, ke-1, dan ke-4. Jika posisi yang dimasukkan tidak valid, program akan memberikan peringatan. Hasil perubahan ini kemudian ditampilkan melalui fungsi view().

Sebagai tahap akhir, fungsi searchData() dijalankan dua kali untuk mencari angka 4 dan 9 di dalam stack. Apabila data ditemukan, program menampilkan posisi kemunculan data tersebut. Jika tidak ditemukan, program memberikan informasi bahwa data tidak ada dalam stack. Dengan demikian, seluruh fungsi dasar stack seperti push, pop, update, view, dan search berhasil diimplementasikan secara menyeluruh.

### 2.1 stack.h

```h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

### 1.2 stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " <<  val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    } 
    if(posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top) {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

// void update(stackTable &s, int posisi){
//     if(isEmpty(s) == true){
//         cout << "Stack kosong!" << endl;
//     } else {
//         if(posisi <= 0){
//             cout << "Posisi tidak valid!" << endl;
//         } else {
//             // index = top - (posisi - 1)
//             int idx = s.top - (posisi - 1);
//             if(idx < 0 || idx > s.top){
//                 cout << "Posisi " << posisi << " tidak valid!" << endl;
//             } else {
//                 cout << "Update data posisi ke-" << posisi << endl;
//                 cout << "Masukkan angka : ";
//                 cin >> s.data[idx];
//                 cout << "Data berhasil diupdate!" << endl;
//             }
//             cout << endl;
//         }
//     }
// }

void view(stackTable s){
    if(isEmpty(s)){
        cout << "List kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

// void searchData(stackTable s, int data){
//     int posisi = 1;
//     bool found = false;
//     if(isEmpty(s)){
//         cout << "Stack kosong!" << endl;
//     } else {
//         cout << "Mencari data " << data << "..." << endl;
//         for(int i = s.top; i >= 0; i--){
//             if(s.data[i] == data){
//                 cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
//                 cout << endl;
//                 found = true;
//                 break;
//             }
//             posisi++;
//         }
//     }

//     if(found == false){
//         cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
//         cout << endl;
//     }
// }
```

### 1.3 main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Kode program di atas merupakan implementasi struktur data stack menggunakan pendekatan array dalam bahasa pemrograman C++. Program ini disusun menjadi tiga bagian utama, yaitu file header (stack.h) yang berfungsi mendefinisikan struktur data dan deklarasi fungsi, file implementasi (stack.cpp) yang berisi definisi dari fungsi-fungsi tersebut, serta file utama (main.cpp) yang digunakan untuk menjalankan dan menguji seluruh operasi dasar pada struktur stack. Seluruh kode menggunakan paradigma prosedural dan memanfaatkan konsep dasar stack yang mengikuti prinsip Last In First Out (LIFO), di mana elemen terakhir yang dimasukkan adalah elemen pertama yang akan dikeluarkan.

Pada file stack.h, struktur data utama yang digunakan adalah stackTable, yang terdiri atas dua komponen, yaitu sebuah array bernama data dengan ukuran tetap (MAX = 10) dan variabel top yang menunjukkan posisi elemen teratas pada stack. Nilai awal top ditetapkan -1, yang menandakan bahwa stack masih kosong. Selain struktur data, file ini juga berisi deklarasi fungsi-fungsi utama, seperti isEmpty() dan isFull() untuk memeriksa kondisi stack, createStack() untuk menginisialisasi stack baru, serta fungsi manipulasi data seperti push(), pop(), update(), view(), dan searchData(). Pendekatan ini mencerminkan prinsip modularitas, di mana definisi struktur dan deklarasi fungsi dipisahkan dari implementasi agar kode lebih mudah dibaca dan dipelihara.

file stack.cpp berisi definisi fungsi-fungsi yang telah dideklarasikan sebelumnya. Fungsi isEmpty() berfungsi memeriksa apakah stack dalam keadaan kosong dengan mengembalikan nilai benar (true) apabila variabel top bernilai -1. Sebaliknya, fungsi isFull() digunakan untuk menentukan apakah stack sudah penuh dengan membandingkan nilai top terhadap MAX - 1. Apabila nilai top telah mencapai batas tersebut, maka tidak ada lagi ruang untuk menambahkan elemen baru. Fungsi createStack() digunakan untuk menginisialisasi stack agar siap digunakan, dengan cara mengatur nilai top menjadi -1 sebagai tanda bahwa stack kosong.

Fungsi push() bertanggung jawab menambahkan elemen baru ke dalam stack. Sebelum menambahkan data, fungsi ini terlebih dahulu memeriksa apakah stack sudah penuh melalui pemanggilan isFull(). Jika penuh, maka program akan menampilkan pesan “Stack penuh!”. Namun, jika masih terdapat ruang, variabel top akan dinaikkan satu tingkat, dan data baru akan dimasukkan ke dalam posisi teratas melalui perintah s.data[s.top] = angka. Fungsi ini juga menampilkan pesan yang menandakan bahwa data berhasil ditambahkan.

Kebalikan dari push, fungsi pop() digunakan untuk menghapus elemen teratas dari stack. Fungsi ini juga melakukan pemeriksaan terlebih dahulu melalui isEmpty() untuk memastikan bahwa stack tidak kosong. Jika stack kosong, maka program menampilkan pesan peringatan bahwa tidak ada data yang dapat dihapus. Jika tidak, nilai pada posisi top disimpan sementara dalam variabel val, lalu top dikurangi satu untuk menandai bahwa elemen teratas telah dihapus. Setelah itu, program menampilkan pesan bahwa data berhasil dihapus dari stack.

Selanjutnya, fungsi update() digunakan untuk memperbarui data pada posisi tertentu di dalam stack. Fungsi ini dimulai dengan memeriksa kondisi stack; apabila kosong, program langsung menampilkan pesan “Stack kosong!”. Jika tidak kosong, fungsi menghitung posisi data yang akan diperbarui berdasarkan rumus index = top - (posisi - 1), di mana posisi dihitung dari bagian atas stack dengan sistem penomoran 1-based (posisi pertama berarti elemen paling atas). Jika posisi yang dimasukkan tidak valid—misalnya lebih kecil dari nol atau melebihi jumlah elemen—program akan menampilkan pesan kesalahan. Namun, apabila posisi valid, pengguna diminta memasukkan nilai baru yang kemudian menggantikan data lama di posisi tersebut. Fungsi ini juga menampilkan pesan konfirmasi bahwa pembaruan data berhasil dilakukan.

Fungsi view() berfungsi untuk menampilkan seluruh isi stack ke layar. Apabila stack kosong, maka akan ditampilkan pesan “List kosong!”. Jika tidak, fungsi melakukan iterasi dari elemen teratas (top) ke elemen terbawah (indeks 0), dan setiap elemen dicetak secara berurutan. Dengan demikian, pengguna dapat melihat seluruh isi stack sesuai urutan penyimpanannya.

Sementara itu, fungsi searchData() berperan dalam melakukan pencarian terhadap suatu nilai di dalam stack. Fungsi ini memulai pencarian dari elemen teratas dengan menelusuri seluruh elemen secara menurun hingga ke elemen paling bawah. Variabel posisi digunakan untuk melacak letak data yang dicari dalam urutan stack. Jika data ditemukan, program menampilkan posisi kemunculannya dan menghentikan pencarian. Namun, jika seluruh elemen telah diperiksa dan data tidak ditemukan, fungsi akan menampilkan pesan bahwa data tidak ada di dalam stack.

file main.cpp berfungsi sebagai bagian utama program yang menguji seluruh operasi stack yang telah diimplementasikan. Pertama-tama, variabel s bertipe stackTable dideklarasikan, kemudian diinisialisasi menggunakan fungsi createStack() agar siap digunakan. Setelah itu, fungsi push() dipanggil beberapa kali untuk menambahkan data berupa angka 1 hingga 5 ke dalam stack. Setelah proses penambahan selesai, fungsi view() digunakan untuk menampilkan isi stack ke layar, sehingga pengguna dapat melihat urutan elemen setelah proses push.

Selanjutnya, dua kali operasi pop() dilakukan untuk menghapus dua elemen teratas dari stack. Setelah penghapusan, fungsi view() kembali dipanggil untuk menampilkan kondisi stack terkini. Setelah itu, fungsi update() digunakan untuk memperbarui data pada posisi ke-2, ke-1, dan ke-4. Jika posisi yang dimasukkan valid, maka data di posisi tersebut akan diperbarui sesuai input pengguna. Program kemudian menampilkan isi stack setelah pembaruan menggunakan view(). Pada bagian akhir, fungsi searchData() dijalankan dua kali untuk mencari nilai 4 dan 9. Apabila nilai ditemukan, program menampilkan posisinya; jika tidak ditemukan, ditampilkan pesan bahwa data tidak tersedia dalam stack.


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY di dalam file “stack.h”. Lalu, buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”.

#### stack.h

```h
#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top; 
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void push(Stack &s, int angka);
void pop(Stack &s);
void printInfo(Stack s);
void balikstack(Stack &s);

#endif
```

##### stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.top == MAX - 1;
}

void createStack(Stack &s){
    s.top = -1;
}

void push(Stack &s, int angka){
    if(isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " <<  val << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack s){
    if(isEmpty(s)){
        cout << "List kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void balikstack(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    
    int temp[MAX];
    int count = 0;
    
    while(!isEmpty(s)){
        temp[count] = s.data[s.top];
        s.top--;
        count++;
    }
    
    for(int i = 0; i < count; i++){
        s.top++;
        s.data[s.top] = temp[i];
    }
}
```

##### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);
    printInfo(S);

    cout<<"balik stack"<<endl;
    balikstack(S);
    printInfo(S);
    
return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week7/output/output-unguided1.png)

Kode program di atas merupakan implementasi struktur data stack menggunakan pendekatan array statis dalam bahasa pemrograman C++. Program ini terdiri atas tiga file utama, yaitu stack.h sebagai file header yang berisi definisi struktur data dan deklarasi fungsi, stack.cpp yang memuat implementasi dari fungsi-fungsi tersebut, serta main.cpp yang berperan sebagai program utama untuk menguji berbagai operasi dasar yang terdapat pada struktur stack. Seluruh implementasi ini mengikuti prinsip kerja Last In First Out (LIFO), di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan.

Pada file stack.h, struktur data utama yang digunakan adalah Stack, yang terdiri atas dua elemen, yaitu array data dengan kapasitas maksimal MAX = 20 dan variabel top yang berfungsi sebagai penunjuk posisi elemen teratas dalam stack. Jika top bernilai -1, berarti stack dalam keadaan kosong. Selain itu, pada file ini juga dideklarasikan sejumlah fungsi yang berperan untuk melakukan operasi terhadap stack, seperti createStack() untuk inisialisasi, isEmpty() untuk memeriksa apakah stack kosong, isFull() untuk mengetahui apakah stack telah mencapai kapasitas maksimum, serta fungsi manipulasi seperti push(), pop(), printInfo(), dan balikstack() yang mengatur penambahan, penghapusan, penampilan, dan pembalikan urutan elemen dalam stack.

file stack.cpp berisi implementasi lengkap dari fungsi-fungsi tersebut. Fungsi isEmpty() mengembalikan nilai true apabila nilai top sama dengan -1, yang berarti tidak ada data di dalam stack. Sebaliknya, fungsi isFull() mengembalikan nilai true apabila top bernilai MAX - 1, yang menunjukkan bahwa stack telah penuh dan tidak dapat menampung data tambahan. Fungsi createStack() digunakan untuk menginisialisasi stack dengan mengatur nilai awal top menjadi -1 agar dapat digunakan dalam operasi berikutnya.

Fungsi push() digunakan untuk menambahkan elemen baru ke dalam stack. Sebelum menambahkan data, fungsi ini terlebih dahulu memeriksa apakah stack sudah penuh dengan memanggil isFull(). Jika stack penuh, program akan menampilkan pesan “Stack penuh!”. Namun, apabila masih terdapat ruang, variabel top dinaikkan satu tingkat, dan nilai baru disimpan pada posisi teratas array data. Setelah itu, pesan konfirmasi ditampilkan untuk menunjukkan bahwa proses penambahan berhasil.

Fungsi pop() berfungsi untuk menghapus elemen teratas dari stack. Sebelum melakukan penghapusan, program memeriksa apakah stack kosong melalui pemanggilan isEmpty(). Jika stack kosong, maka akan muncul pesan “Stack kosong!”. Namun, jika stack berisi elemen, nilai pada posisi top disimpan sementara dalam variabel val, kemudian nilai top dikurangi satu untuk menandakan bahwa elemen tersebut telah dihapus. Program kemudian menampilkan pesan bahwa data dengan nilai tertentu telah berhasil dihapus dari stack.

Fungsi printInfo() digunakan untuk menampilkan seluruh isi stack ke layar. Fungsi ini memeriksa apakah stack kosong sebelum menampilkan isi. Jika kosong, maka program menampilkan pesan “List kosong!”. Jika tidak, program menampilkan elemen stack dari posisi teratas hingga terbawah dengan urutan menurun, disertai label “[TOP]” sebagai penanda elemen paling atas. Cara penulisan seperti ini membantu pengguna memahami urutan data di dalam stack sesuai dengan prinsip LIFO.

Fungsi balikstack() merupakan tambahan yang memberikan kemampuan untuk membalik urutan elemen di dalam stack. Fungsi ini dimulai dengan pengecekan kondisi stack. Jika stack kosong, maka akan muncul pesan “Stack kosong!” dan proses dihentikan. Namun, jika berisi data, fungsi ini membuat sebuah array sementara temp[] untuk menyimpan elemen-elemen stack secara terbalik. Proses pembalikan dilakukan dengan dua tahap. Tahap pertama adalah memindahkan seluruh elemen dari stack ke dalam array temp sambil menurunkan nilai top hingga stack menjadi kosong. Tahap kedua adalah memasukkan kembali elemen dari array temp ke dalam stack satu per satu, sehingga urutan datanya menjadi kebalikan dari sebelumnya. Dengan cara ini, fungsi balikstack() mampu merepresentasikan proses inversi data secara manual tanpa menggunakan struktur data tambahan seperti queue atau linked list.

Pada file main.cpp, program utama dimulai dengan pembuatan objek Stack S dan pemanggilan fungsi createStack(S) untuk menginisialisasi stack. Setelah itu, dilakukan serangkaian operasi push() dan pop() untuk menambahkan serta menghapus elemen. Data yang dimasukkan ke dalam stack adalah angka 3, 4, 8, 2, 3, dan 9, sedangkan dua elemen di antaranya dihapus menggunakan fungsi pop(). Setiap kali data ditambahkan atau dihapus, program menampilkan pesan untuk memberikan umpan balik kepada pengguna.

Setelah proses tersebut, fungsi printInfo() dipanggil untuk menampilkan seluruh isi stack pada kondisi saat itu. Selanjutnya, program menampilkan teks “balik stack” sebagai penanda bahwa fungsi balikstack() akan dijalankan. Setelah proses pembalikan selesai, printInfo() kembali dipanggil untuk menampilkan isi stack yang kini sudah berbalik urutannya. Dari hasil eksekusi, terlihat bahwa elemen yang sebelumnya berada di posisi paling atas kini berpindah ke bagian paling bawah, dan sebaliknya.


### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

#### stack.h

```h
#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top; 
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void push(Stack &s, int angka);
void pop(Stack &s);
void printInfo(Stack s);
void balikstack(Stack &s);

void pushAscending(Stack &s, int x);

#endif
```

##### stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.top == MAX - 1;
}

void createStack(Stack &s){
    s.top = -1;
}

void push(Stack &s, int angka){
    if(isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " <<  val << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack s){
    if(isEmpty(s)){
        cout << "List kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void balikstack(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    
    int temp[MAX];
    int count = 0;
    
    while(!isEmpty(s)){
        temp[count] = s.data[s.top];
        s.top--;
        count++;
    }
    
    for(int i = 0; i < count; i++){
        s.top++;
        s.data[s.top] = temp[i];
    }
}

void pushAscending(Stack &s, int x){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
        return;
    }
    
    Stack temp;
    createStack(temp);
    
    while(!isEmpty(s) && s.data[s.top] > x){
        temp.top++;
        temp.data[temp.top] = s.data[s.top];
        s.top--;
    }
    
    s.top++;
    s.data[s.top] = x;
    
    while(!isEmpty(temp)){
        s.top++;
        s.data[s.top] = temp.data[temp.top];
        temp.top--;
    }
    
    cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
}
```

##### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);

    cout<<"balik stack"<<endl;
    balikstack(S);
    printInfo(S);

return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week7/output/output-unguided2.png)

Prosedur pushAscending() pada kode di atas merupakan pengembangan dari operasi dasar push pada struktur data stack berbasis array, yang memiliki fungsi tambahan untuk menjaga agar data di dalam stack selalu tersusun secara menaik (ascending). Dengan kata lain, prosedur ini tidak hanya menambahkan elemen baru ke puncak stack seperti pada push konvensional, tetapi juga memastikan bahwa setelah proses penyisipan selesai, urutan elemen dari bawah ke atas stack tetap terjaga dalam bentuk terurut dari nilai terkecil hingga terbesar.

Secara konseptual, prosedur ini mengombinasikan dua operasi utama dalam satu mekanisme, yaitu penyisipan terurut (ordered insertion) dan manipulasi tumpukan sementara (temporary stack management). Untuk mencapai tujuan tersebut, algoritma pushAscending() menggunakan satu stack tambahan bernama temp sebagai media penyimpanan sementara selama proses penyisipan berlangsung.

Langkah pertama dalam prosedur pushAscending() adalah melakukan pemeriksaan kondisi stack menggunakan fungsi isFull(). Pemeriksaan ini penting untuk memastikan bahwa masih terdapat ruang kosong sebelum data baru dimasukkan. Jika stack telah penuh, fungsi akan menampilkan pesan “Stack penuh!” dan menghentikan proses penyisipan menggunakan perintah return. Hal ini bertujuan untuk mencegah terjadinya overflow, yaitu kondisi ketika data ditambahkan melebihi kapasitas maksimum yang telah ditentukan.

Apabila stack masih memiliki ruang, langkah berikutnya adalah membuat stack sementara (temp) menggunakan fungsi createStack(temp). Stack ini berfungsi sebagai wadah penampung sementara bagi elemen-elemen yang nilainya lebih besar daripada elemen baru yang akan dimasukkan (x). Tujuannya adalah agar elemen baru dapat diletakkan di posisi yang tepat sehingga urutan menaik tetap terjaga.

Selanjutnya, dilakukan perulangan while dengan kondisi !isEmpty(s) && s.data[s.top] > x. Kondisi ini berarti bahwa selama stack utama s tidak kosong dan elemen teratasnya lebih besar dari nilai yang akan dimasukkan, maka elemen tersebut akan dipindahkan ke stack sementara temp. Proses ini dilakukan dengan menambah nilai top pada stack temp dan menyalin nilai dari elemen teratas s ke posisi teratas temp. Kemudian, top dari stack utama dikurangi satu untuk menandakan bahwa elemen tersebut telah dihapus sementara. Dengan demikian, setelah perulangan berakhir, posisi yang sesuai untuk menyisipkan elemen baru x telah ditemukan, yaitu ketika stack utama kosong atau nilai elemen teratasnya lebih kecil atau sama dengan x.

Setelah menemukan posisi yang tepat, nilai x dimasukkan ke dalam stack utama menggunakan langkah s.top++; s.data[s.top] = x;. Pada titik ini, elemen baru telah ditambahkan ke dalam stack dalam posisi yang sesuai dengan urutan menaik. Namun, sebagian elemen sebelumnya masih tersimpan di dalam stack sementara temp, sehingga langkah berikutnya adalah mengembalikan elemen-elemen tersebut ke stack utama agar strukturnya kembali lengkap.

Proses pengembalian dilakukan menggunakan perulangan while(!isEmpty(temp)), di mana setiap elemen dari stack temp akan dipindahkan kembali ke stack utama. Karena stack bersifat LIFO (Last In, First Out), urutan elemen yang dikembalikan akan sama seperti urutan semula sebelum dilakukan penyisipan. Setiap elemen dari temp ditambahkan kembali ke stack utama dengan menaikkan nilai top dan menyalin data dari temp.data[temp.top]. Setelah proses ini selesai, semua elemen yang sebelumnya dipindahkan ke stack sementara telah dikembalikan, dan urutan stack kini kembali lengkap dengan elemen x berada di posisi yang benar secara menaik.

Sebagai langkah terakhir, prosedur ini menampilkan pesan ke layar berupa “Data [x] berhasil ditambahkan ke dalam stack!”, yang menandakan bahwa proses penyisipan terurut telah selesai dengan sukses.


### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

#### stack.h

```h
#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top; 
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void push(Stack &s, int angka);
void pop(Stack &s);
void printInfo(Stack s);
void balikstack(Stack &s);

void pushAscending(Stack &s, int x);

void getInputStream(Stack &s);

#endif
```

##### stack.cpp

```C++
#include "stack.h"
#include <iostream>
#include <cmath>

using namespace std;

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.top == MAX - 1;
}

void createStack(Stack &s){
    s.top = -1;
}

void push(Stack &s, int angka){
    if(isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " <<  val << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack s){
    if(isEmpty(s)){
        cout << "List kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void balikstack(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    
    int temp[MAX];
    int count = 0;
    
    while(!isEmpty(s)){
        temp[count] = s.data[s.top];
        s.top--;
        count++;
    }
    
    for(int i = 0; i < count; i++){
        s.top++;
        s.data[s.top] = temp[i];
    }
}

void pushAscending(Stack &s, int x){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
        return;
    }
    
    Stack temp;
    createStack(temp);
    
    while(!isEmpty(s) && s.data[s.top] > x){
        temp.top++;
        temp.data[temp.top] = s.data[s.top];
        s.top--;
    }
    
    s.top++;
    s.data[s.top] = x;
    
    while(!isEmpty(temp)){
        s.top++;
        s.data[s.top] = temp.data[temp.top];
        temp.top--;
    }
    
    cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
}

void getInputStream(Stack &s){
    int angka, x, bagi, digit, awal;
    cin >> angka;
    
    x = angka;
    digit = 0;
    while(x > 0){
        digit++;
        x /= 10;
    }
    
    bagi = pow(10, digit - 1);
    
    while(bagi > 0 && !isFull(s)){
        awal = (angka / bagi) % 10;
        push(s, awal);
        bagi /= 10;
    }
}
```

##### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);   

    cout<<"balik stack"<<endl;
    balikstack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week7/output/output-unguided3.png)

Prosedur getInputStream() pada kode di atas berfungsi untuk mengonversi sebuah bilangan bulat yang dimasukkan oleh pengguna menjadi urutan digit yang disimpan satu per satu ke dalam struktur data stack. Prosedur ini menggabungkan proses pemrosesan numerik dengan konsep dasar stack yang menggunakan prinsip Last In First Out (LIFO). Tujuan utama dari prosedur ini adalah memecah angka menjadi bagian-bagian penyusunnya (digit-digit) dan menempatkannya ke dalam stack agar dapat diolah atau ditampilkan kembali sesuai kebutuhan.

Proses dimulai ketika pengguna memasukkan sebuah bilangan bulat melalui input standar (keyboard). Nilai tersebut dibaca dan disimpan dalam variabel angka. Nilai ini kemudian disalin ke dalam variabel x, yang akan digunakan untuk menghitung jumlah digit dalam angka tersebut tanpa mengubah nilai aslinya. Untuk menghitung jumlah digit, dilakukan proses pembagian berulang dengan 10 di dalam perulangan while(x > 0). Setiap kali angka dibagi 10, nilai digit bertambah satu. Setelah perulangan selesai, variabel digit berisi jumlah digit dari bilangan yang dimasukkan oleh pengguna.

Tahapan berikutnya adalah menentukan nilai pembagi awal (bagi) yang akan digunakan untuk memisahkan setiap digit dari bilangan tersebut. Nilai bagi dihitung dengan rumus pow(10, digit - 1), yang berarti jika angka memiliki lima digit, maka pembagi awal bernilai 10⁴ = 10000. Dengan pembagi ini, digit paling signifikan (digit pertama dari kiri) dapat diambil terlebih dahulu menggunakan operasi pembagian integer.

Perulangan berikutnya, while(bagi > 0 && !isFull(s)), berfungsi untuk mengekstraksi setiap digit dari bilangan dan memasukkannya satu per satu ke dalam stack. Pada setiap iterasi, variabel awal menyimpan hasil (angka / bagi) % 10, yang merupakan cara untuk mengambil digit tertentu dari bilangan tersebut. Misalnya, jika angka yang dimasukkan adalah 5432 dan nilai bagi saat ini adalah 1000, maka ekspresi (5432 / 1000) % 10 menghasilkan 5, yaitu digit pertama dari bilangan. Nilai awal tersebut kemudian dimasukkan ke dalam stack melalui pemanggilan prosedur push(s, awal). Setelah satu digit dimasukkan, nilai bagi dibagi 10 agar perulangan berikutnya dapat memproses digit selanjutnya. Proses ini berlanjut hingga seluruh digit dari bilangan dimasukkan ke dalam stack atau hingga stack mencapai kapasitas maksimumnya.

Melalui pendekatan ini, setiap digit angka dimasukkan ke dalam stack sesuai urutan dari digit paling kiri hingga digit paling kanan. Sebagai contoh, jika pengguna memasukkan angka 1234, maka elemen yang disimpan di dalam stack secara berurutan dari bawah ke atas adalah 1, 2, 3, 4, dengan 4 berada di posisi teratas. Susunan ini akan memberikan efek terbalik ketika ditampilkan menggunakan fungsi printInfo() karena sifat dasar stack yang menampilkan elemen dari atas ke bawah. Dengan demikian, bila stack kemudian dibalik menggunakan fungsi balikstack(), urutan digit yang ditampilkan akan kembali menjadi urutan aslinya, yaitu dari 1 ke 4.

Prosedur getInputStream() juga memperlihatkan penerapan praktis dari kombinasi antara manipulasi numerik dan konsep penyimpanan berbasis stack. Melalui perhitungan matematis menggunakan pembagian dan operasi modulus, setiap digit dari angka dapat diisolasi tanpa harus mengubah nilai awal secara langsung. Penggunaan stack sebagai tempat penyimpanan memungkinkan pengelolaan digit secara terstruktur dan memudahkan proses pembalikan urutan data bila diperlukan. Selain itu, prosedur ini tetap memperhatikan keamanan program dengan memeriksa kondisi stack menggunakan isFull(s) untuk menghindari terjadinya kesalahan overflow saat jumlah digit melebihi kapasitas maksimum yang diizinkan.


## Kesimpulan
Dari seluruh pembahasan dan implementasi yang telah dilakukan, dapat disimpulkan bahwa stack adalah salah satu struktur data paling fundamental dan berguna dalam dunia pemrograman. Stack bekerja dengan prinsip Last In First Out (LIFO), artinya data yang terakhir dimasukkan akan menjadi data pertama yang diambil kembali. Konsep sederhana ini ternyata memiliki banyak penerapan penting, mulai dari pengelolaan memori, pembalikan data, hingga proses komputasi yang memerlukan urutan eksekusi tertentu.

Dalam percobaan yang dilakukan, digunakan dua jenis pendekatan utama, yaitu stack menggunakan array dan stack menggunakan singly linked list. Keduanya memiliki kelebihan dan kekurangan masing-masing. Stack berbasis array lebih mudah diimplementasikan dan memiliki waktu akses yang cepat karena data disimpan secara berurutan di memori. Namun, kekurangannya terletak pada ukuran yang tetap (statis), sehingga tidak fleksibel saat jumlah data berubah-ubah. Sebaliknya, stack berbasis linked list lebih fleksibel karena dapat menambah atau menghapus data tanpa batasan ukuran, tetapi membutuhkan memori tambahan untuk menyimpan pointer antar node.

Dari sisi implementasi kode, setiap fungsi utama seperti push, pop, update, view, dan searchData berperan penting dalam menggambarkan operasi dasar stack. Selain itu, beberapa fungsi tambahan seperti pushAscending, balikstack, dan getInputStream menunjukkan bagaimana konsep stack bisa dikembangkan lebih jauh.
Fungsi pushAscending misalnya, menambahkan elemen ke dalam stack dengan tetap menjaga urutan data secara menaik, sehingga tidak hanya memasukkan data secara acak. Fungsi balikstack digunakan untuk membalik urutan isi stack, menunjukkan bagaimana data bisa dimanipulasi tanpa mengubah prinsip LIFO. Sedangkan getInputStream memperlihatkan bagaimana angka yang dimasukkan pengguna dapat dipecah menjadi digit-digit terpisah dan dimasukkan ke dalam stack satu per satu, sebuah contoh penerapan logika stack dalam pemrosesan data numerik.

Secara keseluruhan, implementasi ini menunjukkan bahwa memahami struktur data stack tidak hanya penting dari sisi teori, tetapi juga sangat bermanfaat dalam praktik pemrograman sehari-hari. Stack membantu menyelesaikan berbagai permasalahan yang berkaitan dengan urutan data, penyimpanan sementara, hingga efisiensi pemrosesan. Melalui penerapan fungsi-fungsi yang dibuat, terlihat bahwa konsep yang sederhana seperti LIFO dapat dikembangkan menjadi berbagai bentuk manipulasi data yang lebih kompleks dan bermanfaat.

## Referensi
[1] Naidu, D., & Prasad, A. (2014). Implementation of Enhanced Singly Linked List Equipped with DLL Operations: An Approach Towards Enormous Memory Saving. International Journal of Future Computer and Communication, 3(2), 98–101. https://doi.org/10.7763/IJFCC.2014.V3.276
<br>
[2] Kaluti, M. K., Govindaraju, Y., Shashank, A. R., & Harshith, K. S. (2018). Dynamic Implementation of Stack Using Single Linked List. International Research Journal of Engineering and Technology (IRJET), 5(3), 1923–1926. https://www.irjet.net/archives/V5/i3/IRJET-V5I3434.pdf
</br>
<br>
[3] Stokke, K. A., Barash, M., & Järvi, J. (2023). A Domain-Specific Language for Structure Manipulation. Journal of Computer Languages, 74, 101175. https://doi.org/10.1016/j.cola.2023.101175
</br>
<br>
[4] Ranti, S. (2022). Pengertian Stack dan Queue serta Contoh Penerapannya. Kompas.com. https://tekno.kompas.com/read/2022/12/01/02150047/pengertian-stack-dan-queue-serta-contoh-penerapannya?page=all
</br>
[5] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. Jurnal Informatika Universitas Pamulang, 5(2), 484–497.  