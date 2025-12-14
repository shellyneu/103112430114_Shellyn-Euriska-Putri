#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

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

void ResetVisited(Graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        nodeBantu->visited = NULL;
        nodeBantu = nodeBantu->Next;
    }
}