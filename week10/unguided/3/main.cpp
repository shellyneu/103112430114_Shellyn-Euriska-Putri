#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);
    inOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalNilai(root,0)<<endl;

    cout << endl << "Pre-order: ";
    preOrder(root);
    cout << endl;
    
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
    
    return 0;
}