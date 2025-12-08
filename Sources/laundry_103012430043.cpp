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
    addressLaundry P;
    P = C->firstLaundry;
    if (C == nullptr){
        cout << "Tidak ada nama customer" << endl;
    } else {
        while (P != nullptr) {
            if (P->info.layanan == layanan) {
                cout << P << endl;
            }
            P = P->next;
        }
    }
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
            cout << "      Jenis Pakaian: " << P->info.jenisPakaian << endl;
            cout << "   ----------------------------------------" << endl;

            P = P->next;
        }
    }
}
