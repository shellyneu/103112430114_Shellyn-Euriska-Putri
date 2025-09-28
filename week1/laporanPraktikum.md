# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan pengembangan dari bahasa C yang menambahkan konsep pemrograman berorientasi objek sehingga lebih fleksibel digunakan dalam pengembangan perangkat lunak modern. Dalam konteks pendidikan, C++ banyak dipakai sebagai bahasa dasar untuk melatih keterampilan logika, pemecahan masalah, serta pemahaman algoritma mahasiswa di berbagai jurusan teknik. Penelitian yang dilakukan di Universitas Negeri Semarang menunjukkan bahwa penggunaan C++ pada mata kuliah dasar pemrograman mampu meningkatkan keterampilan analitis, berpikir kritis, serta kemampuan adaptasi mahasiswa terhadap tantangan di bidang teknik elektro [2]. Hal ini sejalan dengan studi di Undiksha yang mengembangkan media pembelajaran C++ interaktif, berisi materi mulai dari sejarah, struktur program, variabel, percabangan, perulangan hingga fungsi, yang terbukti efektif membantu mahasiswa memahami sintaks dan konsep pemrograman [3]. Dengan demikian, C++ tidak hanya sekadar bahasa pemrograman, tetapi juga sarana untuk melatih cara berpikir sistematis yang relevan dengan kebutuhan akademik maupun industri.

Dalam praktik pemrograman, dukungan dari Integrated Development Environment (IDE) sangat penting untuk mempermudah proses belajar dan mengajar. Beberapa penelitian menyoroti penggunaan Dev-C++ sebagai editor utama dalam pembelajaran C++ bagi tunanetra dengan bantuan screen reader NVDA, karena relatif ringan dan mudah dioperasikan [1]. Namun, dalam konteks pembelajaran yang lebih luas, CodeBlocks IDE sering direkomendasikan karena menyediakan fitur-fitur modern seperti integrasi compiler otomatis, debugging, manajemen proyek, serta antarmuka yang lebih ramah bagi pemula. Keberadaan IDE ini memungkinkan mahasiswa lebih fokus pada logika program tanpa terbebani masalah teknis, sekaligus mempercepat proses pembelajaran. Dengan dukungan IDE semacam CodeBlocks, mahasiswa dapat menulis, mengompilasi, dan menguji program secara lebih efisien, yang pada akhirnya meningkatkan motivasi belajar dan memperkuat pemahaman terhadap konsep-konsep pemrograman C++.


## Guided 

### 1. Input Output

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "tebak angka yang dipikiran:" ;
    cin >> angka;

    cout << "angka yang diinput " << angka << endl;
    return 0;
}
```
Kode di atas meminta pengguna memasukkan sebuah angka melalui keyboard. Program kemudian menampilkan kembali angka yang dimasukkan tersebut ke layar. Fungsi utama yang digunakan adalah cin untuk input dan cout untuk output.

### 2. Operator Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //penjumlahan
    cout << "penjumlahan: " << angka1 + angka2 << endl;
    //pengurangan
    cout << "pengurangan: " << angka1 - angka2 << endl;
    //perkalian 
    cout << "perkalian: " << angka1 * angka2 << endl;
    //pembagian
    cout << "pembagian: " << angka1 / angka2 << endl;
    //modulus
    cout << "modulus: " << angka1 % angka2 << endl;

    return 0;
}
```
Kode diatas ini meminta pengguna memasukkan dua angka, lalu menampilkan hasil operasi aritmatika dasar: penjumlahan (+), pengurangan (−), perkalian (×), pembagian (/), dan modulus (sisa bagi, %). Setiap operasi menggunakan operator aritmatika dan hasilnya langsung ditampilkan ke layar. Program ini membantu memahami cara kerja operator aritmatika pada tipe data integer.

### 3. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;
    
    if (angka1 > angka2) {
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    } else if (angka1 < angka2){
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    } else if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    }

    if (angka1 != angka2) {
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }
    
    return 0;
}
```
Kode di atas menggunakan percabangan (if, else if) untuk membandingkan dua angka yang dimasukkan oleh pengguna. Program akan menampilkan apakah angka pertama lebih besar, lebih kecil, atau sama dengan angka kedua. Selain itu, ada percabangan tambahan untuk menampilkan pesan jika kedua angka tidak sama. 

### 4. Perulangan For

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    //increment
    for (int i = 0; i < angka1; i++) {
        cout << i << " - ";
    }
    
    cout << endl;
    
    //decrement
    for (int i = angka1; i >= 0; i--) {
        cout << i << " - ";
    }
    
    return 0;
}
```
Pada kode di atas, terdapat dua contoh penggunaan perulangan for dalam bahasa C++. Pertama, program meminta pengguna memasukkan sebuah angka, lalu menggunakan perulangan for dengan increment untuk mencetak angka dari 0 hingga satu kurang dari angka yang dimasukkan, dipisahkan dengan tanda strip. Setelah itu, program menggunakan perulangan for dengan decrement untuk mencetak angka mulai dari angka yang dimasukkan hingga 0 secara menurun, juga dipisahkan dengan tanda strip. Perulangan for ini memudahkan proses pengulangan dengan batas awal, akhir, dan perubahan nilai yang jelas pada setiap iterasi.

### 5. Perulangan While

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //perulangan while (increment)
    int i = 0;
    while (i <= angka1) {
        cout << i << " - ";
        i++;
    }
    
    cout << endl;

    //perulangan do while (decrement)
    int j = angka2;
    do {
        cout << j << " - ";
        j--;
    } while (j >= 0);
    
    return 0;
}
```
Pada kode di atas, terdapat dua contoh perulangan menggunakan struktur while dan do-while. Perulangan while digunakan untuk mencetak angka dari 0 hingga nilai angka1 secara increment, di mana variabel i akan terus bertambah satu setiap iterasi sampai melebihi angka1. Setelah itu, perulangan do-while digunakan untuk mencetak angka dari nilai angka2 hingga 0 secara decrement, di mana variabel j akan berkurang satu setiap iterasi dan proses perulangan tetap dijalankan minimal satu kali meskipun kondisi pada awalnya sudah tidak terpenuhi. Kedua perulangan ini menunjukkan perbedaan utama antara while dan do-while, yaitu do-while selalu menjalankan blok kode setidaknya satu kali sebelum memeriksa kondisi.

### 6. Struct

```C++
#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct rapot{
        char nama[jumlah];
        int nilai;
    };
    
    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++ ) {
        cout << "masukkan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa: ";
        cin >> siswa[i].nilai;
    }

    cout << endl;

    int i = 0;
    while (i < jumlah) {
        cout << "nama : " << siswa[i].nama << "\nnilai : " << siswa[i].nilai << endl;
        i++;
    }
    
    return 0;
}
```
Kode di atas mendefinisikan sebuah struct bernama rapot untuk menyimpan data nama dan nilai siswa, lalu membuat array siswa berisi 5 elemen bertipe rapot. Program meminta input nama dan nilai untuk setiap siswa menggunakan perulangan for, kemudian menampilkan kembali data yang telah dimasukkan dengan perulangan while. Struct digunakan agar data nama dan nilai tiap siswa dapat dikelompokkan dalam satu entitas, sehingga memudahkan pengelolaan dan akses data.

### 7. Hello World

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```
Program di atas merupakan contoh sederhana untuk menampilkan teks "Hello, World!" ke layar menggunakan bahasa C++. Program ini sering digunakan sebagai latihan awal untuk memastikan lingkungan pengembangan telah terpasang dengan benar dan memahami struktur dasar program C++.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>

using namespace std;

int main() {
    float angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //penjumlahan
    cout << "penjumlahan: " << angka1 << " + " << angka2 << " = " << angka1 + angka2 << endl;
    //pengurangan
    cout << "pengurangan: " << angka1 << " - " << angka2 << " = " << angka1 - angka2 << endl;
    //perkalian 
    cout << "perkalian: " << angka1 << " * " << angka2 << " = " << angka1 * angka2 << endl;
    //pembagian
    if ( angka2 != 0 ) {
        cout << "pembagian: " << angka1 << " / " << angka2 << " = " << angka1 / angka2 << endl;
    } else {
        cout << "pembagian: tidak terdefinisi karena pembagi 0" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week1/output1.png)

Program di atas menerima dua input berupa bilangan bertipe float dari pengguna, lalu menghitung dan menampilkan hasil penjumlahan, pengurangan, perkalian, serta pembagian dari kedua bilangan tersebut. Untuk operasi pembagian, program memeriksa apakah bilangan kedua bernilai nol agar dapat menghindari pembagian dengan nol yang tidak terdefinisi. Setiap hasil operasi ditampilkan dengan format yang jelas, sehingga pengguna dapat langsung melihat proses perhitungan dan hasilnya.


### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << ": ";
    if (angka < 0 || angka > 100) {
        cout << "Angka harus 1-100" << endl;
    } else {
        vector<string> satuan = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
        string hasil;

        if (angka < 12) {
            hasil = satuan[angka];
        } else if (angka < 20) {
            hasil = satuan[angka % 10] + " belas";
        } else if (angka < 100) {
            int puluhan = angka / 10;
            int sisa = angka % 10;
            if (sisa == 0) {
                hasil = satuan[puluhan] + " puluh";
            } else {
                hasil = satuan[puluhan] + " puluh " + satuan[sisa];
            }
        } else {
            hasil = "seratus";
        }
        cout << hasil << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week1/output2.png)


Program di atas menerima input berupa angka bulat positif dari 0 hingga 100, lalu mengubah angka tersebut menjadi bentuk tulisan dalam bahasa Indonesia. Program menggunakan array satuan untuk menyimpan kata-kata angka dasar, kemudian memanfaatkan logika percabangan untuk menentukan format penulisan: angka 0–11 langsung diambil dari array, angka 12–19 menggunakan format "{satuan} belas", angka 20–99 menggunakan format "{satuan} puluh {satuan}", dan angka 100 ditulis sebagai "seratus". Jika input di luar rentang 1–100, program menampilkan pesan error.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "input: ";
    cin >> angka;
    
    int i = angka;
    
    cout << "output: " << endl;

    while (i >= 1) {

        int j = 1;
        while (j <= angka - i) {
            cout << "  ";
            j++;
        }
        

        int k = i;
        while (k >= 1) {
            cout << k << " ";
            k--;
        }

        cout << "* ";

        int l = 1;
        while (l <= i) {
            cout << l << " ";
            l++;
        }

        cout << endl;
        i--;
    }

    int m = 1;
    while (m <= angka) {
        cout << "  ";
        m++;
    }
    
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_3](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week1/output3.png)

Program di atas meminta pengguna memasukkan sebuah angka, lalu mencetak pola berbentuk segitiga simetris yang terdiri dari angka menurun dan menaik di setiap baris, dipisahkan oleh tanda bintang (*). Setiap baris dimulai dengan spasi yang bertambah sesuai urutan baris, diikuti deretan angka menurun dari nilai input hingga 1, lalu tanda *, kemudian angka menaik dari 1 hingga nilai baris tersebut. Setelah seluruh baris tercetak, program menambahkan satu baris terakhir berisi spasi dan satu tanda * di tengah sebagai penutup pola. Program ini menggunakan beberapa loop bersarang untuk mengatur spasi, angka, dan simbol agar pola tercetak rapi sesuai input pengguna.

## Kesimpulan
Pada praktikum ini, telah dipelajari dasar-dasar pemrograman C++ meliputi penggunaan input/output, operator aritmatika, percabangan, perulangan, serta penggunaan struct. Praktikum juga memperkenalkan penggunaan CodeBlocks IDE untuk memudahkan proses penulisan, kompilasi, dan debugging program. Melalui latihan guided dan unguided, mahasiswa dapat memahami konsep dasar pemrograman, logika algoritma, serta penerapan sintaks C++ secara langsung. 


## Referensi
[1] Effendi, Q. M. F. Z., Zuhura, T. R., Azis, M. S., Amrulloh, F. F., Arafat, F. Y., Haris, M., Wahyudi, N. R., & Putra, I. M. (2024). Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro. Jurnal Majemuk, 3(1), 143–151. https://jurnalilmiah.org/journal/index.php/majemuk/article/download/664/483/1442
<br>
[2] Dewi, L. J. E. (2010). Media Pembelajaran Bahasa Pemrograman C++. Jurnal Pendidikan Teknologi dan Kejuruan, 7(1), 63–72. https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25/94
</br>
[3] Sugiyo & Septian, F. (2022). Model Pembelajaran Pemrograman Bahasa C++ untuk Tunanetra dengan Metode Problem Based Learning. Jurnal Maklumatika, 8(2), 119–125. https://maklumatika.i-tech.ac.id/index.php/maklumatika/article/download/126/130

