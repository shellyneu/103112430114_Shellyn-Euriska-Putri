#include "queuePengiriman.h"
#include <iostream>
using namespace std;

void printMenu(){
    cout << "--- Komaniya Ekspress ---" << endl;
    cout << "1. Input Data Paket" << endl;
    cout << "2. Hapus Data Paket" << endl;
    cout << "3. Tampilkan queue paket" << endl;
    cout << "4. Hitung Total Biaya Pengiriman" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan anda: ";
}

int main() {
    queueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    do{
        printMenu();
        cin >> pilihan;
        if(pilihan == 1){
            enqueue(Q);
        } else if(pilihan == 2){
            dequeue(Q);
        } else if(pilihan == 3){
            viewQueue(Q);
        } else if(pilihan == 4){
            long total = TotalBiayaPengiriman(Q);
            cout << "Total Biaya Pengiriman: Rp " << total << endl;
        } else if(pilihan == 5){
            cout << "Keluar." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } while(pilihan != 5);

    return 0;
}