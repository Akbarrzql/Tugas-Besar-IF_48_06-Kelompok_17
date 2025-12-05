#include "../Header/Laundry.h"
#include "../Header/Customer.h"
#include <iostream>
using namespace std;

addressLaundry createElemenLaundry(Laundry x) {
    addressLaundry P = new elmList_Laundry;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

bool isEmptyLaundry(addressCustomer C) {
    return C->firstLaundry == nullptr;
}

void insertFirstLaundry(addressCustomer &C, addressLaundry P) {
    if (isEmptyLaundry(C)) {
        C->firstLaundry = P;
    } else {
        P->next = C->firstLaundry;
        C->firstLaundry->prev = P;
        C->firstLaundry = P;
    }
}

void insertLastLaundry(addressCustomer &C, addressLaundry P) {
    if (isEmptyLaundry(C)) {
        C->firstLaundry = P;
    } else {
        addressLaundry Q = C->firstLaundry;

        while (Q->next != nullptr) {
            Q = Q->next;
        }

        Q->next = P;
        P->prev = Q;
    }
}

void insertAfterLaundry(addressCustomer &C, addressLaundry Prec, addressLaundry P) {
    if (Prec == nullptr || P == nullptr) {
        cout << "Laundry tidak ditemukan" << endl;
        return;
    }else {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != nullptr) {
            Prec->next->prev = P;
        }
        Prec->next = P;
    }
}
