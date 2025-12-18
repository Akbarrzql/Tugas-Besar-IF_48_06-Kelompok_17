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
    string namaCustomer;
    cout << "Masukkan nama customer: ";
    cin >> namaCustomer;

    addressCustomer C = searchCustomer(LC, namaCustomer);

    if (C == nullptr) {
        cout << "Customer tidak ditemukan.\n";
    }
    else {
        Laundry data = inputLaundry();
        addressLaundry P = createElemenLaundry(data);

        if (C->firstLaundry == nullptr) {
            insertFirstLaundry(C, P);
        }
        else {
            if (data.layanan == "Express") {
                insertFirstLaundry(C, P);
            }
            else {
                addressLaundry L = C->firstLaundry;
                addressLaundry prec = nullptr;

                while (L != nullptr) {
                    if (L->info.layanan == data.layanan) {
                        prec = L;
                    }
                    L = L->next;
                }

                if (prec != nullptr) {
                    insertAfterLaundry(C, prec, P);
                }
                else {
                    insertLastLaundry(C, P);
                }
            }
        }

        cout << "Laundry berhasil ditambahkan.\n";
    }
}


void deleteLaundryByService(listCustomer &LC) {
    string namaCustomer;
    cout << "Masukkan nama customer: ";
    cin >> namaCustomer;

    addressCustomer C = searchCustomer(LC, namaCustomer);

    if (C == nullptr || C->firstLaundry == nullptr) {
        cout << "Data tidak ditemukan.\n";
    }
    else {
        string layanan;
        cout << "Masukkan layanan laundry yang dihapus: ";
        cin >> layanan;

        addressLaundry P = nullptr;

        if (C->firstLaundry->info.layanan == layanan) {
            deleteFirstLaundry(C, P);
        }
        else {
            addressLaundry prec = C->firstLaundry;

            while (prec->next != nullptr &&
                   prec->next->info.layanan != layanan) {
                prec = prec->next;
            }

            if (prec->next != nullptr) {
                deleteAfterLaundry(C, prec, P);
            }
        }

        if (P != nullptr) {
            cout << "Laundry berhasil dihapus.\n";
        }
        else {
            cout << "Laundry dengan layanan tersebut tidak ditemukan.\n";
        }
    }
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
