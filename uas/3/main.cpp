#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    GraphKota G;

    cout << "Bagian A" << endl;
    
    cout << "1) Insert node dan connect node sehingga terbentuk graph" << endl;
    cout << endl;
    
    createGraph(G);
    
    insertNode(G, "Jakarta");
    insertNode(G, "Bekasi");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");
    insertNode(G, "Bogor");
    
    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Jakarta", "Tangerang", 24);
    connectNode(G, "Jakarta", "Bogor", 42);
    connectNode(G, "Bogor", "Depok", 22);
    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Depok", "Bekasi", 25);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Bekasi", "Tangerang", 45);
    
    cout << "Graph berhasil dibuat!" << endl;
    cout << endl << endl;
    
    cout << "2) printGraph()" << endl;
    printGraph(G);
    cout << endl << endl;
    
    cout << "3) deleteNode() -> Depok" << endl;
    deleteNode(G, "Depok");
    cout << "Node Depok berhasil dihapus!" << endl;
    cout << endl << endl;
    
    cout << "4) printGraph()" << endl;
    printGraph(G);
    cout << endl;
    
    cout << "Bagian B" << endl;
    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");
    cout << endl;

    return 0;
}