#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* parent;
    Node* firstChild;
    Node* nextSibling;
    Node(char val) : data(val), parent(nullptr), firstChild(nullptr), nextSibling(nullptr) {}
};

void addChild(Node* parent, Node* child) {
    child->parent = parent;
    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling) temp = temp->nextSibling;
        temp->nextSibling = child;
    }
}

Node* getRoot(Node* node) {
    while (node->parent) node = node->parent;
    return node;
}

void getSiblings(Node* node) {
    if (!node->parent) return;
    Node* temp = node->parent->firstChild;
    while (temp) {
        if (temp != node) cout << temp->data << " ";
        temp = temp->nextSibling;
    }
}

Node* getParent(Node* node) {
    return node->parent;
}

void getChildren(Node* node) {
    Node* temp = node->firstChild;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->nextSibling;
    }
}

bool isLeaf(Node* node) {
    return node->firstChild == nullptr;
}

bool isInternalNode(Node* node) {
    return node->firstChild != nullptr;
}

int getLevel(Node* node) {
    int level = 0;
    while (node->parent) {
        level++;
        node = node->parent;
    }
    return level;
}

int getTreeHeight(Node* node) {
    if (isLeaf(node)) return 0;
    int max_h = 0;
    Node* child = node->firstChild;
    while (child) {
        int h = getTreeHeight(child);
        if (h > max_h) max_h = h;
        child = child->nextSibling;
    }
    return max_h + 1;
}

int getDegree(Node* node) {
    int count = 0;
    Node* temp = node->firstChild;
    while (temp) {
        count++;
        temp = temp->nextSibling;
    }
    return count;
}

void getAncestors(Node* node) {
    Node* current = node->parent;
    while (current) {
        cout << current->data << " ";
        current = current->parent;
    }
}

void getDescendants(Node* node) {
    Node* child = node->firstChild;
    while (child) {
        cout << child->data << " ";
        getDescendants(child);
        child = child->nextSibling;
    }
}

int main() {
    Node* A = new Node('A');    
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');

    addChild(A, B); addChild(A, C);
    addChild(B, D); addChild(B, E);
    addChild(C, F); addChild(C, G); addChild(C, H);
    addChild(E, I); addChild(E, J);

    cout << "Root = " << getRoot(I)->data << endl;

    cout << "Sibling C = ";
    getSiblings(C);
    cout << endl;

    cout << "Parent F = " << getParent(F) << endl;

    cout << "Child B = ";
    getChildren(B);
    cout << endl;

    cout << "Leaf = ";
    Node* allNodes[] = {A, B, C, D, E, F, G, H, I, J};
    for (int i = 0; i < 10; i++)
        if (isLeaf(allNodes[i])) cout << allNodes[i]->data << " ";
    cout << endl;

    cout << "Internal Node = ";
    for (int i = 0; i < 10; i++)
        if (isInternalNode(allNodes[i])) cout << allNodes[i]->data << " ";
    cout << endl;

    cout << "Level E = " << getLevel(E) << endl;
    cout << "Tree height = " << getTreeHeight(A) << endl;
    cout << "Degree B = " << getDegree(B) << endl;

    cout << "Ancestor I = ";
    getAncestors(I);
    cout << endl;

    cout << "Descendant B = ";
    getDescendants(B);
    cout << endl;

    return 0;
}