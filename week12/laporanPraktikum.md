# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH </h1>
<p align="center">Shellyn Euriska Putri - 103112430114</p>

## Dasar Teori
Struktur data graph merupakan salah satu struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar objek secara fleksibel dan kompleks. Secara formal, graph didefinisikan sebagai himpunan tidak kosong yang terdiri atas simpul (vertex) dan sisi (edge) yang menghubungkan pasangan simpul tertentu. Berbeda dengan struktur data linier seperti array, stack, atau linked list yang hanya merepresentasikan hubungan sekuensial, graph mampu memodelkan relasi banyak-ke-banyak (many-to-many) sehingga sangat relevan untuk merepresentasikan permasalahan dunia nyata, seperti jaringan komputer, peta jalan, sistem prasyarat mata kuliah, hingga struktur dependensi dalam perangkat lunak. Sifat inilah yang menjadikan graph sebagai struktur data fundamental dalam bidang ilmu komputer, khususnya pada pemodelan data dan analisis algoritma.

Berdasarkan karakteristik arah sisi, graph dapat diklasifikasikan menjadi graph berarah (directed graph) dan graph tidak berarah (undirected graph). Pada graph berarah, setiap edge memiliki orientasi tertentu dari satu vertex ke vertex lain, sehingga hubungan yang terbentuk bersifat satu arah. Sebaliknya, pada graph tidak berarah, edge tidak memiliki arah sehingga hubungan antar vertex bersifat dua arah. Selain itu, edge pada graph juga dapat memiliki bobot (weighted graph) yang merepresentasikan nilai tertentu, seperti jarak, biaya, atau waktu tempuh. Informasi bobot ini menjadi dasar dalam berbagai algoritma graph, seperti pencarian lintasan terpendek dan optimasi jaringan. Dengan demikian, pemahaman mengenai jenis-jenis graph menjadi penting sebelum mengimplementasikannya ke dalam program.

Dalam implementasinya, graph dapat direpresentasikan ke dalam memori komputer menggunakan beberapa pendekatan, antara lain matriks ketetanggaan (adjacency matrix) dan daftar ketetanggaan (adjacency list). Representasi matriks ketetanggaan menggunakan array dua dimensi berukuran 𝑛×𝑛, dengan 𝑛 menyatakan jumlah vertex, di mana setiap elemen matriks menunjukkan ada atau tidaknya edge antara dua vertex tertentu. Representasi ini sederhana dan mudah dipahami, namun kurang efisien dari sisi penggunaan memori untuk graph berukuran besar dan jarang (sparse graph). Oleh karena itu, representasi daftar ketetanggaan lebih sering digunakan karena bersifat dinamis dan lebih hemat memori, terutama ketika jumlah edge jauh lebih kecil dibandingkan jumlah kemungkinan pasangan vertex.

Pendekatan daftar ketetanggaan dapat dikembangkan lebih lanjut menggunakan struktur data pointer dalam bentuk multilist atau linked list bersarang. Pada representasi ini, setiap vertex memiliki pointer ke daftar edge yang terhubung dengannya, sehingga memungkinkan penambahan dan penghapusan node maupun edge secara dinamis selama program berjalan. Konsep ini sejalan dengan prinsip struktur data dinamis, di mana alokasi memori dapat menyesuaikan kebutuhan sistem. Penggunaan pointer dalam representasi graph juga memberikan pemahaman yang lebih mendalam mengenai pengelolaan memori dan hubungan antar data, yang menjadi kompetensi penting dalam pembelajaran struktur data.

Selain sebagai struktur data statis, graph juga sering digunakan sebagai dasar untuk berbagai algoritma penelusuran (traversal), seperti Breadth First Search (BFS) dan Depth First Search (DFS). BFS melakukan penelusuran graph secara melebar dengan mengunjungi vertex berdasarkan tingkat kedalaman, sedangkan DFS melakukan penelusuran secara mendalam hingga mencapai vertex terdalam sebelum kembali ke cabang lain. Kedua algoritma ini menjadi dasar dalam berbagai aplikasi, seperti pencarian jalur, pendeteksian siklus, serta pembentukan struktur tree dari graph. Dalam konteks graph berarah, traversal juga berperan penting dalam proses topological sort, yaitu proses penyusunan urutan linear dari vertex berdasarkan hubungan ketergantungan parsial.

Konsep graph tidak hanya terbatas pada struktur data klasik, tetapi juga berkembang dalam bidang analisis perangkat lunak dan sistem berskala besar. Grass dan Chen (1990) menunjukkan bahwa struktur program C++ dapat dimodelkan dalam bentuk graph, di mana entitas seperti file, fungsi, variabel, dan tipe data direpresentasikan sebagai vertex, sedangkan relasi seperti pemanggilan fungsi, pewarisan, dan dependensi direpresentasikan sebagai edge [1]. Representasi graph semacam ini memungkinkan visualisasi dan analisis struktur program secara lebih sistematis, misalnya untuk membangun call graph, inheritance graph, atau dependency graph. Hal ini menunjukkan bahwa graph berperan penting tidak hanya sebagai struktur data, tetapi juga sebagai alat analisis konseptual dalam rekayasa perangkat lunak.

Seiring dengan berkembangnya kebutuhan pemrosesan data berskala besar, graph juga menjadi fondasi utama dalam graph analytics modern. Osama dkk. (2022) menjelaskan bahwa analisis graph berskala besar membutuhkan abstraksi yang efisien karena ukuran graph yang semakin besar dan kompleks [2]. Dalam konteks ini, graph dipandang sebagai struktur data “native” yang diproses langsung melalui vertex atau edge, bukan sekadar direduksi menjadi bentuk matriks. Pendekatan ini menekankan pentingnya traversal graph, himpunan vertex aktif (frontier), serta proses iteratif hingga kondisi konvergensi tercapai. Konsep tersebut menunjukkan bahwa pemahaman dasar mengenai struktur data graph menjadi prasyarat penting sebelum mempelajari analisis graph paralel dan terdistribusi.


## Guided 
### 1.1. graph.h

```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G); //prosedur untuk mengeset first dari graph
adrNode AlokasiNode(infoGraph data); //alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); //prosedur untuk alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); //Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph info1); //function untuk mencari alamat Node berdasarkan info
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan Node
void DisconnectNode(adrNode node1, adrNode node2); //prosedur untuk memutuskan hubungan Node
void DeleteNode(Graph &G, infoGraph X); //prosedur untuk menghapus Node

void PrintInfoGraph(Graph G); //Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); //traversal Breadth First Search
void PrintDFS(Graph G, infoGraph StartInfo); //traversal Depth First Search


#endif
```

### 1.2. graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

### 1.3 main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    //isi node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G'); // Node 'G' diasumsikan berdasarkan konteks sebelumnya

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'D', 'E');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'F'); // Baris duplikat, dipertahankan sesuai gambar
    ConnectNode(G, 'E', 'F');
    ConnectNode(G, 'F', 'G'); // Asumsi untuk Node 'G'

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil dihapus." << endl;
    } else {
        cout << "Node E gagal dihapus." << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    return 0;
}
```
file graph.h berfungsi sebagai header yang mendefinisikan struktur dasar dan prototipe fungsi untuk mengelola struktur data graph. Pada bagian awal, digunakan mekanisme header guard (#ifndef, #define, dan #endif) untuk mencegah terjadinya duplikasi pendefinisian ketika file ini dipanggil lebih dari satu kali. Tipe data infoGraph didefinisikan sebagai char, yang berarti setiap simpul (node) dalam graph akan direpresentasikan menggunakan satu karakter, seperti ‘A’, ‘B’, dan seterusnya. Pendekatan ini mempermudah visualisasi graph dalam konteks praktikum. Selain itu, digunakan pula tipe pointer adrNode dan adrEdge untuk merepresentasikan alamat simpul dan alamat sisi (edge), yang menegaskan bahwa graph diimplementasikan menggunakan struktur data dinamis berbasis pointer.

Struktur ElmNode merepresentasikan simpul dalam graph. Setiap node menyimpan informasi berupa info, penanda visited yang digunakan saat proses traversal, pointer firstEdge yang menunjuk ke daftar sisi yang terhubung dengan node tersebut, serta pointer Next yang menghubungkan node satu dengan node lainnya dalam daftar utama graph. Dengan demikian, daftar node membentuk sebuah linked list, sedangkan daftar edge pada setiap node juga membentuk linked list tersendiri. Struktur ElmEdge digunakan untuk merepresentasikan sisi, yang menyimpan alamat node tujuan dan pointer ke edge berikutnya. Sementara itu, struktur Graph hanya memiliki satu pointer First yang menunjuk ke node pertama, sehingga graph secara keseluruhan direpresentasikan sebagai adjacency list berbasis multilist.

Pada bagian deklarasi fungsi, CreateGraph digunakan untuk menginisialisasi graph agar berada pada kondisi kosong. Fungsi alokasi node dan edge disediakan untuk menangani pembuatan elemen baru secara dinamis. Selain itu, terdapat fungsi-fungsi untuk menambahkan node, mencari node berdasarkan informasi tertentu, menghubungkan dua node, memutuskan hubungan antar node, serta menghapus node beserta seluruh edge yang terkait dengannya. Untuk keperluan visualisasi dan pengujian algoritma, disediakan pula fungsi untuk menampilkan isi graph, mereset status kunjungan, serta melakukan traversal BFS dan DFS.

Implementasi fungsi-fungsi tersebut terdapat pada file graph.cpp. Fungsi CreateGraph menginisialisasi graph dengan mengeset pointer First bernilai NULL, yang menandakan bahwa graph masih kosong. Proses alokasi node dilakukan melalui fungsi AlokasiNode, yang membuat node baru di memori, mengisi nilai informasinya, mengatur status visited menjadi nol, serta memastikan pointer ke edge dan node berikutnya bernilai NULL. Hal serupa diterapkan pada fungsi AlokasiEdge, yang bertugas membuat edge baru dengan menyimpan alamat node tujuan.

Fungsi InsertNode digunakan untuk menambahkan node ke dalam graph dengan konsep insert last. Jika graph masih kosong, node baru langsung menjadi node pertama. Namun, jika graph sudah memiliki node, maka program akan menelusuri daftar node hingga node terakhir dan menambahkan node baru di bagian akhir. Pendekatan ini menjaga urutan node sesuai dengan urutan penambahan. Fungsi FindNode kemudian digunakan untuk mencari alamat node tertentu dengan membandingkan nilai info dari setiap node, yang sangat penting untuk operasi penghubungan, penghapusan, maupun traversal.

Penghubungan antar node dilakukan melalui fungsi ConnectNode. Fungsi ini terlebih dahulu mencari alamat kedua node yang akan dihubungkan. Jika kedua node ditemukan, maka dibuat edge baru dari node pertama ke node kedua dan sebaliknya. Hal ini menunjukkan bahwa graph yang diimplementasikan bersifat tidak berarah (undirected graph). Penyisipan edge dilakukan dengan metode insert first pada daftar edge, sehingga edge terbaru akan berada di awal daftar ketetanggaan node tersebut. Jika salah satu node tidak ditemukan, program akan menampilkan pesan kesalahan.

Fungsi DisconnectNode bertugas memutuskan hubungan dari satu node ke node lainnya dengan cara menelusuri daftar edge milik node pertama. Jika edge yang mengarah ke node tujuan ditemukan, edge tersebut akan dihapus dengan menyesuaikan pointer sebelumnya. Proses ini penting untuk menjaga konsistensi graph, terutama saat dilakukan penghapusan node. Penghapusan node secara menyeluruh diimplementasikan dalam fungsi DeleteNode. Proses ini dimulai dengan mencari node yang akan dihapus. Jika node tidak ditemukan, proses dihentikan. Selanjutnya, semua edge dari node lain yang mengarah ke node tersebut dihapus terlebih dahulu, kemudian seluruh edge yang keluar dari node tersebut juga didealokasi. Setelah semua hubungan terputus, node dihapus dari daftar utama graph dan memori yang digunakan dibebaskan. Pendekatan ini memastikan tidak ada pointer menggantung (dangling pointer) yang dapat menyebabkan kesalahan memori.

Untuk menampilkan struktur graph, fungsi PrintInfoGraph digunakan. Fungsi ini menelusuri setiap node dan mencetak daftar node yang terhubung dengannya berdasarkan adjacency list. Tampilan ini memudahkan pengguna untuk memahami struktur graph secara visual. Sebelum melakukan traversal, fungsi ResetVisited digunakan untuk mengatur ulang status visited seluruh node menjadi nol, sehingga traversal dapat dilakukan dari kondisi awal yang bersih.

Traversal Breadth First Search (BFS) diimplementasikan dalam fungsi PrintBFS dengan memanfaatkan struktur data queue. Proses traversal dimulai dari node awal yang ditentukan, kemudian node tersebut dimasukkan ke dalam queue dan ditandai sebagai telah dikunjungi. Selanjutnya, program akan memproses node satu per satu dari queue, mencetak informasinya, lalu memasukkan semua tetangga yang belum dikunjungi ke dalam queue. Dengan cara ini, BFS menelusuri graph secara melebar berdasarkan tingkat kedalaman. Sementara itu, traversal Depth First Search (DFS) diimplementasikan menggunakan stack. Node awal dimasukkan ke dalam stack, kemudian diproses dengan prinsip LIFO. Setiap node yang diambil dari stack akan ditandai sebagai dikunjungi dan seluruh tetangganya yang belum dikunjungi akan dimasukkan kembali ke dalam stack. Pendekatan ini membuat DFS menelusuri graph secara mendalam sebelum berpindah ke cabang lain.

file main.cpp berfungsi sebagai program utama untuk menguji seluruh fungsi yang telah dibuat. Pada bagian awal, graph diinisialisasi dan sejumlah node ditambahkan ke dalam graph. Setelah itu, node-node tersebut dihubungkan sesuai dengan struktur graph yang diinginkan. Program kemudian menampilkan representasi adjacency list untuk memastikan bahwa graph telah terbentuk dengan benar. Selanjutnya, traversal BFS dan DFS dijalankan dari node awal ‘A’ untuk melihat urutan penelusuran graph.

Setelah itu, program melakukan penghapusan node ‘E’ beserta seluruh hubungan yang terkait dengannya. Keberhasilan penghapusan diverifikasi dengan memanggil kembali fungsi pencarian node. Terakhir, graph kembali ditampilkan dan traversal diulang untuk menunjukkan bahwa struktur graph telah berubah sesuai dengan operasi penghapusan yang dilakukan. Secara keseluruhan, program ini menunjukkan implementasi lengkap struktur data graph tidak berarah menggunakan adjacency list, mulai dari pembuatan, manipulasi, traversal, hingga penghapusan node, dengan pendekatan yang sesuai untuk pembelajaran struktur data pada tingkat mahasiswa.


## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”. Kemudian, buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

#### graph.h

```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    adrNode visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintinfoGraph(Graph G);
adrNode FindNode(Graph G, infoGraph X);


#endif
```

##### graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = NULL;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    
    if (G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge edgeBaru1 = new ElmEdge;
        edgeBaru1->Node = N2;
        edgeBaru1->Next = N1->firstEdge;
        N1->firstEdge = edgeBaru1;
        
        adrEdge edgeBaru2 = new ElmEdge;
        edgeBaru2->Node = N1;
        edgeBaru2->Next = N2->firstEdge;
        N2->firstEdge = edgeBaru2;
    }
}

void PrintinfoGraph(Graph G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == X) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}
```

##### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode nodeA = FindNode(G, 'A');
    adrNode nodeB = FindNode(G, 'B');
    adrNode nodeC = FindNode(G, 'C');
    adrNode nodeD = FindNode(G, 'D');
    adrNode nodeE = FindNode(G, 'E');
    adrNode nodeF = FindNode(G, 'F');
    adrNode nodeG = FindNode(G, 'G');
    adrNode nodeH = FindNode(G, 'H');

    ConnectNode(nodeA, nodeB);
    ConnectNode(nodeA, nodeC);
    ConnectNode(nodeB, nodeD);
    ConnectNode(nodeB, nodeE);
    ConnectNode(nodeC, nodeF);
    ConnectNode(nodeC, nodeG);
    ConnectNode(nodeD, nodeH);
    ConnectNode(nodeE, nodeH);
    ConnectNode(nodeF, nodeH);
    ConnectNode(nodeG, nodeH);

    PrintinfoGraph(G);
    cout << endl;

    return 0;
}
```

### Output Unguided :
##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week12/output/output-unguided1.png)
file graph.h berperan sebagai antarmuka utama yang mendefinisikan struktur data dan fungsi-fungsi dasar untuk membangun graph. Pada bagian awal, digunakan header guard untuk mencegah terjadinya pendefinisian ganda ketika file ini dipanggil lebih dari satu kali. Tipe data infoGraph didefinisikan sebagai char, yang berarti setiap simpul dalam graph direpresentasikan oleh satu karakter. Pendefinisian tipe pointer adrNode dan adrEdge digunakan untuk mempermudah penulisan kode serta menegaskan bahwa graph diimplementasikan menggunakan struktur data dinamis berbasis pointer.

Struktur ElmNode merepresentasikan simpul (node) dalam graph. Setiap node menyimpan informasi berupa info, pointer visited, pointer firstEdge yang menunjuk ke daftar sisi yang terhubung dengan node tersebut, serta pointer Next yang menghubungkan node ke node berikutnya dalam daftar node utama. Keberadaan pointer Next menunjukkan bahwa seluruh node dalam graph disimpan dalam bentuk linked list. Sementara itu, struktur ElmEdge digunakan untuk merepresentasikan sisi (edge) yang menghubungkan satu node ke node lain. Struktur ini menyimpan alamat node tujuan dan pointer ke edge berikutnya, sehingga daftar edge pada setiap node juga membentuk linked list tersendiri. Struktur Graph sendiri hanya memiliki satu pointer first yang menunjuk ke node pertama dalam graph, sehingga graph direpresentasikan menggunakan adjacency list berbasis multilist.

Pada file graph.cpp, fungsi CreateGraph digunakan untuk menginisialisasi graph dengan mengatur pointer first bernilai NULL, yang menandakan bahwa graph masih dalam kondisi kosong. Fungsi InsertNode bertugas menambahkan node baru ke dalam graph. Pada fungsi ini, node baru dialokasikan secara dinamis, kemudian nilai informasi diisikan sesuai dengan parameter yang diberikan. Pointer visited, firstEdge, dan Next diatur bernilai NULL sebagai kondisi awal. Proses penyisipan node dilakukan dengan konsep insert last, di mana node baru akan ditempatkan di akhir daftar node. Pendekatan ini menjaga urutan node sesuai dengan urutan penambahan yang dilakukan pada program utama.

Fungsi ConnectNode digunakan untuk menghubungkan dua node yang telah ada di dalam graph. Fungsi ini menerima dua parameter berupa alamat node, kemudian membuat dua edge baru yang saling berlawanan arah. Hal ini menunjukkan bahwa graph yang diimplementasikan bersifat tidak berarah (undirected graph). Setiap edge disisipkan di awal daftar edge milik node terkait dengan metode insert first. Dengan demikian, hubungan antar node dapat ditelusuri melalui adjacency list masing-masing node. Fungsi ini hanya akan dijalankan apabila kedua node yang akan dihubungkan tidak bernilai NULL, sehingga menghindari kesalahan akibat pengaksesan pointer yang tidak valid.

Untuk menampilkan isi graph, fungsi PrintinfoGraph digunakan. Fungsi ini menelusuri seluruh node yang ada dalam graph, kemudian untuk setiap node mencetak daftar node lain yang terhubung dengannya. Proses ini dilakukan dengan menelusuri linked list edge pada masing-masing node. Hasil keluaran dari fungsi ini memberikan gambaran struktur graph dalam bentuk adjacency list, sehingga hubungan antar node dapat diamati secara langsung. Selain itu, fungsi FindNode disediakan untuk mencari alamat node tertentu berdasarkan nilai informasinya. Fungsi ini sangat penting karena digunakan sebagai dasar untuk menghubungkan node-node pada program utama.

file main.cpp berfungsi sebagai program utama yang menguji implementasi graph. Pada awal program, graph diinisialisasi menggunakan fungsi CreateGraph. Selanjutnya, sejumlah node dengan label ‘A’ hingga ‘H’ dimasukkan ke dalam graph menggunakan fungsi InsertNode. Setelah seluruh node ditambahkan, program mencari alamat masing-masing node menggunakan fungsi FindNode dan menyimpannya ke dalam variabel pointer. Langkah ini diperlukan agar proses penghubungan node dapat dilakukan dengan mudah dan aman.

Setelah itu, node-node dihubungkan sesuai dengan struktur graph yang diinginkan menggunakan fungsi ConnectNode. Pola penghubungan yang dilakukan membentuk graph dengan satu node pusat, yaitu node ‘H’, yang terhubung dengan beberapa node lainnya. Setelah seluruh hubungan terbentuk, fungsi PrintinfoGraph dipanggil untuk menampilkan representasi adjacency list dari graph tersebut. Dengan demikian, program ini menunjukkan implementasi dasar struktur data graph tidak berarah menggunakan adjacency list, mulai dari proses pembuatan graph, penambahan node, penghubungan antar node, hingga penampilan struktur graph secara keseluruhan.


### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintDFS (Graph G, adrNode N);

#### graph.h
```h
void PrintDFS(Graph G, adrNode N);
```

##### graph.cpp
```C++
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == NULL) {
            nodeBantu->visited = nodeBantu;
            cout << nodeBantu->info << " - ";

            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == NULL) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

##### main.cpp
```C++
    cout << "=== DFS TRAVERSAL dari node A ===" << endl;
    PrintDFS(G, nodeA);
    cout << endl;
```

### Output Unguided :
##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week12/output/output-unguided2.png)
Pada file graph.h, fungsi PrintDFS dideklarasikan sebagai prosedur yang bertugas menampilkan hasil penelusuran graph menggunakan metode Depth First Search. Fungsi ini menerima parameter berupa struktur Graph dan sebuah node awal sebagai titik mulai traversal. Deklarasi ini menunjukkan bahwa proses DFS dilakukan dengan mengacu pada kondisi graph secara keseluruhan, namun penelusurannya dimulai dari satu node tertentu yang telah ditentukan sebelumnya.

Implementasi fungsi PrintDFS pada file graph.cpp diawali dengan pemanggilan prosedur ResetVisited. Langkah ini bertujuan untuk memastikan bahwa seluruh node dalam graph berada dalam kondisi belum dikunjungi sebelum traversal dimulai. Dalam implementasi graph ini, status kunjungan tidak direpresentasikan menggunakan tipe data boolean atau integer, melainkan menggunakan pointer visited yang bernilai NULL jika node belum dikunjungi dan bernilai alamat node itu sendiri jika sudah dikunjungi. Pendekatan ini meskipun tidak umum, tetap sah secara logika karena memanfaatkan kondisi pointer untuk membedakan status kunjungan.

Setelah status kunjungan direset, fungsi mencari node awal berdasarkan informasi yang diberikan melalui pemanggilan fungsi FindNode. Jika node awal tidak ditemukan, proses traversal dihentikan untuk mencegah terjadinya kesalahan akses memori. Apabila node awal valid, proses DFS dilanjutkan dengan menggunakan struktur data stack. Penggunaan stack mencerminkan prinsip dasar DFS yang menelusuri graph secara mendalam terlebih dahulu sebelum berpindah ke cabang lain.

Node awal dimasukkan ke dalam stack sebagai langkah pertama. Selanjutnya, selama stack tidak kosong, node teratas akan diambil dan diproses. Jika node tersebut belum pernah dikunjungi, status visited pada node akan diubah dari NULL menjadi alamat node itu sendiri sebagai penanda bahwa node telah dikunjungi. Informasi node kemudian ditampilkan sebagai bagian dari hasil traversal. Proses ini mencerminkan konsep DFS, di mana sebuah node dikunjungi terlebih dahulu sebelum menelusuri node-node tetangganya.

Setelah sebuah node diproses, seluruh node tetangganya akan diperiksa melalui daftar edge yang dimiliki node tersebut. Jika ditemukan node tetangga yang belum dikunjungi, node tersebut dimasukkan ke dalam stack. Dengan mekanisme ini, node yang terakhir dimasukkan akan diproses lebih dahulu, sehingga traversal bergerak semakin dalam mengikuti jalur tertentu sebelum kembali dan menelusuri cabang lainnya. Proses ini berlangsung terus hingga stack kosong, yang menandakan bahwa seluruh node yang dapat dijangkau dari node awal telah dikunjungi.

Pada file main.cpp, fungsi PrintDFS dipanggil untuk melakukan traversal DFS dengan node ‘A’ sebagai titik awal. Pemanggilan ini menghasilkan urutan penelusuran node sesuai dengan prinsip Depth First Search dan struktur graph yang telah dibentuk sebelumnya. Hasil traversal ditampilkan ke layar sebagai bukti bahwa algoritma DFS berhasil diimplementasikan dan berjalan dengan benar.


### 3. Buatlah prosedur untuk menampilkanhasil penelusuran BFS. prosedur PrintBFS (Graph G, adrNode N);

#### graph.h
```h
void PrintBFS(Graph G, adrNode N);
```

##### graph.cpp
```C++
void PrintBFS(Graph G, adrNode N) {
    ResetVisited(G);
    adrNode StartNode = N;
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    Qyu.push(StartNode);
    StartNode->visited = StartNode;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == NULL) {
                edgeBantu->Node->visited = edgeBantu->Node;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}
```

##### main.cpp
```C++
    cout << "\n=== BFS TRAVERSAL dari node A ===" << endl;
    PrintBFS(G, nodeA);
    cout << endl;
```

### Output Unguided :
##### Output 
![Screenshot Output Unguided 1_1](https://github.com/shellyneu/103112430114_Shellyn-Euriska-Putri/blob/main/week12/output/output-unguided3.png)
Pada file graph.h, fungsi PrintBFS dideklarasikan sebagai prosedur yang digunakan untuk melakukan penelusuran graph dengan metode Breadth First Search. Fungsi ini menerima parameter berupa struktur Graph dan sebuah alamat node sebagai titik awal traversal. Dengan demikian, proses BFS tidak hanya bergantung pada kondisi graph secara keseluruhan, tetapi juga secara eksplisit ditentukan dari node mana penelusuran akan dimulai.

Implementasi fungsi PrintBFS pada file graph.cpp diawali dengan pemanggilan prosedur ResetVisited. Langkah ini bertujuan untuk mengembalikan seluruh status kunjungan node ke kondisi awal, yaitu belum dikunjungi. Pada implementasi graph ini, status kunjungan ditandai menggunakan pointer visited, di mana nilai NULL menunjukkan bahwa node belum dikunjungi, sedangkan nilai yang berisi alamat node menandakan bahwa node tersebut sudah pernah dikunjungi. Pendekatan ini memungkinkan pemeriksaan status kunjungan dilakukan dengan sederhana melalui pengecekan nilai pointer.

Setelah status kunjungan direset, node awal traversal diambil langsung dari parameter yang diberikan pada fungsi, tanpa perlu melakukan pencarian ulang. Apabila node awal bernilai NULL, proses traversal dihentikan untuk mencegah terjadinya kesalahan akses memori. Jika node awal valid, proses BFS dilanjutkan dengan menggunakan struktur data queue. Penggunaan queue mencerminkan karakteristik utama BFS, yaitu menelusuri graph secara melebar dengan prinsip First In First Out (FIFO).

Node awal dimasukkan ke dalam queue dan langsung ditandai sebagai telah dikunjungi. Selanjutnya, selama queue tidak kosong, node yang berada di bagian depan queue akan diambil dan diproses. Informasi dari node tersebut kemudian ditampilkan sebagai bagian dari hasil traversal. Setelah itu, seluruh node tetangga dari node yang sedang diproses diperiksa melalui daftar edge yang dimilikinya. Apabila ditemukan node tetangga yang belum dikunjungi, node tersebut akan ditandai sebagai telah dikunjungi dan dimasukkan ke dalam queue.

Mekanisme ini memastikan bahwa node-node yang berada pada tingkat kedalaman yang sama akan diproses terlebih dahulu sebelum berpindah ke tingkat berikutnya. Dengan kata lain, BFS menelusuri graph berdasarkan jarak dari node awal, sehingga traversal berlangsung secara berlapis. Proses ini akan terus berjalan hingga seluruh node yang dapat dijangkau dari node awal telah dikunjungi dan queue berada dalam kondisi kosong.

Pada file main.cpp, fungsi PrintBFS dipanggil dengan node ‘A’ sebagai titik awal traversal. Pemanggilan ini menghasilkan urutan penelusuran node sesuai dengan prinsip Breadth First Search dan struktur graph yang telah dibentuk sebelumnya. Hasil traversal yang ditampilkan ke layar dapat digunakan untuk memverifikasi bahwa algoritma BFS telah diimplementasikan dengan benar.

## Kesimpulan
Berdasarkan seluruh kode program yang telah diimplementasikan, dapat disimpulkan bahwa struktur data graph berhasil direalisasikan menggunakan pendekatan adjacency list berbasis pointer. Graph dibangun dengan memanfaatkan struktur node dan edge yang saling terhubung melalui linked list, sehingga memungkinkan representasi hubungan antar simpul secara dinamis. Pendekatan ini memberikan fleksibilitas dalam pengelolaan data, khususnya pada proses penambahan simpul dan pembentukan hubungan antar simpul, tanpa bergantung pada ukuran memori yang tetap seperti pada representasi berbasis matriks.

Implementasi fungsi-fungsi dasar seperti pembuatan graph, penambahan node, pencarian node, serta penghubungan antar node menunjukkan pemahaman terhadap konsep graph tidak berarah. Setiap hubungan antar simpul direpresentasikan oleh dua edge yang saling berlawanan arah, sehingga relasi antar node dapat ditelusuri dari kedua sisi. Selain itu, mekanisme penandaan kunjungan menggunakan pointer visited dimanfaatkan secara konsisten untuk mengontrol proses traversal dan mencegah terjadinya pengulangan kunjungan pada simpul yang sama.

Algoritma traversal Breadth First Search dan Depth First Search berhasil diterapkan dengan memanfaatkan struktur data queue dan stack. BFS menelusuri graph secara melebar berdasarkan tingkat kedalaman dari node awal, sedangkan DFS menelusuri graph secara mendalam dengan mengikuti satu jalur hingga mencapai simpul terdalam sebelum berpindah ke jalur lainnya. Hasil traversal yang ditampilkan menunjukkan bahwa kedua algoritma berjalan sesuai dengan konsep teoritisnya dan mampu menjelajahi seluruh simpul yang terhubung dari node awal.

## Referensi
<br>
[1] Grass, J. E., & Chen, Y.-F. (1990). The C++ Information Abstractor. AT&T Bell Laboratories.
</br>
<br>
[2] Osama, M., Porumbescu, S. D., & Owens, J. D. (2022). Essentials of Parallel Graph Analytics. arXiv preprint arXiv:2212.08200.
</br>
