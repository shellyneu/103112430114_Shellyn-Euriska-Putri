# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama) </h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Tree merupakan struktur data non-linear yang digunakan untuk merepresentasikan hubungan hierarkis antar elemen data yang tersusun dalam bentuk node dan edge. Tree memiliki satu node khusus yang disebut root, sementara node lain berperan sebagai parent dan child sesuai posisi hierarkinya. Struktur ini tidak memiliki siklus dan memungkinkan proses pencarian, penyimpanan, serta representasi data yang lebih terstruktur terutama untuk kasus klasifikasi dan hirarki data kompleks [1]. Selain itu, tree dikategorikan sebagai struktur data dinamis yang memungkinkan penambahan dan penghapusan elemen tanpa menggeser keseluruhan data seperti yang terjadi pada array [1].

Binary Tree merupakan salah satu bentuk tree yang paling banyak digunakan dalam implementasi struktur data. Pada binary tree, setiap node memiliki maksimum dua child yang disebut left child dan right child [1]. Binary tree juga mendukung beberapa metode traversal untuk mengunjungi semua node, yaitu preorder, inorder, dan postorder. Ketiga metode ini banyak digunakan dalam aplikasi seperti evaluasi ekspresi, manipulasi struktur hirarki, hingga operasi pencarian data rekursif [1].

Binary Search Tree (BST) merupakan pengembangan binary tree yang menerapkan sifat terurut pada setiap node di dalamnya, di mana nilai pada left subtree harus lebih kecil dari parent dan nilai pada right subtree harus lebih besar. Dengan aturan ini, operasi pencarian pada BST dapat dilakukan lebih efisien dibandingkan struktur linear karena pencarian hanya berfokus pada subtree tertentu berdasarkan perbandingan nilai [1]. BST juga mendukung operasi penting seperti insertion, deletion, searching, serta traversal yang semuanya dapat diimplementasikan menggunakan pendekatan rekursif sesuai konsep yang diajarkan dalam modul praktikum struktur data.

Operasi deletion dalam BST memiliki tiga kemungkinan skenario, yaitu penghapusan leaf node, node dengan satu child, atau node dengan dua child. Untuk kasus node dengan dua child, diperlukan penggantian nilai node dengan node pengganti seperti inorder successor atau predecessor untuk mempertahankan aturan pengurutan BST [1]. Sementara itu, operasi insertion dilakukan dengan membandingkan nilai baru dengan parent node secara rekursif hingga ditemukan posisi yang tepat pada leaf sehingga tidak mengubah struktur terurut dari BST.

Dalam konteks implementasi, tree dan BST sering direalisasikan menggunakan konsep pointer dan pendekatan dinamis sehingga node dapat dialokasikan dan dilepaskan sesuai kebutuhan. Penggunaan fungsi rekursif menjadi bagian penting dalam pengelolaan tree karena traversal dan operasi lainnya secara alami mengikuti pola pemecahan masalah berbasis subtree. Namun demikian, implementasi pointer secara langsung sering menimbulkan kendala seperti kebocoran memori dan pointer tergantung pada pengelolaan manual oleh programmer. Solusi modern memanfaatkan smart pointers yang mampu mengelola referensi objek secara otomatis serta mencegah terjadinya dangling pointer ataupun double free dalam struktur tree yang bersifat rekursif [2].

Dengan demikian, pemahaman mengenai struktur tree khususnya Binary Search Tree sangat penting dalam pembelajaran struktur data karena tidak hanya memberikan fondasi kuat dalam pengelolaan data secara hierarkis, tetapi juga digunakan sebagai dasar pengembangan struktur yang lebih kompleks seperti AVL Tree, Heap Tree, dan Red-Black Tree yang mengoptimalkan efisiensi operasi pencarian serta pengurutan data dalam berbagai aplikasi dunia nyata.

## Guided 

### 1. Faktorial

```c++
#include<iostream>
using namespace std;

long int faktorial(long int a){
    if(a == 1 || a == 0){
        return 1;
    } else if (a > 1){
        return a * faktorial(a - 1);
    }
    return 0;
}

int main(){
    long int angka;
    cout << "Masukkan angka faktorial: ";
    cin >> angka;

    if(angka < 0){
        cout << "Faktorial tidak terdefinisi untuk angka negatif." << endl;
    } else {
        long int hasil = faktorial(angka);
        cout << angka << "! = " << hasil << endl;
    }

    return 0;
}
```
Program di atas merupakan implementasi fungsi rekursif untuk menghitung nilai faktorial dari suatu bilangan bulat non-negatif. Faktorial didefinisikan sebagai hasil perkalian berurutan dari bilangan tersebut dengan semua bilangan positif di bawahnya, serta memiliki nilai khusus 0! = 1. Pada kode tersebut, fungsi rekursif bernama faktorial digunakan untuk mengelola proses perhitungan secara berulang berdasarkan konsep pemanggilan diri sendiri. Fungsi ini menerima parameter bertipe long int dan memeriksa nilai masukan. Jika nilai yang diberikan adalah 0 atau 1, fungsi langsung mengembalikan nilai 1, karena kedua kondisi tersebut merupakan dasar perhitungan faktorial. Kondisi dasar ini disebut sebagai base case, yang memastikan bahwa proses rekursi berhenti sehingga tidak menimbulkan pemanggilan tak hingga.

Apabila nilai parameter lebih besar dari 1, fungsi akan mengembalikan hasil perkalian bilangan tersebut dengan pemanggilan fungsi faktorial untuk nilai satu tingkat di bawahnya, yaitu a - 1. Proses ini berulang hingga mencapai kondisi dasar. Dengan demikian, mekanisme rekursif bekerja menurunkan nilai argumen secara bertahap sampai mencapai kondisi penghentian. Apabila masukan bernilai negatif, fungsi akan mengembalikan nilai 0 sebagai bentuk penanganan masukan yang tidak valid, sebab faktorial tidak didefinisikan untuk bilangan negatif dalam konsep matematika standar.

Pada fungsi main, program meminta pengguna memasukkan sebuah bilangan bulat menggunakan objek input cin. Data yang diterima selanjutnya diperiksa untuk memastikan bahwa angka tersebut tidak bernilai negatif. Jika pengguna memasukkan nilai negatif, program akan menampilkan pesan bahwa faktorial tidak terdefinisi untuk angka negatif. Sebaliknya, jika nilai memenuhi kriteria, fungsi faktorial akan dipanggil dan hasil perhitungan ditampilkan ke layar menggunakan cout.

### 2. faktorial_tree.cpp

```c++
#include<iostream>
#include<string>
using namespace std;

// Fungsi untuk mencetak indentasi (untuk visualisasi tree)
void printIndent(int level) {
    for(int i = 0; i < level; i++) {
        if(i == level - 1) {
            cout << "|-- ";
        } else {
            cout << "|   ";
        }
    }
}

// Fungsi faktorial dengan visualisasi tree
long int faktorial(long int a, int level = 0){
    // Cetak node saat ini
    printIndent(level);
    cout << "faktorial(" << a << ")";
    
    if(a == 1 || a == 0){
        cout << " = 1 (base case)" << endl;
        return 1;
    } else if (a > 1){
        cout << " = " << a << " * faktorial(" << (a-1) << ")" << endl;
        long int hasil = faktorial(a - 1, level + 1);
        
        // Cetak hasil saat kembali dari rekursi
        printIndent(level);
        cout << "^ return " << a << " * " << hasil << " = " << (a * hasil) << endl;
        
        return a * hasil;
    }
    return 0;
}

int main(){
    long int angka;
    cout << "===== VISUALISASI TREE FAKTORIAL REKURSIF =====" << endl;
    cout << "Masukkan angka faktorial: ";
    cin >> angka;

    if(angka < 0){
        cout << "Faktorial tidak terdefinisi untuk angka negatif." << endl;
    } else {
        cout << "\nProses Rekursi (Tree Structure):\n" << endl;
        long int hasil = faktorial(angka);
        cout << "\n===== HASIL AKHIR =====" << endl;
        cout << angka << "! = " << hasil << endl;
    }

    return 0;
}
```
Program tersebut merupakan pengembangan dari konsep perhitungan faktorial menggunakan rekursi, namun dilengkapi dengan fitur visualisasi struktur recursion tree. Dengan demikian, pengguna tidak hanya memperoleh hasil akhir, tetapi juga dapat memahami alur pemanggilan fungsi rekursif secara bertahap dalam format struktur pohon. Visualisasi ini membantu memperlihatkan bagaimana setiap pemanggilan fungsi menghasilkan node baru dalam pohon rekursi hingga mencapai kondisi dasar (base case), kemudian kembali melakukan proses penggabungan hasil melalui operasi perkalian.

Program ini memanfaatkan fungsi tambahan bernama printIndent yang bertugas mencetak indentasi sesuai level pemanggilan rekursif. Semakin dalam sebuah fungsi direkursi, semakin besar tingkat indentasi yang dicetak. Tampilan karakter seperti “|--” dan “| ” digunakan untuk membentuk gambaran hierarki pohon sehingga hubungan parent dan child pada proses rekursif tersaji secara jelas. Hal ini memungkinkan pemakai dapat melihat bagaimana fungsi faktorial memanggil dirinya sendiri dengan nilai yang berkurang satu setiap langkah.

Fungsi utama faktorial pada program ini menerima dua parameter, yaitu bilangan yang akan dihitung faktorialnya serta variabel level yang menentukan kedalaman rekursi. Parameter level memiliki nilai dasar 0 sehingga pemanggilan pertama dianggap sebagai akar atau root dari pohon. Ketika fungsi dijalankan, langkah pertama adalah mencetak representasi node saat ini melalui pemanggilan printIndent, kemudian menampilkan nilai argumen yang sedang diproses. Apabila nilai tersebut merupakan 0 atau 1, program akan menampilkan bahwa telah tercapai kondisi dasar dan mengembalikan nilai 1 untuk menghentikan rekursi lebih lanjut.

Jika nilai parameter lebih besar dari 1, fungsi menampilkan proses matematis berupa ekspresi a * faktorial(a-1). Setelah pemanggilan rekursif dilakukan untuk menghitung nilai faktorial sebelumnya, barulah program mencetak informasi ketika fungsi selesai dieksekusi dan mengembalikan hasil ke fungsi sebelumnya. Proses ini divisualisasikan sebagai tanda panah kembali (^) yang menunjukkan bahwa eksekusi telah kembali dari level rekursi yang lebih dalam, sekaligus memperlihatkan tahapan penggabungan hasil perkalian pada setiap langkah pemanggilan.

Pada fungsi main, program meminta pengguna memasukkan bilangan bulat untuk dihitung nilai faktorialnya. Validasi tetap dilakukan untuk mencegah masukan bilangan negatif yang tidak memiliki definisi faktorial dalam matematika. Jika masukan valid, struktur pohon rekursif akan dicetak terlebih dahulu sebelum program menampilkan hasil akhir perhitungan.


### 3.1. bst.h

```h
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

### 3.2 bst.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

### 3.3 main.cpp

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Program ini mengimplementasikan struktur data Binary Search Tree (BST) dalam bahasa C++ dengan pendekatan modular yang membagi deklarasi dan definisi fungsi ke dalam file header serta implementasi terpisah. Pada file bst.h, struktur node untuk BST didefinisikan dengan menggunakan struct yang berisi satu atribut data berupa bilangan bulat dan dua pointer yang masing-masing menunjuk ke anak kiri (left) dan anak kanan (right). Selain itu, berbagai fungsi yang berkaitan dengan operasi dasar BST dideklarasikan, seperti pengecekan kondisi kosong, alokasi dan dealokasi node, pemasukan data, pencarian, traversal, penghapusan node, serta perhitungan ukuran dan tinggi tree. Pemisahan antarmuka dan implementasi ini menunjukkan penerapan prinsip abstraksi dalam pemrograman terstruktur.

Implementasi lengkap fungsi-fungsi tersebut terdapat pada file bst.cpp. Fungsi isEmpty digunakan untuk memeriksa apakah tree tidak memiliki node, sedangkan createTree menginisialisasi sebuah pointer tree menjadi kosong. Alokasi node baru memanfaatkan operator new sehingga node dapat dialokasikan secara dinamis selama program berjalan, dan dealokasi menghapus node yang tidak lagi digunakan untuk menghindari kebocoran memori. Fungsi insertNode menerapkan logika pencarian posisi berdasarkan sifat BST, di mana nilai yang lebih kecil ditempatkan pada subtree kiri dan nilai yang lebih besar pada subtree kanan. Proses ini dilakukan secara rekursif hingga posisi node baru ditemukan.

Pencarian data dalam tree dilakukan pada fungsi searchByData, yang menelusuri tree secara iteratif menggunakan pointer bantu. Jika ditemukan, program menampilkan informasi tambahan seperti parent, sibling, serta child dari node terkait, sehingga pengguna dapat memahami hubungan hierarkis antar node dalam tree. Operasi traversal yang disediakan terdiri dari preOrder, inOrder, dan postOrder, masing-masing menggambarkan urutan penelusuran yang berbeda berdasarkan posisi node saat dikunjungi. Traversal ini penting untuk menampilkan data dalam berbagai keperluan, khususnya inOrder yang pada BST menghasilkan data terurut.

Program juga mendukung penghapusan node melalui fungsi deleteNode, yang mencakup empat kasus umum sesuai teori BST: node merupakan leaf, hanya memiliki anak kiri, hanya memiliki anak kanan, dan memiliki dua anak. Pada kasus terakhir, program menggunakan successor yaitu node dengan nilai terkecil pada subtree kanan (hasil dari fungsi mostLeft) untuk menggantikan posisi node yang dihapus sehingga sifat BST tetap terjaga. Selain itu, disediakan fungsi deleteTree yang menghapus seluruh node secara rekursif dari subtree hingga tree kembali kosong. Fungsi size dan height masing-masing mengembalikan jumlah total node dalam tree serta kedalaman level tertinggi, yang keduanya merupakan indikator penting dalam evaluasi kompleksitas struktur tree.

Antarmuka dibuat agar pengguna dapat memilih berbagai operasi pada BST melalui menu. Program memberikan respons informatif untuk setiap aksi, seperti keberhasilan atau kegagalan operasi insert, delete, maupun pencarian data. Selain itu, traversal tree serta informasi mengenai ukuran dan tinggi tree dapat ditampilkan sesuai kebutuhan. Seluruh interaksi ini berjalan dalam loop hingga pengguna memilih untuk keluar dari program, mencerminkan penerapan kontrol alur program yang efektif.

## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”. Kemudian, buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

#### bstree.h

```h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype input);
address findNode(infotype x, address root);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

#endif
```

##### bstree.cpp

```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x){
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype input){
    if(root == Nil){
        root = alokasi(input);
        return;
    } else if(input < root->info){
        insertNode(root->left, input);
    } else if(input > root->info){
        insertNode(root->right, input);
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else if(x > root->info){
        return findNode(x, root->right);
    } else {
        return root;
    }
}

void preOrder(address root){ 
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(address root){ 
    if(root == Nil){
        return;
    }
    inOrder(root->left);
    cout << root->info << " - ";
    inOrder(root->right);
}

void postOrder(address root){ 
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}
```

##### main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    inOrder(root);
    cout << endl;
    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week10/output/output-unguided1.png)
Program Binary Search Tree (BST) ini terdiri dari tiga file utama yaitu bstree.h, bstree.cpp, dan main.cpp yang bekerja bersama untuk membangun serta menampilkan struktur tree secara terurut. Pada bstree.h, didefinisikan tipe data dan deklarasi fungsi yang akan digunakan dalam pengelolaan tree. Struktur Node yang dirancang memiliki satu atribut info bertipe integer sebagai data utama, serta dua pointer yaitu left dan right untuk menunjuk anak kiri dan kanan. file ini juga memuat deklarasi fungsi seperti alokasi, insertNode, findNode, dan tiga metode traversal yaitu preOrder, inOrder, serta postOrder. Dengan adanya header ini, detail implementasi fungsi tidak perlu diketahui oleh program utama sehingga mencerminkan prinsip modularitas dan abstraksi dalam pemrograman.

Seluruh fungsi yang dideklarasikan di header kemudian diimplementasikan dalam bstree.cpp. Namun, dalam program utama hanya beberapa fungsi yang digunakan secara langsung. Fungsi alokasi berperan penting dalam membentuk node baru menggunakan memori dinamis, dimana nilai node dan pointer anaknya diinisialisasi sesuai kebutuhan. Fungsi inti pembentuk tree adalah insertNode, yang menyisipkan data ke dalam tree mengikuti aturan BST: nilai lebih kecil ditempatkan di subtree kiri, sementara nilai lebih besar pada subtree kanan. Implementasi ini dilakukan secara rekursif sampai ditemukan posisi kosong bernilai Nil sebagai tempat meletakkan node baru. Sementara itu, fungsi inOrder digunakan untuk menampilkan node dalam urutan kiri–root–kanan sehingga keluaran berupa data yang terurut menaik secara otomatis. Fungsi traversal lainnya seperti preOrder dan postOrder, serta findNode, memang tersedia namun tidak terpanggil di program utama sehingga tidak berpengaruh pada hasil akhir eksekusi.

Pada main.cpp, proses eksekusi dimulai dengan membuat pointer root dan menginisialisasinya sebagai Nil, menandakan tree masih kosong. Selanjutnya, beberapa nilai disisipkan ke dalam tree melalui pemanggilan berulang fungsi insertNode. Data yang dimasukkan akan otomatis tersusun sesuai sifat BST. Ketika salah satu nilai, yaitu angka 6, dimasukkan dua kali, node duplikat secara implisit tidak ditambahkan karena tidak memenuhi kondisi kurang atau lebih besar dalam struktur BST, sehingga tree tetap terjaga keunikannya. Setelah tree berhasil terbentuk, fungsi inOrder dipanggil untuk menampilkan data dalam urutan yang terstruktur, menjadi validasi bahwa tree telah dibangun dengan benar sesuai sifat BST. Program kemudian menampilkan hasil akhir traversal dan mengakhiri eksekusi secara teratur.

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut: hitungJumlahNode, hitungTotalInfo, hitungKedalaman.

#### bstree.h

```h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype input);
address findNode(infotype x, address root);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalNilai(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```

##### bstree.cpp

```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x){
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype input){
    if(root == Nil){
        root = alokasi(input);
        return;
    } else if(input < root->info){
        insertNode(root->left, input);
    } else if(input > root->info){
        insertNode(root->right, input);
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else if(x > root->info){
        return findNode(x, root->right);
    } else {
        return root;
    }
}

void preOrder(address root){ 
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(address root){ 
    if(root == Nil){
        return;
    }
    inOrder(root->left);
    cout << root->info << " - ";
    inOrder(root->right);
}

void postOrder(address root){ 
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalNilai(address root, int start){
    if(root == Nil){
        return start;
    }
    start = start + root->info;
    start = hitungTotalNilai(root->left, start);
    start = hitungTotalNilai(root->right, start);
    return start;
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return start;
    }
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    
    if(leftDepth > rightDepth){
        return leftDepth;
    } else {
        return rightDepth;
    }
}
```

##### main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    inOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalNilai(root,0)<<endl;
    return 0;
}
```
### Output Unguided :
##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week10/output/output-unguided2.png)
Program Binary Search Tree (BST) ini merupakan perluasan dari implementasi dasar tree dengan penambahan tiga fungsi khusus yang digunakan untuk menghitung karakteristik struktural dan nilai dari tree, yaitu menghitung kedalaman tree, menghitung jumlah node, dan menghitung total nilai seluruh node. Ketiga fungsi tambahan tersebut digunakan pada program utama untuk memberikan informasi analitis mengenai struktur tree yang terbentuk.

Dalam bstree.h, struktur Node berperan menyimpan nilai data bertipe integer dan dua pointer left serta right yang menunjuk ke anak kiri dan kanan. File ini juga memuat deklarasi fungsi-fungsi pengelolaan tree, termasuk operasi traversal dan fungsi analisis seperti hitungJumlahNode, hitungTotalNilai, dan hitungKedalaman. Terdapat pula deklarasi fungsi alokasi dan insertNode yang berperan penting dalam membentuk BST sehingga tree siap dilakukan perhitungan karakteristiknya.

File bstree.cpp berisi implementasi dari seluruh fungsi tersebut. Adapun fungsi yang digunakan langsung dalam main.cpp diawali dengan insertNode yang berfungsi menempatkan nilai input ke dalam tree sesuai aturan BST secara rekursif, yakni dengan membandingkan nilai masukan dengan data pada node yang sedang ditelusuri hingga diperoleh posisi yang sesuai untuk ditempati node baru. Setelah tree berhasil terbentuk, tiga fungsi utama digunakan untuk menghitung informasi mengenai struktur tree. Pertama, hitungJumlahNode bekerja secara rekursif dengan menghitung setiap node yang ditemukan dan menjumlahkannya bersama hasil perhitungan subtree kiri dan kanan. Dengan demikian, fungsi ini mengembalikan nilai total seluruh node dalam tree.

Selanjutnya, fungsi hitungTotalNilai melakukan penjumlahan terhadap seluruh nilai info pada setiap node dalam tree. Fungsi ini juga bersifat rekursif dengan parameter tambahan start sebagai penampung nilai sementara yang akan terus ditambahkan seiring penelusuran subtree kiri dan kanan. Fungsi ini mengembalikan akumulasi akhir setelah seluruh node selesai dikunjungi. Fungsi berikutnya adalah hitungKedalaman, yang menggambarkan panjang maksimum jalur dari root hingga node terdalam. Proses perhitungan dilakukan dengan membandingkan kedalaman subtree kiri dan kanan, kemudian mengembalikan nilai kedalaman terbesar sebagai tinggi tree. Parameter start merepresentasikan tingkat kedalaman yang bertambah setiap kali fungsi melakukan penelusuran lebih jauh ke subtree berikutnya.

Pada main.cpp, setelah tree dibangun dengan penyisipan beberapa nilai, pengguna dapat melihat bentuk terurut tree melalui fungsi inOrder yang menampilkan data dalam urutan menaik. Setelah itu, fungsi hitungKedalaman, hitungJumlahNode, dan hitungTotalNilai dipanggil untuk menampilkan kedalaman tree, jumlah seluruh node, dan total nilai yang tersimpan dalam tree. Informasi yang dihasilkan memberikan gambaran mengenai kompleksitas dan isi tree yang terbentuk dalam program tersebut.

### 3. Print tree secara pre-order dan post-order.

#### bstree.h

```h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype input);
address findNode(infotype x, address root);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalNilai(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```

##### bstree.cpp

```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x){
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype input){
    if(root == Nil){
        root = alokasi(input);
        return;
    } else if(input < root->info){
        insertNode(root->left, input);
    } else if(input > root->info){
        insertNode(root->right, input);
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else if(x > root->info){
        return findNode(x, root->right);
    } else {
        return root;
    }
}

void preOrder(address root){ 
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(address root){ 
    if(root == Nil){
        return;
    }
    inOrder(root->left);
    cout << root->info << " - ";
    inOrder(root->right);
}

void postOrder(address root){ 
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalNilai(address root, int start){
    if(root == Nil){
        return start;
    }
    start = start + root->info;
    start = hitungTotalNilai(root->left, start);
    start = hitungTotalNilai(root->right, start);
    return start;
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return start;
    }
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    
    if(leftDepth > rightDepth){
        return leftDepth;
    } else {
        return rightDepth;
    }
}
```

##### main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);
    inOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalNilai(root,0)<<endl;

    cout << endl << "Pre-order: ";
    preOrder(root);
    cout << endl;
    
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
    
    return 0;
}
```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week10/output/output-unguided3.png)
Program Binary Search Tree (BST) ini merupakan lanjutan dari implementasi tree sebelumnya, namun dengan fokus utama pada penerapan metode traversal pre-order dan post-order sebagai bagian dari proses penelusuran node dalam struktur pohon biner. Ketiga file yaitu bstree.h, bstree.cpp, dan main.cpp bekerja bersama dalam mendefinisikan struktur tree, membangun tree melalui penyisipan data, dan menampilkan hasil penelusuran data dalam urutan tertentu untuk menunjukkan bagaimana Binary Search Tree menyusun serta mengelola elemen data secara hierarkis.

Pada file bstree.h, didefinisikan struktur data Node yang memiliki satu atribut info sebagai data utama, serta dua pointer bernama left dan right yang menunjuk ke node anak kiri dan kanan. file ini juga memuat deklarasi fungsi traversal seperti preOrder dan postOrder yang nantinya dimanfaatkan dalam program utama untuk menampilkan isi tree sesuai urutan kunjungan tertentu. Struktur header ini mendukung modularitas karena pemanggilan fungsi di main.cpp dapat dilakukan tanpa mengetahui detail implementasi yang terletak pada file lain.

Implementasi fungsi tersebut dijelaskan dalam bstree.cpp. Setelah tree terbentuk melalui penyisipan data menggunakan insertNode, proses penelusuran dapat dilakukan dengan beberapa metode traversal. Fungsi preOrder mengunjungi node dalam urutan root–left–right, yang berarti node pusat (root) dicetak terlebih dahulu sebelum subtree kiri dan kanan diproses secara rekursif. Dengan demikian, traversal ini sering digunakan untuk menampilkan struktur hierarki atau menyalin tree karena node utama selalu diproses lebih dahulu. Sementara itu, postOrder mengunjungi node dalam urutan left–right–root, yaitu node dicetak setelah seluruh proses pada subtree kiri dan kanan selesai. Pola ini umum digunakan dalam operasi yang memerlukan pemrosesan anak terlebih dahulu seperti pada proses deleteTree, karena root dihapus paling akhir untuk mencegah kehilangan akses ke subtree.

Pada main.cpp, beberapa node terlebih dahulu dimasukkan ke dalam tree sehingga struktur BST terbentuk berdasarkan aturan penyisipan nilai (nilai kecil di kiri, nilai besar di kanan). Setelah menampilkan tree dengan inOrder yang menghasilkan urutan data terurut, program juga menghitung karakteristik struktur seperti kedalaman tree, jumlah node, dan total nilai seluruh node. Kemudian, fungsi preOrder dipanggil untuk memperlihatkan urutan kunjungan node yang menyoroti struktur hierarki pohon mulai dari root ke level yang lebih rendah. Berikutnya, fungsi postOrder dijalankan untuk menampilkan hasil penelusuran dengan urutan pemrosesan anak terlebih dahulu, menunjukkan bagaimana rekursi mengunjungi node secara mendalam sebelum kembali ke tingkat atas tree.

## Kesimpulan
Dapat disimpulkan bahwa struktur data tree merupakan struktur non-linear yang digunakan untuk merepresentasikan hubungan hierarki antar data dalam bentuk node dan edge. Pada implementasinya, tree memiliki satu elemen utama yaitu root, diikuti node lain yang berperan sebagai parent dan child sesuai tingkatannya. Struktur ini lebih fleksibel dibanding struktur data linear karena memungkinkan proses penyisipan dan penghapusan node tanpa harus melakukan pergeseran elemen secara keseluruhan seperti pada array.

Melalui praktikum ini, penerapan konsep rekursi berperan sangat penting, terutama pada proses traversal dan operasi lain seperti pencarian, penghitungan jumlah node, kedalaman tree, dan penghapusan node. Tiga jenis traversal yang digunakan, yaitu preorder, inorder, dan postorder, masing-masing memiliki tujuan yang berbeda, salah satunya traversal inorder yang menghasilkan output dalam bentuk data terurut secara menaik ketika tree yang digunakan merupakan BST.

Pada bagian implementasi Binary Search Tree, diterapkan aturan bahwa nilai yang lebih kecil ditempatkan pada subtree kiri dan nilai lebih besar pada subtree kanan. Dengan aturan tersebut, operasi searching dan traversal dapat dilakukan lebih efisien dibandingkan struktur data linear. Proses insert, search, dan delete juga berhasil diuji menggunakan pendekatan rekursif, termasuk penghapusan node dengan tiga kondisi yaitu ketika node merupakan leaf, memiliki satu child, maupun dua child yang memerlukan penggantian nilai menggunakan successor.

## Referensi
<br>
[1] Dalal, A., & Atri, A. (2014). A Study on Binary Tree. International Journal of Research, 1(10), 1275–1280. 
</br>

<br>
[2] Donchev, I., & Todorova, E. (2015). Implementation of Binary Search Trees Via Smart Pointers. International Journal of Advanced Computer Science and Applications, 6(3), 59–64. 
</br>
