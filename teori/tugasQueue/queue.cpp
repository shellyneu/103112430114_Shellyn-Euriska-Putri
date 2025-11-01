#include <iostream>
#include <string>
using namespace std;

struct InfoTugas {
    char Pekerjaan;     
    int waktu;          
    int Dikerjakan;     
    string Status;      
};

struct ElmTugas {
    InfoTugas info;
    ElmTugas* next;
};

struct AntrianTugas {
    ElmTugas* Head;
    ElmTugas* Tail;
};

void CreateQueue(AntrianTugas &Q) {
    Q.Head = nullptr;
    Q.Tail = nullptr;
}

bool IsEmpty(AntrianTugas Q) {
    return (Q.Head == nullptr);
}

ElmTugas* Alokasi(char id, int waktu) {
    ElmTugas* P = new ElmTugas;
    P->info.Pekerjaan = id;
    P->info.waktu = waktu;
    P->info.Dikerjakan = 0;
    P->info.Status = "unfinished";
    P->next = nullptr;
    return P;
}

void TambahTugas(AntrianTugas &Q, ElmTugas* P) {
    if (IsEmpty(Q)) {
        Q.Head = P;
        Q.Tail = P;
    } else {
        Q.Tail->next = P;
        Q.Tail = P;
    }
    Q.Tail->next = nullptr;
}

void HapusTugas(AntrianTugas &Q, ElmTugas* &P) {
    if (!IsEmpty(Q)) {
        P = Q.Head;
        Q.Head = Q.Head->next;
        if (Q.Head == nullptr)
            Q.Tail = nullptr;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void TampilQueue(AntrianTugas Q) {
    ElmTugas* P = Q.Head;
    cout << "Daftar Tugas Saat Ini:\n";
    while (P != nullptr) {
        cout << "  Tugas " << P->info.Pekerjaan
            << " | Waktu: " << P->info.waktu
            << " | Dikerjakan: " << P->info.Dikerjakan
            << " | Status: " << P->info.Status << endl;
        P = P->next;
    }
    cout << endl;
}

void DailyTask(AntrianTugas &Q) {
    int total = 0;
    int jumlahTugas = 0;
    
    ElmTugas* temp = Q.Head;
    while (temp != nullptr) {
        if (temp->info.Status == "unfinished") {
            jumlahTugas++;
        }
        temp = temp->next;
    }

    TampilQueue(Q);

    while (jumlahTugas > 0) {
        ElmTugas* P;
        HapusTugas(Q, P);

        cout << "\nMemproses Tugas " << P->info.Pekerjaan << "...\n";
        while (P->info.Dikerjakan < P->info.waktu) {
            P->info.Dikerjakan++;
            total++;
        }

        P->info.Status = "finished";
        cout << "Tugas " << P->info.Pekerjaan << " -> finished.\n";
        
        TambahTugas(Q, P);
        jumlahTugas--;

        if (jumlahTugas > 0) {
            cout << "\nSisa tugas:\n";
            TampilQueue(Q);
        }
    }

    cout << "\nSemua tugas selesai!\n";
    cout << "Total waktu pengerjaan = " << total << " jam.\n";
}

int main() {
    AntrianTugas Q;
    CreateQueue(Q);

    TambahTugas(Q, Alokasi('A', 9));
    TambahTugas(Q, Alokasi('B', 7));
    TambahTugas(Q, Alokasi('C', 5));
    TambahTugas(Q, Alokasi('D', 1));

    DailyTask(Q);

    return 0;
}
