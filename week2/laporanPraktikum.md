# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Bahasa pemrograman C++ adalah pengembangan dari C yang mendukung paradigma prosedural dan berorientasi objek, sehingga fleksibel untuk pendidikan maupun industri. Dalam praktik dasar pemrograman, diperkenalkan struktur data seperti array yang berfungsi menyimpan data sejenis secara berurutan di memori. Array satu dimensi dapat diperluas menjadi array dua dimensi maupun multidimensi untuk merepresentasikan data yang lebih kompleks, misalnya matriks atau tabel. Penelitian menegaskan bahwa array merupakan fondasi penting dalam pembelajaran struktur data, meskipun memiliki keterbatasan ukuran yang statis [1].

Selain array, konsep pointer dan reference di C++ menjadi kunci dalam pengelolaan memori. Pointer memungkinkan akses data langsung melalui alamat memori, sedangkan reference menyediakan cara efisien untuk mengakses variabel tanpa duplikasi. Studi terbaru menunjukkan bahwa penggunaan indeks atau pointer dalam mengakses elemen array tidak selalu menunjukkan perbedaan signifikan dalam kecepatan, meskipun pointer dapat lebih efisien pada kasus tertentu [3]. Untuk mendukung modularitas program, fungsi dan prosedur digunakan sebagai pemecah program menjadi bagian kecil: fungsi mengembalikan nilai, sedangkan prosedur tidak. Dengan pemahaman konsep-konsep ini, dapat membangun logika pemrograman yang lebih sistematis dan efisien [2].

## Guided 

### 1. Array

```C++
#include <iostream>

using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl ;
        j++;
    }

    return 0;
}
```
Kode di atas mendeklarasikan sebuah array arr berukuran 5, lalu meminta pengguna memasukkan 5 nilai yang disimpan ke dalam array melalui perulangan for. Setelah semua nilai dimasukkan, program menggunakan perulangan while untuk menampilkan kembali setiap nilai yang telah disimpan di array beserta indeksnya.


### 2. Array Dua Dimensi

```C++
#include <iostream>

using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };

    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
        
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);

    //perkalian matriks 2x2
    for(int i = 0; i < 2; i++){                         //perulangan baris
        for (int j = 0; j < 2; j++){                    //perulangan kolom
            for (int k = 0; k < 2; k++){                //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Kode di atas mendemonstrasikan operasi dasar pada array dua dimensi (matriks) yaitu penjumlahan dan perkalian matriks berukuran 2x2. Dua buah matriks, arrA dan arrB, diinisialisasi dengan nilai tetap, lalu arrC digunakan untuk menyimpan hasil penjumlahan elemen-elemen yang bersesuaian dari kedua matriks tersebut. Selanjutnya, arrD digunakan untuk menyimpan hasil perkalian matriks dengan menggunakan tiga buah loop bersarang: loop pertama untuk baris, kedua untuk kolom, dan ketiga untuk melakukan penjumlahan hasil perkalian elemen yang sesuai. Fungsi tampilkanHasil digunakan untuk menampilkan isi matriks hasil ke layar. Program ini memperkenalkan konsep array dua dimensi dan operasi dasar matriks secara sederhana.


### 3. Function dan Procedure

```C++
#include <iostream>

using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan: " << totalJumlah << endl;
    
    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian: " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Kode di atas mendemonstrasikan penggunaan fungsi dan prosedur untuk mengolah array. Fungsi cariMAX menerima array dan ukurannya, lalu mencari nilai terbesar dengan membandingkan setiap elemen. Prosedur operasiAritmatika menghitung total penjumlahan dan perkalian seluruh elemen array, lalu menampilkannya ke layar. Pada fungsi main, program meminta pengguna memasukkan lima nilai ke dalam array, kemudian menampilkan nilai terbesar menggunakan cariMAX dan hasil penjumlahan serta perkalian menggunakan operasiAritmatika. Kode ini memperlihatkan konsep pemisahan logika program ke dalam fungsi dan prosedur untuk meningkatkan keterbacaan dan modularitas.


### 4. Pointer

```C++
#include <iostream>

using namespace std;

void tukar(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Addres of a: " << &a << endl;
    cout << "Value stored in ptr (addres of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl;

    return 0;
}
```
Kode di atas mendemonstrasikan penggunaan pointer untuk mengakses dan memanipulasi nilai variabel secara tidak langsung. Fungsi tukar menerima dua pointer ke integer dan menukar nilai yang ditunjuk oleh pointer tersebut menggunakan variabel sementara. Di fungsi main, dua variabel a dan b diinisialisasi, lalu pointer ptr diarahkan ke alamat a. Program kemudian mencetak nilai dan alamat dari a, nilai yang disimpan di ptr (alamat a), serta nilai yang ditunjuk oleh ptr (nilai a). Setelah itu, fungsi tukar dipanggil untuk menukar nilai a dan b melalui alamatnya, dan hasil pertukaran ditampilkan. Kode ini menyoroti konsep pointer, dereferensi, dan passing by reference menggunakan alamat memori.


### 5. Reference

```C++
#include <iostream>

using namespace std;

void tukar(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Value of a: " << a << endl;
    cout << "Addres of a (&a): " << &a << endl;
    cout << "Value of ref (alias a): " << ref << endl;
    cout << "Addres of ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nAfter ref = 50;" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl;

    return 0;
}
```
Kode di atas mendemonstrasikan konsep reference (referensi) pada variabel dan penggunaannya dalam fungsi. Variabel ref dideklarasikan sebagai reference ke a, sehingga perubahan pada ref juga mengubah nilai a karena keduanya menunjuk ke alamat memori yang sama. Hal ini terlihat saat ref diubah menjadi 50, nilai a juga ikut berubah. Fungsi tukar menggunakan reference sebagai parameter agar nilai variabel yang dikirim (dalam hal ini a dan b) bisa langsung ditukar tanpa perlu mengembalikan nilai. Output program menunjukkan nilai dan alamat dari a dan ref, perubahan nilai setelah assignment melalui reference, serta hasil pertukaran nilai antara a dan b. Konsep ini penting untuk efisiensi memori dan manipulasi data secara langsung pada fungsi.


## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
#include <iostream>

using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrB[3][3] = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };

    int arrC[3][3] = {0}; // untuk penjumlahan
    int arrD[3][3] = {0}; // untuk pengurangan
    int arrE[3][3] = {0}; // untuk perkalian

    //penjumlahan matriks 3x3
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);

    //pengurangan matriks 3x3
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan: " << endl;
    tampilkanHasil(arrD);

    //perkalian matriks 3x3
    for(int i = 0; i < 3; i++){                         //perulangan baris
        for (int j = 0; j < 3; j++){                    //perulangan kolom
            for (int k = 0; k < 3; k++){                //perulangan perkalian
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrE);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided1.png)

Kode di atas mendemonstrasikan operasi penjumlahan, pengurangan, dan perkalian pada dua buah matriks berukuran 3x3. Dua matriks awal, arrA dan arrB, diinisialisasi dengan nilai tetap. Program menggunakan tiga matriks hasil: arrC untuk penjumlahan, arrD untuk pengurangan, dan arrE untuk perkalian. Penjumlahan dan pengurangan dilakukan dengan menjumlahkan atau mengurangkan elemen yang bersesuaian pada kedua matriks. Untuk perkalian, digunakan tiga lapis perulangan (nested loop) untuk menghitung hasil kali baris matriks pertama dengan kolom matriks kedua sesuai aturan perkalian matriks. Hasil dari masing-masing operasi kemudian ditampilkan menggunakan fungsi tampilkanHasil, yang mencetak isi matriks ke layar.


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

#### Pointer 

```C++
#include <iostream>

using namespace std;

void tukar(int *x, int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    cout << "\nBefore swapping: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    tukar(&a, &b, &c);
    
    cout << "After swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
```
### Output Unguided 2 - Pointer :

##### Output 1
![Screenshot Output Unguided 1_2-1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided2-pointer.png)

Kode di atas mendemonstrasikan penggunaan pointer untuk menukar nilai tiga variabel (a, b, dan c). Fungsi tukar menerima tiga parameter pointer ke integer, lalu menukar nilai yang ditunjuk sehingga nilai a menjadi b, b menjadi c, dan c menjadi a. Di fungsi main, variabel a, b, dan c diinisialisasi, lalu alamat a disimpan ke pointer ptr untuk menunjukkan bagaimana pointer bekerja. Program menampilkan nilai dan alamat variabel sebelum dan sesudah pemanggilan fungsi tukar, sehingga perubahan nilai akibat pertukaran dapat diamati secara langsung di output.

#### Reference

```C++
#include <iostream>

using namespace std;

void tukar(int &x, int &y, int &z){
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Value of ref (alias a): " << ref << endl;
    cout << "Address of ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nAfter ref = 50;" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;

    cout << "\nBefore swapping: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    tukar(a, b, c);
    
    cout << "After swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
```
### Output Unguided 2 - Reference :

##### Output 1
![Screenshot Output Unguided 1_2-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided2-reference.png)

Kode di atas mendemonstrasikan penggunaan reference (referensi) pada variabel dan fungsi. Pada fungsi tukar, tiga variabel bertipe int ditukar nilainya menggunakan parameter referensi, sehingga perubahan nilainya langsung memengaruhi variabel asli yang dikirimkan. Di fungsi main, variabel a, b, dan c dideklarasikan, lalu dibuat reference ref yang mengacu ke a. Program menampilkan nilai dan alamat memori dari a dan ref, lalu mengubah nilai a melalui ref untuk menunjukkan bahwa reference adalah alias dari variabel aslinya. Setelah itu, fungsi tukar dipanggil untuk menukar nilai ketiga variabel, dan hasil akhirnya ditampilkan ke layar. Kode ini menekankan konsep reference sebagai alias variabel dan penggunaannya untuk memodifikasi nilai variabel secara langsung dalam fungsi.


### 3. Diketahui sebuah array 1 dimensi sebagai berikut : 
### arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
### Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
### --- Menu Program Array ---
### 1. Tampilkan isi array
### 2. cari nilai maksimum
### 3. cari nilai minimum
### 4. Hitung nilai rata - rata

```C++
#include <iostream>

using namespace std;

void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for(int i = 0; i < ukuran; i++) {
        cout << arr[i];
        if(i < ukuran - 1) cout << ", ";
    }
    cout << endl;
}

int cariMaksimum(int arr[], int ukuran) {
    int maksimum = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }
    return maksimum;
}

int cariMinimum(int arr[], int ukuran) {
    int minimum = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

void hitungRataRata(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    double rataRata = (double)totalJumlah / ukuran;
    cout << "Nilai rata-rata: " << rataRata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = 10;
    int pilihan;
    
    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                tampilkanArray(arrA, ukuran);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 5);
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_3-1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided3-1.png)
##### Output 2
![Screenshot Output Unguided 1_3-2](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided3-2.png)
##### Output 3
![Screenshot Output Unguided 1_3-3](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided3-3.png)
##### Output 4
![Screenshot Output Unguided 1_3-4](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided3-4.png)
##### Output 5
![Screenshot Output Unguided 1_3-5](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week2/output/output-unguided3-5.png)

Kode di atas mendemonstrasikan program berbasis menu yang mengelola sebuah array satu dimensi berisi 10 bilangan bulat. Program ini menyediakan empat fitur utama: menampilkan seluruh isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung rata-rata nilai array. Fungsi tampilkanArray mencetak seluruh elemen array, cariMaksimum dan cariMinimum masing-masing mencari nilai terbesar dan terkecil dengan membandingkan setiap elemen, sedangkan prosedur hitungRataRata menjumlahkan seluruh elemen lalu membaginya dengan jumlah elemen untuk mendapatkan rata-rata. Pengguna dapat memilih fitur yang diinginkan melalui menu berbasis switch-case, dan program akan terus berjalan hingga pengguna memilih opsi keluar.


## Kesimpulan
Pada praktikum ini, telah dipelajari dasar-dasar pemrograman C++ meliputi penggunaan array satu dimensi dan dua dimensi, pointer, reference, serta pemisahan logika program menggunakan fungsi dan prosedur. Array digunakan untuk menyimpan data sejenis secara terstruktur, baik dalam bentuk satu dimensi maupun dua dimensi (matriks), dan dapat dioperasikan untuk penjumlahan, pengurangan, serta perkalian. Pointer dan reference memberikan fleksibilitas dalam pengelolaan memori, memungkinkan manipulasi data secara langsung melalui alamat atau alias variabel. Penggunaan fungsi dan prosedur membantu modularisasi program sehingga kode menjadi lebih terstruktur dan mudah dipahami. Melalui latihan guided dan unguided, dapat dipahami konsep dasar ini secara praktis, yang menjadi fondasi penting untuk mempelajari struktur data dan algoritma yang lebih kompleks di tahap selanjutnya.


## Referensi
[1] Nugroho, A. Y., & Sutanto, N. H. (2024). Exploring the Code Foundation: A Literature Review of Data Structures in C++. International Journal of Mechanical, Industrial and Control Systems Engineering, 1(3), 24–37. https://doi.org/10.61132/ijmicse.v1i3.47
[2] Ahmed, H. E. (2018). Evaluation of C++ as Object-Oriented Programming Language Compared to Java. International Journal of Scientific Engineering and Applied Science (IJSEAS), 4(1), 16–22. http://www.ijseas.com
[3] Logožar, R., Mikac, M., & Radošević, D. (2024). Exploring the Access to the Static Array Elements via Indices and via Pointers — the Introductory C++ Case Expanded. Journal of Information and Organizational Sciences (JIOS), 48(1), 49–80. https://doi.org/10.31341/jios.48.1.3
