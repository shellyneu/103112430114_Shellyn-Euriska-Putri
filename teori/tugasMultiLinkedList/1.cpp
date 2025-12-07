#include <iostream>
#include <string>
using namespace std;

struct elm_jual;
struct elm_sales;

typedef elm_jual* adr_jual;
typedef elm_sales* adr_sales;

struct sales{
    string nama, gol;
};

struct elm_jual{
    int info;
    adr_jual next;
};

struct elm_sales{
    sales info;
    adr_sales next;
    adr_jual nextJual;
};

struct mll{
    adr_sales First;
};

void Create_list(mll &List_Sales){
    List_Sales.First = NULL;
}

void new_elm_sales(sales info, adr_sales &S){
    S = new elm_sales;
    S->next = NULL;
    S->nextJual = NULL;
    S->info = info;
}

void new_elm_jual(int info, adr_jual &J){
    J = new elm_jual;
    J->info = info;
}

void insert_last_Sales(mll &List_Sales, adr_sales S){
    if(List_Sales.First == NULL){
        List_Sales.First = S;
    }else{
        adr_sales P = List_Sales.First;
        while(P->next != NULL){
            P = P->next;
        }
        P->next = S;
    }
}

adr_sales Search_Sales(mll List_Sales, string nama_Sales){
    adr_sales P = List_Sales.First;
    while(P != NULL){
        if(P->info.nama == nama_Sales){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void Insert_new_Penjualan(mll &List_Sales, adr_sales S, adr_jual J){
    if(S->nextJual == NULL){
        S->nextJual = J;
    }else{
        adr_jual P = S->nextJual;
        while(P->next != NULL){
            P = P->next;
        }
        P->next = J;
    }
}

void Delete_First_Penjualan(mll &List_Sales, adr_sales S, adr_jual &J){
    J = S->nextJual;
    S->nextJual = J->next;
    J->next = NULL;
}

void Delete_after_Penjualan(mll &List_Sales, adr_sales S, adr_jual prec, adr_jual &J){
    J = prec->next;
    prec->next = J->next;
    J->next = NULL;
}

void Delete_Last_Penjualan(mll &List_Sales, adr_sales S, adr_jual &J){
    adr_jual P = S->nextJual;
    adr_jual Prec = NULL;

    while(P->next != NULL){
        Prec = P;
        P = P->next;
    }

    if(Prec == NULL){
        S->nextJual = NULL;
    }else{
        Prec->next = NULL;
    }

    J = P;
}

void Show_data_sales(mll list_sales){
    adr_sales P = list_sales.First;

    while(P != NULL){
        cout << P->info.nama << endl;

        adr_jual Q = P->nextJual;

        while(Q =! NULL){  
            cout << Q->info << " ";
            Q = Q->next;
        }
        cout << endl << endl;

        P = P->next;
    }
}

void Delete_Penjualan(mll &list_sales){
    adr_sales P = list_sales.First;
    adr_jual Q, prec, J;

    while(P != NULL){
        Q = P->nextJual;
        prec = NULL;

        while(Q != NULL){
            if(Q->info < 3){
                if(Q == P->nextJual){
                    Delete_First_Penjualan(list_sales, P, J);
                    Q = P->nextJual;
                }else if(Q->next == NULL){
                    Delete_Last_Penjualan(list_sales, P, J);
                    Q = NULL;
                }else{
                    Delete_after_Penjualan(list_sales, P, prec, J);
                    Q = prec->next;
                }
            }else{
                prec = Q;
                Q = Q->next;
            }
        }
        P = P->next;
    }
}

int main(){
    mll showroom;
    Create_list(showroom);

    adr_sales s1, s2, s3, s4, s5;

    new_elm_sales({"Siska", "A"}, s1);
    new_elm_sales({"Affan", "C"}, s2);
    new_elm_sales({"Cahya", "A"}, s3);
    new_elm_sales({"Lia", "C"}, s4);
    new_elm_sales({"Hafidz", "B"}, s5);

    insert_last_Sales(showroom, s1);
    insert_last_Sales(showroom, s2);
    insert_last_Sales(showroom, s3);
    insert_last_Sales(showroom, s4);
    insert_last_Sales(showroom, s5);


    adr_jual j;

    new_elm_jual(5, j); Insert_new_Penjualan(showroom, s1, j);
    new_elm_jual(3, j); Insert_new_Penjualan(showroom, s1, j);
    new_elm_jual(4, j); Insert_new_Penjualan(showroom, s1, j);
    new_elm_jual(2, j); Insert_new_Penjualan(showroom, s1, j);

    new_elm_jual(4, j); Insert_new_Penjualan(showroom, s2, j);
    new_elm_jual(3, j); Insert_new_Penjualan(showroom, s2, j);

    new_elm_jual(5, j); Insert_new_Penjualan(showroom, s3, j);
    new_elm_jual(0, j); Insert_new_Penjualan(showroom, s3, j);
    new_elm_jual(2, j); Insert_new_Penjualan(showroom, s3, j);

    new_elm_jual(7, j); Insert_new_Penjualan(showroom, s5, j);

    Show_data_sales(showroom);

    return 0;
}