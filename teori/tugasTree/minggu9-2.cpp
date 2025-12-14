#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char data;
    Node* firstChild;
    Node* nextSibling;

    Node(char val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

void addChild(Node* parent, Node* child) {
    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling) temp = temp->nextSibling;
        temp->nextSibling = child;
    }
}

void bracketNotation(Node* node) {
    if (!node) return;

    cout << node->data;

    if (node->firstChild) {
        cout << "(";
        Node* child = node->firstChild;
        while (child) {
            bracketNotation(child);
            if (child->nextSibling) cout << ", ";
            child = child->nextSibling;
        }
        cout << ")";
    }
}

void printLevelNotation(Node* node, int level) {
    for (int i = 0; i < level; i++) cout << "|-- ";
    cout << node->data << endl;

    Node* child = node->firstChild;
    while (child) {
        printLevelNotation(child, level + 1);
        child = child->nextSibling;
    }
}

int main() {
    Node* X = new Node('X');
    Node* Y = new Node('Y');
    Node* R = new Node('R');
    Node* S = new Node('S');
    Node* Q = new Node('Q');
    Node* U = new Node('U');
    Node* W = new Node('W');
    Node* T = new Node('T');
    Node* Z = new Node('Z');
    Node* P = new Node('P');
    Node* M = new Node('M');
    Node* N = new Node('N');

    addChild(X, Y);
    addChild(X, R);
    addChild(X, S);
    addChild(Y, Q);
    addChild(R, T);
    addChild(R, U);
    addChild(R, W);
    addChild(S, Z);
    addChild(Q, P);
    addChild(Q, M);
    addChild(U, N);

    cout << "--- Bracket Notation ---" << endl;
    bracketNotation(X);
    cout << endl << endl;

    cout << "--- Level Notation ---" << endl;
    printLevelNotation(X, 0);
    cout << endl;

    return 0;
}