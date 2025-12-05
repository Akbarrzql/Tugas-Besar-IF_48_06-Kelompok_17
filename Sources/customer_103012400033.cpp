#include "../Header/Customer.h"

void createListCustomer(listCustomer &L);
bool isEmptyCustomer(listCustomer L);
addressCustomer createElemenCustomer(Customer data);

void insertFirstCustomer(listCustomer &L, addressCustomer P);
void insertLastCustomer(listCustomer &L, addressCustomer P);
void insertAfterCustomer_103012430046(listCustomer &L, addressCustomer Prec, addressCustomer P);

void deleteFirstCustomer(listCustomer &L, addressCustomer &P){
    if (L.first != nullptr) {

        P = L.first;
        L.first = L.first->next;
        P->next = nullptr;

        deleteAllLaundry(P);

    } else {
        P = nullptr;
    }

}

void deleteLastCustomer(listCustomer &L, addressCustomer &P){
    if (L.first != nullptr) {

        if (L.first->next == nullptr) {
            deleteFirstCustomer(L, P);
        } else {
            addressCustomer temp = L.first;

            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            P = temp->next;
            temp->next = nullptr;

            deleteAllLaundry(P);
        }

    } else {
        P = nullptr;
    }
}
void deleteAfterCustomer(listCustomer &L, addressCustomer Prec, addressCustomer &P){
    if (Prec != nullptr && Prec->next != nullptr) {

        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;

        deleteAllLaundry(P);

    } else {
        P = nullptr;
    }
}

addressCustomer searchCustomer(listCustomer L, string nama);