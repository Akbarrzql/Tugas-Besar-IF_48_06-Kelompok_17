#include <iostream>
#include "Header/header.h"
using namespace std;

#include <iostream>
#include "Header/header.h"
using namespace std;

/* ================= MENU STUDY CASE ================= */

void menuStudyCase(listCustomer &LC) {
    bool run = true;
    int pilih;

    while (run) {
        cout << "\n===== MENU STUDY CASE =====\n";
        cout << "1. Insert Customer berdasarkan kondisi\n";
        cout << "2. Hapus Customer berdasarkan nama\n";
        cout << "3. Insert Laundry ke Customer\n";
        cout << "4. Hapus Laundry berdasarkan layanan\n";
        cout << "5. Tampilkan semua Customer\n";
        cout << "6. Tampilkan semua Laundry (unik layanan)\n";
        cout << "7. Cari Customer berdasarkan nama\n";
        cout << "8. Hitung Total Pendapatan\n";
        cout << "9. Hitung Total Laundry Selesai\n";
        cout << "10. Tampilkan Customer berdasarkan layanan\n";
        cout << "11. Cari Laundry berdasarkan layanan\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            insertCustomerByCondition(LC);
        }

        else if (pilih == 2) {
            deleteCustomerByName(LC);
        }

        else if (pilih == 3) {
            insertLaundryByCustomer(LC);
        }

        else if (pilih == 4) {
            deleteLaundryByService(LC);
        }

        else if (pilih == 5) {
            printCustomer(LC);
        }

        else if (pilih == 6) {
            string layanan;
            cout << "Masukkan layanan: ";
            cin >> layanan;
            menampilkanLaundryLayanan(LC, layanan);
        }

        else if (pilih == 7) {
            string nama;
            cout << "Masukkan nama customer: ";
            cin >> nama;
            addressCustomer C = searchCustomer(LC, nama);
            if (C != nullptr)
                cout << "Customer ditemukan: " << C->info.name << endl;
            else
                cout << "Customer tidak ditemukan.\n";
        }

        else if (pilih == 8) {
            cout << "Total Pendapatan: Rp "
                 << hitungTotalPendapatan(LC) << endl;
        }

        else if (pilih == 9) {
            string tgl;
            cout << "Masukkan tanggal selesai: ";
            cin >> tgl;
            cout << "Total Laundry Selesai: "
                 << totalLaundrySelesai(LC, tgl) << endl;
        }

        else if (pilih == 10) {
            string layanan;
            cout << "Masukkan layanan: ";
            cin >> layanan;
            tampilkanCustomerByLayanan(LC, layanan);
        }

        else if (pilih == 11) {
            string layanan;
            cout << "Masukkan layanan laundry: ";
            cin >> layanan;

            addressLaundry L = laundryByLayanan(LC, layanan);
            if (L != nullptr) {
                cout << "\nLaundry ditemukan\n";
                cout << "Nama Laundry   : " << L->info.name << endl;
                cout << "Layanan        : " << L->info.layanan << endl;
                cout << "Berat Pakaian  : " << L->info.beratPakaian << endl;
                cout << "Harga          : " << L->info.harga << endl;
                cout << "Jumlah Pakaian : " << L->info.jumlahPakaian << endl;
                cout << "Tanggal Masuk  : " << L->info.tglMasuk << endl;
                cout << "Tanggal Selesai: " << L->info.tglSelesai << endl;
            } else {
                cout << "Laundry dengan layanan tersebut tidak ditemukan.\n";
            }
        }

        else if (pilih == 0) {
            run = false;
        }

        else {
            cout << "Pilihan tidak valid!\n";
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
            cout << "Pilihan tidak valid!\n";
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
