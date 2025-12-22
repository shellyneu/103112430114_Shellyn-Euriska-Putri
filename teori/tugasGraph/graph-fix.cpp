#include <iostream>

using namespace std;

struct ElementVertex;

typedef ElementVertex* adrVertex;

struct ElementEdge {
    adrVertex destination;
    ElementEdge* nextEdge;
};

typedef ElementEdge* adrEdge;

struct ElementVertex {
    char info;
    adrEdge firstEdge;
    adrVertex nextVertex;
};

struct Graph {
    adrVertex firstVertex;
};

void createGraph(Graph &G) {
    G.firstVertex = nullptr;
}

adrVertex alokasiVertex(char id) {
    adrVertex P = new ElementVertex;
    P->info = id;
    P->firstEdge = nullptr;
    P->nextVertex = nullptr;
    return P;
}

adrEdge alokasiEdge(adrVertex dest) {
    adrEdge E = new ElementEdge;
    E->destination = dest;
    E->nextEdge = nullptr;
    return E;
}

void addVertex(Graph &G, char id) {
    adrVertex P = alokasiVertex(id);
    if (G.firstVertex == nullptr) {
        G.firstVertex = P;
    } else {
        adrVertex last = G.firstVertex;
        while (last->nextVertex != nullptr) {
            last = last->nextVertex;
        }
        last->nextVertex = P;
    }
}

adrVertex findVertex(Graph G, char id) {
    adrVertex P = G.firstVertex;
    while (P != nullptr) {
        if (P->info == id) {
            return P;
        }
        P = P->nextVertex;
    }
    return nullptr;
}

void addEdge(Graph &G, char id1, char id2) {
    adrVertex v1 = findVertex(G, id1);
    adrVertex v2 = findVertex(G, id2);

    if (v1 != nullptr && v2 != nullptr) {
        adrEdge e1 = alokasiEdge(v2);
        e1->nextEdge = v1->firstEdge;
        v1->firstEdge = e1;

        adrEdge e2 = alokasiEdge(v1);
        e2->nextEdge = v2->firstEdge;
        v2->firstEdge = e2;
    }
}

int countVertex(Graph G) {
    int count = 0;
    adrVertex P = G.firstVertex;
    while (P != nullptr) {
        count++;
        P = P->nextVertex;
    }
    return count;
}

int countDegree(adrVertex P) {
    int degree = 0;
    if (P != nullptr) {
        adrEdge E = P->firstEdge;
        while (E != nullptr) {
            degree++;
            E = E->nextEdge;
        }
    }
    return degree;
}

bool isComplete(Graph G) {
    int n = countVertex(G);
    
    if (n <= 1) return true; 

    adrVertex P = G.firstVertex;
    while (P != nullptr) {
        if (countDegree(P) != (n - 1)) {
            return false;
        }
        P = P->nextVertex;
    }
    return true;
}

int main() {
    Graph G;
    createGraph(G);

    addVertex(G, 'A');
    addVertex(G, 'B');
    addVertex(G, 'C');
    addVertex(G, 'D');

    addEdge(G, 'A', 'B');
    addEdge(G, 'A', 'C');
    addEdge(G, 'A', 'D');
    addEdge(G, 'B', 'D');

    cout << "\nCoba isComplete" << endl;
    cout << "Jumlah Simpul (N): " << countVertex(G) << endl;
    
    if (isComplete(G)) {
        cout << "Graph Lengkap" << endl;
    } else {
        cout << "Graph TIDAK Lengkap" << endl;
    }

    cout << "\nCoba findVertex" << endl;
    adrVertex foundC = findVertex(G, 'C');
    adrVertex foundZ = findVertex(G, 'Z');
    
    cout << "Cari Simpul 'C': ";
    if (foundC != nullptr) {
        cout << "DITEMUKAN (Alamat Info: " << foundC->info << ")" << endl;
    } else {
        cout << "TIDAK DITEMUKAN" << endl;
    }
    

    return 0;
}