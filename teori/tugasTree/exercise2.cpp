#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char info;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        cout << current->info << " ";

        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

int main() {
    Node* root = createNode('/');

    root->left = createNode('*');
    root->right = createNode('H');

    root->left->left = createNode('-');
    root->left->right = createNode('G');

    root->left->left->left = createNode('-');
    root->left->left->right = createNode('F');

    root->left->left->left->left = createNode('-');
    root->left->left->left->right = createNode('E');

    root->left->left->left->left->left = createNode('+');
    root->left->left->left->left->right = createNode('N');

    root->left->left->left->left->left->left = createNode('+');
    root->left->left->left->left->left->right = createNode('M');

    root->left->left->left->left->left->left->left = createNode('K');
    root->left->left->left->left->left->left->right = createNode('L');

    cout << "\n1. Pre-order (Root-Left-Right):" << endl;
    preOrder(root);

    cout << "\n\n2. In-order (Left-Root-Right):" << endl;
    inOrder(root);

    cout << "\n\n3. Post-order (Left-Right-Root):" << endl;
    postOrder(root);

    cout << "\n\n4. Level-order (BFS):" << endl;
    levelOrder(root);

    cout << endl;
    return 0;
}