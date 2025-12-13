#include <iostream>
#include "Header/header.h"
using namespace std;

void menuStudyCase(listCustomer &LC) {
    int pilih;
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

    switch (pilih) {
        case 0:
            menuUser();
            return;
        default:
            cout << "Pilihan salah!" << endl;
            menuStudyCase(LC);
    }
}

void menuUser() {
    cout << "\n===== MENU USER =====\n";
    cout << "1. Study Case\n";
    cout << "2. Kembali ke main menu\n";
    cout << "Pilih: ";
    
    int pilih;
    listCustomer LC;

    cin >> pilih;

    switch (pilih) {
        case 1:
            menuStudyCase(LC);
            return;
        case 2:
            return;
        default:
            cout << "Pilihan salah!" << endl;
            menuUser();
    }
}