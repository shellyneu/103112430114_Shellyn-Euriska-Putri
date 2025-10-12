# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Abstract Data Type (ADT) atau tipe data abstrak merupakan konsep dasar dalam struktur data yang memisahkan antara cara penggunaan dan cara implementasi suatu data. ADT berfokus pada apa yang dapat dilakukan terhadap data tanpa memperlihatkan bagaimana data tersebut diolah. Konsep ini mendukung prinsip encapsulation dan modularitas dalam pemrograman, sehingga memudahkan perancangan program yang terstruktur dan mudah dipelihara [1].

Dalam bahasa C++, penerapan ADT sering berkaitan dengan penggunaan struct, pointer, dan reference sebagai representasi data kompleks. Struct memungkinkan pengelompokan beberapa variabel dengan tipe berbeda menjadi satu kesatuan logis, sehingga mempermudah pengorganisasian data dalam program. Sementara itu, pointer berfungsi menyimpan alamat memori suatu variabel, memberikan akses langsung terhadap data yang direferensikan. Konsep reference menawarkan alternatif yang lebih aman dari pointer karena tidak memerlukan dereferensi eksplisit dan menjamin keterkaitan langsung dengan variabel aslinya [2].

Pemahaman hubungan antara ADT dan mekanisme memori melalui pointer dan reference sangat penting dalam membangun sistem yang efisien. Dengan pendekatan ini, program dapat mengelola data secara dinamis tanpa pemborosan memori, sekaligus menjaga konsistensi nilai antar variabel. Selain itu, penerapan struct dalam desain ADT juga mendukung modularitas, di mana setiap struktur dapat memiliki fungsi atau operasi spesifik yang merepresentasikan perilaku data tersebut [3].


## Guided 

### 1. Struct

```C++
#include<iostream>

using namespace std;

struct mahasiswa
{
    string nama;
    float nilai, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Masukkan nilai mahasiswa: ";
    cin >> m.nilai;
    cout << "Masukkan nilai 2 mahasiswa: ";
    cin >> m.nilai2;
};

float rata2(mahasiswa m) {
    return float(m.nilai + m.nilai2)/2;
};

int main() {
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan procedure

    cout << "Rata-rata: " << rata2(mhs); //pemanggilan function

    return 0;
}
```
Program ini mendefinisikan sebuah struktur mahasiswa yang berisi nama dan dua nilai. Fungsi inputMhs digunakan untuk menerima input nama dan dua nilai dari pengguna melalui terminal. Fungsi rata2 menghitung rata-rata dari kedua nilai yang dimasukkan. Di dalam fungsi main, sebuah variabel bertipe mahasiswa dibuat, lalu data mahasiswa diinput menggunakan inputMhs, dan hasil rata-rata kedua nilai ditampilkan ke layar menggunakan fungsi rata2. Program ini mendemonstrasikan penggunaan struct, input/output dasar, dan pemisahan logika ke dalam fungsi untuk meningkatkan keterbacaan kode.


### 2.1. pelajaran.h

```h
// Header guard digunakan untuk mencegah file header yang sama
// di-include lebih dari sekali dalam satu program.
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

// deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel);

// prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif 
```
Kode di atas adalah contoh header file C++ yang menggunakan header guard (#ifndef, #define, #endif) untuk mencegah duplikasi saat file di-include. Di dalamnya terdapat deklarasi ADT (Abstract Data Type) berupa struct pelajaran yang menyimpan nama dan kode mata pelajaran. Selain itu, terdapat deklarasi fungsi create_pelajaran untuk membuat data pelajaran baru dan prosedur tampil_pelajaran untuk menampilkan data pelajaran ke layar. Penggunaan #include <iostream> dan using namespace std memungkinkan pemakaian tipe data string dan fungsi input/output standar C++.


### 2.2. pelajaran.cpp

```C++
#include "pelajaran.h"

// Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodePel;
    return p;
}

// Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran: " << pel.namaMapel << endl;
    cout << "Nilai : " << pel.kodeMapel << endl;
}
```
Kode di atas merupakan implementasi dua fungsi dalam bahasa C++ yang berkaitan dengan struktur data pelajaran. Fungsi create_pelajaran menerima dua parameter bertipe string, yaitu nama mata pelajaran dan kode pelajaran, lalu menginisialisasi sebuah objek pelajaran dengan nilai tersebut dan mengembalikannya. Fungsi kedua, tampil_pelajaran, adalah prosedur yang menerima sebuah objek pelajaran sebagai parameter dan menampilkan nama mata pelajaran serta kode pelajaran ke layar menggunakan cout. Kode ini mengasumsikan bahwa struktur pelajaran dan kode yang diperlukan seperti iostream dan string telah didefinisikan di file header "pelajaran.h".


### 2.3. main.cpp

```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodePel);

    tampil_pelajaran(pel);

    return 0;
}
```
Kode ini mendefinisikan fungsi utama (main) yang membuat sebuah objek pelajaran dengan nama "Struktur Data" dan kode "STD" menggunakan fungsi create_pelajaran, yang didefinisikan di file header "pelajaran.h". Setelah objek pelajaran dibuat, fungsi tampil_pelajaran dipanggil untuk menampilkan informasi pelajaran tersebut ke layar. Program menggunakan namespace std agar dapat menggunakan tipe data dan fungsi standar C++ seperti string dan cout tanpa perlu menuliskan prefix std::. Kode ini merupakan contoh sederhana penggunaan fungsi dan objek dalam pemrograman C++ untuk mengelola data pelajaran.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3∗uts+0.4∗uas+0.3∗tugas.

```C++
#include<iostream>
using namespace std;

struct mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

void input(mahasiswa &m) {
    cout << "Nama: "; cin >> m.nama;
    cout << "NIM: "; cin >> m.nim;
    cout << "UTS: "; cin >> m.uts;
    cout << "UAS: "; cin >> m.uas;
    cout << "Tugas: "; cin >> m.tugas;
}

float hitungNilai(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

int main() {
    mahasiswa mhs[10];
    int n;
    
    cout << "Jumlah mahasiswa (max 10): "; cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "\nMahasiswa " << i+1 << ":\n";
        input(mhs[i]);
        mhs[i].nilaiAkhir = hitungNilai(mhs[i]);
    }
    
    cout << "\nHASIL:\n";
    for(int i = 0; i < n; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ") - Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week3/output/output-unguided1.png)

Kode ini membuat program sederhana untuk mengelola data mahasiswa dan menghitung nilai akhir berdasarkan nilai UTS, UAS, dan tugas. Program menggunakan struktur mahasiswa untuk menyimpan nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Fungsi input digunakan untuk menerima data mahasiswa dari pengguna, sedangkan fungsi hitungNilai menghitung nilai akhir dengan bobot 30% UTS, 40% UAS, dan 30% tugas. Di fungsi main, pengguna diminta memasukkan jumlah mahasiswa (maksimal 10), lalu data setiap mahasiswa diinput dan nilai akhirnya dihitung. Hasil akhir berupa nama, NIM, dan nilai akhir setiap mahasiswa ditampilkan ke layar.


### 2. Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h". Lalu buatlah implementasi ADT pelajaran pada file "pelajaran.cpp". Terakhir, cobalah hasil implementasi ADT pada file "main.cpp".

#### pelajaran.h
```h
// Header guard digunakan untuk mencegah file header yang sama
// di-include lebih dari sekali dalam satu program.
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

// deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel);

// prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif 
```

#### pelajaran.cpp
```C++
#include "pelajaran.h"

// Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodePel;
    return p;
}

// Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran: " << pel.namaMapel << endl;
    cout << "Nilai : " << pel.kodeMapel << endl;
}
```

#### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodePel);

    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2-1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week3/output/output-unguided2.png)

Program ini terdiri dari tiga file utama yang mengimplementasikan sebuah ADT (Abstract Data Type) untuk pelajaran. File pelajaran.h mendefinisikan struktur data pelajaran yang menyimpan nama dan kode pelajaran, serta deklarasi fungsi untuk membuat dan menampilkan data pelajaran. File pelajaran.cpp berisi implementasi fungsi create_pelajaran yang menginisialisasi objek pelajaran dengan nama dan kode yang diberikan, serta prosedur tampil_pelajaran untuk menampilkan informasi pelajaran ke layar. Pada file main.cpp, program membuat sebuah objek pelajaran dengan nama "Struktur Data" dan kode "STD", lalu menampilkan data tersebut menggunakan prosedur yang telah dibuat. Program ini mendemonstrasikan konsep pemisahan kode menggunakan header dan source file, serta penggunaan ADT untuk pengelolaan data sederhana.


### 3. Buatlah program dengan ketentuan:
### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include<iostream>
using namespace std;

void tampil(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int x, int y) {
    int temp = arr1[x][y];
    arr1[x][y] = arr2[x][y];
    arr2[x][y] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr1[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int arr2[3][3] = {{10,11,12}, {13,14,15}, {16,17,18}};

    int x = 10, y = 20;
    int *ptr1 = &x, *ptr2 = &y;
    
    cout << "Array 1:\n"; tampil(arr1);
    cout << "Array 2:\n"; tampil(arr2);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl;
    
    tukarArray(arr1, arr2, 1, 1);
    cout << "\nSetelah ditukar:\n";
    cout << "Array 1:\n"; tampil(arr1);
    cout << "Array 2:\n"; tampil(arr2);
    
    tukarPointer(ptr1, ptr2);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl;
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_3-1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week3/output/output-unguided3.png)

Program ini mendemonstrasikan cara menukar elemen pada array dua dimensi dan nilai variabel menggunakan pointer. Dua array 3x3 arr1 dan arr2 diinisialisasi dengan nilai berbeda, lalu fungsi tampil digunakan untuk menampilkan isi masing-masing array. Fungsi tukarArray menukar elemen array pada posisi tertentu, sedangkan fungsi tukarPointer menukar nilai dua variabel x dan y melalui pointer. Setelah proses penukaran, isi array dan nilai variabel ditampilkan kembali untuk memperlihatkan perubahan yang terjadi. Program ini memperkenalkan konsep passing by reference pada array dan pointer dalam C++.


## Kesimpulan
Pada praktikum ini, telah dipelajari konsep Abstract Data Type (ADT) yang memisahkan antara cara penggunaan dan cara implementasi data, serta penerapannya dalam pemrograman C++ menggunakan struct, pointer, dan reference. Melalui latihan guided dan unguided, dapat dipahami bagaimana mendefinisikan dan mengelola data kompleks menggunakan struct, membuat ADT pelajaran dengan pemisahan kode pada header dan source file, serta memanipulasi array dan pointer untuk pertukaran data. Praktikum ini juga menekankan pentingnya modularitas dan encapsulation dalam desain program, serta pengelolaan memori yang efisien melalui pointer dan reference. Dengan pemahaman ini, dapat memiliki fondasi yang kuat untuk mempelajari struktur data dan algoritma yang lebih kompleks di tahap berikutnya.


## Referensi
[1] Modul Struktur Data. (2025). Modul 3 – Abstract Data Type (ADT). Program Studi Teknik Informatika, [Nama Institusi].
<br>
[2] Nugroho, A. Y., & Sutanto, N. H. (2024). Exploring the Code Foundation: A Literature Review of Data Structures in C++. International Journal of Mechanical, Industrial and Control Systems Engineering, 1(3), 24–37. https://doi.org/10.61132/ijmicse.v1i3.47
</br>
[3] Ahmed, H. E. (2018). Evaluation of C++ as Object-Oriented Programming Language Compared to Java. International Journal of Scientific Engineering and Applied Science (IJSEAS), 4(1), 16–22. http://www.ijseas.com