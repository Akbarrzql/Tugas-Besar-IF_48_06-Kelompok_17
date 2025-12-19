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

void printLaundry(addressCustomer C) {
    if (C == nullptr) {
        cout << "Customer tidak ditemukan.\n";
    }
    else if (C->firstLaundry == nullptr) {
        cout << "   Tidak ada laundry untuk customer "
             << C->info.name << ".\n";
    }
    else {
        addressLaundry P = C->firstLaundry;
        int idx = 1;

        cout << "   Laundry milik: " << C->info.name << endl;
        cout << "   ----------------------------------------\n";

        while (P != nullptr) {
            cout << "   Laundry #" << idx++ << endl;
            cout << "      Layanan       : " << P->info.layanan << endl;
            cout << "      Berat (kg)    : " << P->info.beratPakaian << endl;
            cout << "      Jumlah        : " << P->info.jumlahPakaian << endl;
            cout << "      Harga         : Rp" << P->info.harga << endl;
            cout << "      Status Bayar  : " << P->info.statusBayar << endl;
            cout << "      Tgl Masuk     : " << P->info.tglMasuk << endl;
            cout << "      Tgl Selesai   : " << P->info.tglSelesai << endl;
            cout << "   ----------------------------------------\n";
            P = P->next;
        }
    }
}

//study kasus
void buatPesananLaundryLangsungBayar(listCustomer &LC) {
    string namaCustomer;
    cout << "Masukkan nama customer: ";
    cin >> namaCustomer;

    addressCustomer C = searchCustomer(LC, namaCustomer);

    if (C == nullptr) {
        cout << "Customer tidak ditemukan.\n";
    }
    else {
        Laundry data;

        cout << "Jenis Layanan       : ";
        cin >> data.layanan;
        cout << "Berat Pakaian (kg)  : ";
        cin >> data.beratPakaian;
        cout << "Jumlah Pakaian     : ";
        cin >> data.jumlahPakaian;
        cout << "Harga              : ";
        cin >> data.harga;
        cout << "Tanggal Masuk      : ";
        cin >> data.tglMasuk;
        cout << "Tanggal Selesai    : ";
        cin >> data.tglSelesai;

        data.statusBayar = "Lunas";

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

        cout << "Pesanan laundry berhasil dibuat dan langsung dibayar.\n";
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
        string layanan, tgl;
        cout << "Masukkan layanan laundry  : ";
        cin >> layanan;
        cout << "Masukkan tanggal selesai  : ";
        cin >> tgl;

        addressLaundry P = nullptr;

        if (C->firstLaundry->info.layanan == layanan &&
            C->firstLaundry->info.statusBayar == "Lunas" &&
            C->firstLaundry->info.tglSelesai == tgl) {

            deleteFirstLaundry(C, P);
        }
        else {
            addressLaundry prec = C->firstLaundry;

            while (prec->next != nullptr &&
                   !(prec->next->info.layanan == layanan &&
                     prec->next->info.statusBayar == "Lunas" &&
                     prec->next->info.tglSelesai == tgl)) {

                prec = prec->next;
            }

            if (prec->next != nullptr) {
                deleteAfterLaundry(C, prec, P);
            }
        }

        if (P != nullptr) {
            cout << "Laundry berhasil dihapus.\n";
            cout << "Layanan       : " << P->info.layanan << endl;
            cout << "Tanggal Selesai: " << P->info.tglSelesai << endl;
            cout << "Status Bayar  : " << P->info.statusBayar << endl;
        }
        else {
            cout << "Laundry tidak ditemukan / belum lunas / tanggal tidak sesuai.\n";
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
