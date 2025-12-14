#include <iostream>
#include "Header/header.h"
using namespace std;

void menuStudyCase(listCustomer &LC) {
    bool studyRunning = true;
    int pilih;

    while (studyRunning) {
        cout << "\n===== MENU STUDY CASE =====\n";
        cout << "1. Insert Customer berdasarkan kondisi\n";
        cout << "2. Hapus Customer berdasarkan nama\n";
        cout << "3. Insert Laundry ke Customer\n";
        cout << "4. Hapus Laundry berdasarkan layanan\n";
        cout << "5. Tampilkan semua Customer\n";
        cout << "6. Tampilkan semua Laundry (unique layanan)\n";
        cout << "7. Cari Customer berdasarkan nama\n";
        cout << "8. Hitung Total Pendapatan\n";
        cout << "9. Hitung Total Laundry Selesai\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 0) {
            studyRunning = false;
        }
        else if (pilih == 5) {
            printCustomer(LC);
        }
        else if (pilih == 7) {
            string nama;
            cout << "Masukkan nama customer: ";
            cin >> nama;
            addressCustomer C = searchCustomer(LC, nama);
            if (C != nullptr) {
                cout << "Customer ditemukan: " << C->info.name << endl;
            } else {
                cout << "Customer tidak ditemukan.\n";
            }
        }
        else if (pilih == 8) {
            cout << "Total pendapatan: Rp "
                 << hitungTotalPendapatan(LC) << endl;
        }
        else {
            cout << "Fitur belum diimplementasikan.\n";
        }
    }
}

void menuUser(listCustomer &LC) {
    bool userRunning = true;
    int pilih;

    while (userRunning) {
        cout << "\n===== MENU USER =====\n";
        cout << "1. Study Case\n";
        cout << "2. Kembali ke Main Menu\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            menuStudyCase(LC);
        }
        else if (pilih == 2) {
            userRunning = false;
        }
        else {
            cout << "Pilihan salah!\n";
        }
    }
}
