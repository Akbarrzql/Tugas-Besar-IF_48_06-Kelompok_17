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

//study kasus
void deleteCustomerByLaundry(listCustomer &LC) {
    string nama;
    cout << "Masukkan nama customer yang dihapus: ";
    cin >> nama;

    addressCustomer P = nullptr;

    if (LC.first != nullptr && LC.first->info.name == nama) {
        if (LC.first->firstLaundry != nullptr) {
            cout << "Customer masih memiliki laundry. Tidak dapat dihapus.\n";
            return;
        }

        deleteFirstCustomer(LC, P);
    }
    else {
        addressCustomer prec = LC.first;
        while (prec != nullptr &&
               prec->next != nullptr &&
               prec->next->info.name != nama) {
            prec = prec->next;
        }

        if (prec != nullptr && prec->next != nullptr) {
            if (prec->next->firstLaundry != nullptr) {
                cout << "Customer masih memiliki laundry. Tidak dapat dihapus.\n";
                return;
            }

            deleteAfterCustomer(LC, prec, P);
        }
    }

    if (P != nullptr) {
        cout << "Customer '" << nama << "' berhasil dihapus.\n";
    }
    else {
        cout << "Customer tidak ditemukan.\n";
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

void printCustomer(listCustomer L) {
    if (isEmptyCustomer(L)) {
        cout << "List customer kosong.\n";
    } else {
        addressCustomer P = L.first;
        int i = 1;
        while (P != nullptr) {
            cout << "\nCustomer #" << i++ << endl;
            cout << "Nama   : " << P->info.name << endl;
            cout << "No Tlp : " << P->info.noTlp << endl;
            cout << "Alamat : " << P->info.alamat << endl;
            P = P->next;
        }
    }
}