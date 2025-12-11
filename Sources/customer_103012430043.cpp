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
    addressCustomer c;
    c = L.first;
    bool ditemukan = false;
    int nomorCustomer = 1;
    
    cout << "\n===== CUSTOMER DENGAN LAYANAN: " << layanan << " =====" << endl;
    cout << "========================================================" << endl;
    
    while (c != nullptr) {
        addressLaundry l;
        l = c->firstLaundry;
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
            cout << "Nama         : " << c->info.name << endl;
            cout << "No. Telepon  : " << c->info.noTlp << endl;
            cout << "Alamat       : " << c->info.alamat << endl;
            cout << "Jumlah pakaian dengan layanan " << layanan << ": " << jumlahLayanan << endl;
            
            cout << "\nDetail Pakaian dengan Layanan " << layanan << ":" << endl;
            cout << "----------------------------------------" << endl;
            
            l = c->firstLaundry;
            int idx = 1;
            while (l != nullptr) {
                if (l->info.layanan == layanan) {
                    cout << "   Pakaian #" << idx++ << endl;
                    cout << "      Nama Pakaian : " << l->info.name << endl;
                    cout << "      Berat (kg)   : " << l->info.beratPakaian << endl;
                    cout << "      Harga        : Rp" << l->info.harga << endl;
                    cout << "      Jenis Pakaian: " << l->info.jenisPakaian << endl;
                    cout << "   ........................................" << endl;
                }
                l = l->next;
            }
            cout << "========================================================" << endl;
        }
        
        c = c->next;
    }
    
    if (!ditemukan) {
        cout << "Tidak ada customer yang menggunakan layanan '" << layanan << "'." << endl;
        cout << "========================================================" << endl;
    }
}