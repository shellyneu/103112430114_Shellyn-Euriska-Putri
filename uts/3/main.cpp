#include "stackMahasiswa.h"
#include <iostream>
using namespace std;

int main(){
    StackMahasiswa S;
    createStackMahasiswa(S);

    push(S);
    push(S);
    push(S);
    push(S);
    push(S);
    push(S);

    view(S);

    pop(S);

    view(S);

    update(S, 3);

    view(S);

    searchNilaiAkhir(S, 85.5, 95.5);

    maxNilaiAkhir(S);

    return 0;
}