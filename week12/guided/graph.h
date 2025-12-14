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