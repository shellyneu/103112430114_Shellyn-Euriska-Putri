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