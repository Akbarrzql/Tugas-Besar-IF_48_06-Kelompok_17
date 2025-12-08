#include "../Header/header.h"
#include <iostream>
using namespace std;

void createListCustomer(listCustomer &L) {
    L.first = nullptr;
}

bool isEmptyCustomer(listCustomer L) {
    return L.first == nullptr;
}

addressCustomer createElemenCustomer(Customer data) {
    addressCustomer P;
    P = new elmList_Customer;
    P->info = data;
    P->next = nullptr;
    P->firstLaundry = nullptr;  

    return P;
}

void insertFirstCustomer(listCustomer &L, addressCustomer P) {
    if (isEmptyCustomer(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastCustomer(listCustomer &L, addressCustomer P) {
    if (isEmptyCustomer(L)) {
        L.first = P;
    } else {
        addressCustomer Q;
        Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterCustomer_103012430046(listCustomer &L, addressCustomer Prec, addressCustomer P) {
    if (Prec == nullptr || L.first == nullptr){
        cout << "List Kosong" << endl;
    }else {
        P->next = Prec->next;
        Prec->next = P;
    }
}