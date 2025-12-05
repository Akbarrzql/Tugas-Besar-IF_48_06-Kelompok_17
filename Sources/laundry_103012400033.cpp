#include "../Header/Laundry.h"

void deleteFirstLaundry(addressCustomer &C, addressLaundry &P){
    if (C != nullptr && C->firstLaundry != nullptr) {

        P = C->firstLaundry;

        if (C->firstLaundry->next == nullptr) {
            C->firstLaundry = nullptr;
        } else {
            C->firstLaundry = P->next;
            C->firstLaundry->prev = nullptr;
        }

        P->next = nullptr;
        P->prev = nullptr;

    } else {
        P = nullptr;
    }
}

void deleteLastLaundry(addressCustomer &C, addressLaundry &P){
    if (C != nullptr && C->firstLaundry != nullptr) {

        if (C->firstLaundry->next == nullptr) {
            deleteFirstLaundry(C, P);
        } else {
            addressLaundry temp = C->firstLaundry;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            P = temp;
            temp->prev->next = nullptr;
            P->prev = nullptr;
        }

    } else {
        P = nullptr;
    }
}
void deleteAfterLaundry(addressCustomer &C, addressLaundry Prec, addressLaundry &P){
    if (C != nullptr && Prec != nullptr && Prec->next != nullptr) {

        P = Prec->next;

        Prec->next = P->next;

        if (P->next != nullptr) {
            P->next->prev = Prec;
        }

        P->next = nullptr;
        P->prev = nullptr;

    } else {
        P = nullptr;
    }
}

