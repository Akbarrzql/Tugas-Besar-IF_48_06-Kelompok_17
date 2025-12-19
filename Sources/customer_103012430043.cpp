#include "../Header/header.h"
#include <iostream>
using namespace std;

void createListCustomer(listCustomer &L) {
    L.first = nullptr;
}

bool isEmptyCustomer(listCustomer L) {
    return L.first == nullptr;
}

addressCustomer createElemenCustomer(Customer data) {
    addressCustomer P;
    P = new elmList_Customer;
    P->info = data;
    P->next = nullptr;
    P->firstLaundry = nullptr;  

    return P;
}

void insertFirstCustomer(listCustomer &L, addressCustomer P) {
    if (isEmptyCustomer(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastCustomer(listCustomer &L, addressCustomer P) {
    if (isEmptyCustomer(L)) {
        L.first = P;
    } else {
        addressCustomer Q;
        Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterCustomer_103012430046(listCustomer &L, addressCustomer Prec, addressCustomer P) {
    if (Prec == nullptr || L.first == nullptr){
        cout << "List Kosong" << endl;
    }else {
        P->next = Prec->next;
        Prec->next = P;
    }
}

//study kasus
void insertCustomerByCondition(listCustomer &LC) {
    Customer c = inputCustomer();

    addressCustomer cek = searchCustomer(LC, c.name);
    if (cek != nullptr) {
        cout << "Customer dengan nama '" << c.name
             << "' sudah terdaftar. Insert dibatalkan.\n";
        return;
    }

    addressCustomer P = createElemenCustomer(c);

    if (isEmptyCustomer(LC)) {
        insertFirstCustomer(LC, P);
    }
    else {
        insertLastCustomer(LC, P);
    }

    cout << "Customer berhasil ditambahkan (data unik).\n";
}


int hitungTotalPendapatan(listCustomer L) {
    int totalPendapatan = 0;
    addressCustomer c;
    c = L.first;
    
    while (c != nullptr) {
        addressLaundry l;
        l = c->firstLaundry;
        
        while (l != nullptr) {
            totalPendapatan += l->info.harga;
            l = l->next;
        }
        
        c = c->next;
    }
    
    return totalPendapatan;
}

void tampilkanCustomerByLayanan(listCustomer L, string layanan) {
    addressCustomer c = L.first;
    bool ditemukan = false;
    int nomorCustomer = 1;

    cout << "\n===== CUSTOMER DENGAN LAYANAN: " << layanan << " =====\n";
    cout << "=====================================================\n";

    while (c != nullptr) {
        addressLaundry l = c->firstLaundry;
        bool customerPunyaLayanan = false;
        int jumlahLayanan = 0;

        while (l != nullptr) {
            if (l->info.layanan == layanan) {
                customerPunyaLayanan = true;
                jumlahLayanan++;
            }
            l = l->next;
        }

        if (customerPunyaLayanan) {
            ditemukan = true;
            cout << "\nCustomer #" << nomorCustomer++ << endl;
            cout << "Nama        : " << c->info.name << endl;
            cout << "No. Telepon : " << c->info.noTlp << endl;
            cout << "Alamat      : " << c->info.alamat << endl;
            cout << "Jumlah laundry layanan '" << layanan
                 << "' : " << jumlahLayanan << endl;

            cout << "\nDetail Laundry:\n";
            cout << "----------------------------------------\n";

            l = c->firstLaundry;
            int idx = 1;
            while (l != nullptr) {
                if (l->info.layanan == layanan) {
                    cout << "   Laundry #" << idx++ << endl;
                    cout << "      Berat (kg)   : " << l->info.beratPakaian << endl;
                    cout << "      Jumlah       : " << l->info.jumlahPakaian << endl;
                    cout << "      Harga        : Rp" << l->info.harga << endl;
                    cout << "      Status Bayar : " << l->info.statusBayar << endl;
                    cout << "      Tgl Masuk    : " << l->info.tglMasuk << endl;
                    cout << "      Tgl Selesai  : " << l->info.tglSelesai << endl;
                    cout << "   ........................................\n";
                }
                l = l->next;
            }
            cout << "=====================================================\n";
        }

        c = c->next;
    }

    if (!ditemukan) {
        cout << "Tidak ada customer yang menggunakan layanan '"
             << layanan << "'.\n";
        cout << "=====================================================\n";
    }
}

void printAllCustomerWithLaundry(listCustomer LC) {
    if (LC.first == nullptr) {
        cout << "Data customer masih kosong.\n";
    }
    else {
        addressCustomer C = LC.first;
        int i = 1;

        cout << "\n===== DAFTAR CUSTOMER & LAUNDRY =====\n";

        while (C != nullptr) {
            cout << "\nCustomer #" << i++ << endl;
            cout << "Nama   : " << C->info.name << endl;
            cout << "No Tlp : " << C->info.noTlp << endl;
            cout << "Alamat : " << C->info.alamat << endl;

            addressLaundry L = C->firstLaundry;

            if (L == nullptr) {
                cout << "  >> Belum memiliki laundry\n";
            }
            else {
                int j = 1;
                cout << "  Daftar Laundry:\n";

                while (L != nullptr) {
                    cout << "  Laundry #" << j++ << endl;
                    cout << "    Layanan      : " << L->info.layanan << endl;
                    cout << "    Berat (kg)   : " << L->info.beratPakaian << endl;
                    cout << "    Jumlah       : " << L->info.jumlahPakaian << endl;
                    cout << "    Harga        : Rp" << L->info.harga << endl;
                    cout << "    Status Bayar : " << L->info.statusBayar << endl;
                    cout << "    Tgl Masuk    : " << L->info.tglMasuk << endl;
                    cout << "    Tgl Selesai  : " << L->info.tglSelesai << endl;
                    cout << "    -----------------------------\n";
                    L = L->next;
                }
            }

            cout << "--------------------------------------\n";
            C = C->next;
        }
    }
}

