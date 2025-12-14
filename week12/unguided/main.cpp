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

    cout << "=== DFS TRAVERSAL dari node A ===" << endl;
    PrintDFS(G, nodeA);
    cout << endl;

    cout << "\n=== BFS TRAVERSAL dari node A ===" << endl;
    PrintBFS(G, nodeA);
    cout << endl;

    return 0;
}