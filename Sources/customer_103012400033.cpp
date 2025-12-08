#include "../Header/header.h"

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

addressCustomer searchCustomer(listCustomer L, string nama){
    addressCustomer P = L.first;

    while (P != nullptr) {
        if (P->info.name == nama) {
            return P; 
        }
        P = P->next;
    }

    return nullptr; 
}
void printCustomer(listCustomer L){
    addressCustomer P = L.first;
    if (P == nullptr) {
        cout << "Data customer tidak ditemukan!" << endl;
    }

    cout << "\n===== DATA CUSTOMER =====" << endl;
    cout << "Nama         : " << P->info.name << endl;
    cout << "No. Telepon  : " << P->info.noTlp << endl;
    cout << "Alamat       : " << P->info.alamat << endl;
}