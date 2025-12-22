#include "graph.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void createGraph(GraphKota &G) {
    G.First = NULL;
}

adrKota alokasiNode(string namaKota) {
    adrKota nodeBaru = new ElmKota;
    nodeBaru->namaKota = namaKota;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->next = NULL;
    return nodeBaru;
}

adrEdge alokasiEdge(adrKota kotaTujuan, int jarak) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->kotaTujuan = kotaTujuan;
    edgeBaru->jarak = jarak;
    edgeBaru->next = NULL;
    return edgeBaru;
}

void insertNode(GraphKota &G, string namaKota) {
    adrKota nodeBaru = alokasiNode(namaKota);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        adrKota nodeBantu = G.First;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

adrKota findNode(GraphKota G, string namaKota) {
    adrKota nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->namaKota == namaKota) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string kota1, string kota2, int jarak) {
    adrKota node1 = findNode(G, kota1);
    adrKota node2 = findNode(G, kota2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = alokasiEdge(node2, jarak);
        edge1->next = node1->firstEdge;
        node1->firstEdge = edge1;

        adrEdge edge2 = alokasiEdge(node1, jarak);
        edge2->next = node2->firstEdge;
        node2->firstEdge = edge2;
    } else {
        cout << "Kota tidak ditemukan!" << endl;
    }
}

void disconnectNode(adrKota node1, adrKota node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge prevEdge = NULL;

        while (edgeBantu != NULL && edgeBantu->kotaTujuan != node2) {
            prevEdge = edgeBantu;
            edgeBantu = edgeBantu->next;
        }

        if (edgeBantu != NULL) {
            if (prevEdge == NULL) {
                node1->firstEdge = edgeBantu->next;
            } else {
                prevEdge->next = edgeBantu->next;
            }
            delete edgeBantu;
        }
    }
}

void deleteNode(GraphKota &G, string namaKota) {
    adrKota nodeHapus = findNode(G, namaKota);
    if (nodeHapus == NULL) {
        cout << "Kota tidak ditemukan!" << endl;
        return;
    }

    adrKota nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        disconnectNode(nodeLainnya, nodeHapus);
        nodeLainnya = nodeLainnya->next;
    }

    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempEdge = edgeBantu;
        edgeBantu = edgeBantu->next;
        delete tempEdge;
    }
    nodeHapus->firstEdge = NULL;

    if (G.First == nodeHapus) {
        G.First = nodeHapus->next;
    } else {
        adrKota nodeBantu = G.First;
        while (nodeBantu->next != nodeHapus) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeHapus->next;
    }

    delete nodeHapus;
}

void printGraph(GraphKota G) {
    if (G.First == NULL) {
        cout << "Graph kosong!" << endl;
        return;
    }
    
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->namaKota << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        if (edgeBantu == NULL) {
            cout << "(tidak ada koneksi)";
        } else {
            while (edgeBantu != NULL) {
                cout << edgeBantu->kotaTujuan->namaKota << "(" << edgeBantu->jarak << " KM)";
                if (edgeBantu->next != NULL) {
                    cout << ", ";
                } else {
                    cout << ",";
                }
                edgeBantu = edgeBantu->next;
            }
        }
        cout << endl;
        nodeBantu = nodeBantu->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota nodeBantu = G.First;
    while (nodeBantu != NULL) {
        nodeBantu->visited = 0;
        nodeBantu = nodeBantu->next;
    }
}

void printBFS(GraphKota &G, string startKota) {
    resetVisited(G);
    adrKota startNode = findNode(G, startKota);
    if (startNode == NULL) {
        cout << "Kota tidak ditemukan!" << endl;
        return;
    }
    
    queue<adrKota> q;
    q.push(startNode);
    startNode->visited = 1;
    
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        adrKota current = q.front();
        q.pop();
        cout << current->namaKota << " - ";
        
        adrEdge edgeBantu = current->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->kotaTujuan->visited == 0) {
                q.push(edgeBantu->kotaTujuan);
                edgeBantu->kotaTujuan->visited = 1;
            }
            edgeBantu = edgeBantu->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota &G, string startKota) {
    resetVisited(G);
    adrKota startNode = findNode(G, startKota);
    if (startNode == NULL) {
        cout << "Kota tidak ditemukan!" << endl;
        return;
    }
    
    stack<adrKota> s;
    s.push(startNode);
    
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        adrKota current = s.top();
        s.pop();
        
        if (current->visited == 0) {
            cout << current->namaKota << " - ";
            current->visited = 1;
            
            adrEdge edgeBantu = current->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->kotaTujuan->visited == 0) {
                    s.push(edgeBantu->kotaTujuan);
                }
                edgeBantu = edgeBantu->next;
            }
        }
    }
    cout << endl;
}