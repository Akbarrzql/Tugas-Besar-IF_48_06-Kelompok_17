#include "../Header/header.h"

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

void menampilkanLaundryLayanan(listCustomer L, string layanan) {

    addressCustomer C = L.first;
    while (C != nullptr) {
        addressLaundry L = C->firstLaundry;
        while (L != nullptr) {
            if (L->info.layanan == layanan) {
                cout << "Customer: " << C->info.name << endl;
                cout << "Laundry: " << L->info.name 
                     << " | Layanan: " << L->info.layanan
                     << " | Berat: " << L->info.beratPakaian << endl;
                cout << "--------------------------" << endl;
            }
            L = L->next;
        }
        C = C->next;
    }
}

addressLaundry laundryByLayanan(listCustomer L, string layanan) {
    addressCustomer C = L.first;
    while (C != nullptr) {
        addressLaundry L = C->firstLaundry;
        while (L != nullptr) {
            if (L->info.layanan == layanan) {
                return L;
            }
            L = L->next;
        }
        C = C->next;
    }
    return nullptr;
}

int totalLaundrySelesai(listCustomer L, string tgl) {
    int total = 0;

    addressCustomer C = L.first;
    while (C != nullptr) {
        addressLaundry L = C->firstLaundry;
        while (L != nullptr) {
            if (L->info.tglSelesai == tgl) {
                total++;
            }
            L = L->next;
        }
        C = C->next;
    }

    return total;
}
