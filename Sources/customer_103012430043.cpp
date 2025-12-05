#include "../Header/Customer.h"
#include <iostream>
using namespace std;

void createListCustomer(listCustomer &L) {
    L.first = NULL;
}

bool isEmptyCustomer(listCustomer L) {
    return L.first == NULL;
}

addressCustomer createElemenCustomer(Customer data) {
    addressCustomer P;
    P = new elmList_Customer;
    P->info = data;
    P->next = NULL;
    P->firstLaundry = NULL;  

    return P;
}

void insertFirstCustomer(listCustomer &L, addressCustomer P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastCustomer(listCustomer &L, addressCustomer P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        addressCustomer Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterCustomer_103012430046(listCustomer &L, addressCustomer Prec, addressCustomer P) {

}