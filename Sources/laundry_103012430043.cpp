#include "../Header/Laundry.h"
#include "../Header/Customer.h"
#include <iostream>
using namespace std;

addressLaundry createElemenLaundry(Laundry x) {
    addressLaundry P = new elmList_Laundry;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

bool isEmptyLaundry(addressCustomer C) {
    return C->firstLaundry == NULL;
}

void insertFirstLaundry(addressCustomer &C, addressLaundry P) {
    if (C->firstLaundry == NULL) {
        C->firstLaundry = P;
    } else {
        P->next = C->firstLaundry;
        C->firstLaundry->prev = P;
        C->firstLaundry = P;
    }
}

void insertLastLaundry(addressCustomer &C, addressLaundry P) {
    if (C->firstLaundry == NULL) {
        C->firstLaundry = P;
    } else {
        addressLaundry Q = C->firstLaundry;

        while (Q->next != NULL) {
            Q = Q->next;
        }

        Q->next = P;
        P->prev = Q;
    }
}

void insertAfterLaundry(addressCustomer &C, addressLaundry Prec, addressLaundry P) {

}
