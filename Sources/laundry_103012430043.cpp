#include "../Header/header.h"
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

addressLaundry searchLaundry(addressCustomer C, string layanan){
    if (C == nullptr){
        cout << "Tidak ada nama customer" << endl;
        return nullptr;
    }

    addressLaundry P = C->firstLaundry;
    while (P != nullptr) {
        if (P->info.layanan == layanan) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

void printLaundry(addressCustomer C){
    addressLaundry P;
    int idx;
    P = C->firstLaundry;
    idx = 1;
    if (C == nullptr){
        cout << "Customer tidak ditemukan." << endl;
    }else if (P == nullptr){
        cout << "   Tidak ada laundry terdaftar untuk customer " << C->info.name << "." << endl;
    }else {
        cout << "   Laundry milik: " << C->info.name << endl;
        cout << "   ----------------------------------------" << endl;
        while (P != nullptr) {
            cout << "   Laundry #" << idx++ << endl;
            cout << "      Nama Pakaian : " << P->info.name << endl;
            cout << "      No. Tlp      : " << P->info.noTlp << endl;
            cout << "      Alamat       : " << P->info.alamat << endl;
            cout << "      Berat (kg)   : " << P->info.beratPakaian << endl;
            cout << "      Layanan      : " << P->info.layanan << endl;
            cout << "      Harga        : Rp" << P->info.harga << endl;
            cout << "      Jumlah Pakaian: " << P->info.jumlahPakaian << endl;
            cout << "   ----------------------------------------" << endl;

            P = P->next;
        }
    }
}

//study kasus
void insertLaundryByCustomer(listCustomer &LC) {
    string nama;
    cout << "Masukkan nama customer: ";
    cin >> nama;

    addressCustomer C = searchCustomer(LC, nama);
    if (C == nullptr) {
        cout << "Customer tidak ditemukan.\n";
    } else {
        Laundry L = inputLaundry();
        addressLaundry P = createElemenLaundry(L);
        insertLastLaundry(C, P);
        cout << "Laundry berhasil ditambahkan.\n";
    }
}

void deleteLaundryByService(listCustomer &LC) {
    string layanan;
    cout << "Masukkan layanan laundry: ";
    cin >> layanan;

    addressCustomer C = LC.first;
    bool found = false;

    while (C != nullptr) {
        addressLaundry L = searchLaundry(C, layanan);
        if (L != nullptr) {
            deleteAfterLaundry(C, L->prev, L);
            found = true;
        }
        C = C->next;
    }

    if (found)
        cout << "Laundry dengan layanan " << layanan << " berhasil dihapus.\n";
    else
        cout << "Laundry tidak ditemukan.\n";
}

void printAllUniqueLaundry(listCustomer LC) {
    addressCustomer C = LC.first;
    cout << "\n=== DAFTAR LAYANAN UNIK ===\n";

    while (C != nullptr) {
        addressLaundry L = C->firstLaundry;
        while (L != nullptr) {
            cout << "- " << L->info.layanan << endl;
            L = L->next;
        }
        C = C->next;
    }
}

void deleteAllLaundry(addressCustomer C) {
    addressLaundry P;
    addressLaundry temp;
    P = C->firstLaundry;
    if (C == nullptr) {
        cout << "Data customer untuk laundry tidak ditemukan." << endl;
    }else{
        while (P != nullptr) {
            temp = P;
            P = P->next;
            delete temp;
        }   
    
        C->firstLaundry = nullptr;
    }
}
