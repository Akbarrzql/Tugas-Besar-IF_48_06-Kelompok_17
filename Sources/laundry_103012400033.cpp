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
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
    else {
        P = nullptr;
    }
}


void menampilkanLaundryLayanan(listCustomer L, string layanan) {
    addressCustomer C = L.first;
    bool ditemukan = false;

    cout << "\n===== DAFTAR LAUNDRY DENGAN LAYANAN: "
         << layanan << " =====\n";
    cout << "============================================\n";

    while (C != nullptr) {
        addressLaundry Ld = C->firstLaundry;

        while (Ld != nullptr) {
            if (Ld->info.layanan == layanan) {
                ditemukan = true;

                cout << "Customer       : " << C->info.name << endl;
                cout << "Layanan        : " << Ld->info.layanan << endl;
                cout << "Berat (kg)     : " << Ld->info.beratPakaian << endl;
                cout << "Jumlah Pakaian : " << Ld->info.jumlahPakaian << endl;
                cout << "Harga          : Rp" << Ld->info.harga << endl;
                cout << "Status Bayar   : " << Ld->info.statusBayar << endl;
                cout << "Tgl Masuk      : " << Ld->info.tglMasuk << endl;
                cout << "Tgl Selesai    : " << Ld->info.tglSelesai << endl;
                cout << "--------------------------------------------\n";
            }
            Ld = Ld->next;
        }
        C = C->next;
    }

    if (!ditemukan) {
        cout << "Tidak ada laundry dengan layanan tersebut.\n";
        cout << "============================================\n";
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
