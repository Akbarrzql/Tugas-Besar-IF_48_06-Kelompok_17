#include <iostream>
#include "Header/header.h"
using namespace std;

void menuStudyCase(listCustomer &LC) {
    bool run = true;
    int pilih;

    while (run) {
        cout << "\n===== MENU STUDY CASE =====\n";
        cout << "1. Insert Customer berdasarkan jika nama customer belum ada\n"; //studi kasus insert berdasarkan kondisi
        cout << "2. Hapus Customer berdasarkan tidak ada laundry\n"; // studi kasus delete berdasarkan kondisi
        cout << "3. Insert Laundry berdasarkan status pembayaran langsung lunas\n"; //studi kasus insert laundry ke customer tertentu
        cout << "4. Hapus Laundry berdasarkan layanan yang selesai dan lunas\n"; //studi kasus delete laundry berdasarkan layanan
        cout << "5. Hitung Total Pendapatan (Komputasi)\n"; //menghitung total pendapatan dari semua laundry
        cout << "6. Hitung Total Laundry Selesai (Komputasi)\n"; //menghitung total laundry yang selesai pada tanggal tertentu
        cout << "7. Cari Customer berdasarkan nama\n"; // studi kasus mencari customer berdasarkan kondisi
        cout << "8. Tampilkan semua Customer\n"; //studi kasus menampilkan semua customer 
        cout << "9. Tampilkan semua Laundry Berdasarkan Nama\n"; //studi kasus menampilkan semua laundry dengan layanan 
        cout << "10. Menampilan semua Customer dengan Layanan Laundry yang dimiliki\n"; 
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            insertCustomerByCondition(LC);
        }

        else if (pilih == 2) {
            deleteCustomerByLaundry(LC);
        }

        else if (pilih == 3) {
            buatPesananLaundryLangsungBayar(LC);
        }

        else if (pilih == 4) {
            deleteLaundryByService(LC);
        }

        else if (pilih == 5) {
            int total = hitungTotalPendapatan(LC);
            cout << "===== TOTAL PENDAPATAN =====\n";
            cout << "Total Pendapatan: Rp " << total << endl;
        }

        else if (pilih == 6) {
            string tgl;
            cout << "Masukkan tanggal selesai: ";
            cin >> tgl;
            int total = totalLaundrySelesai(LC, tgl);
            cout << "===== TOTAL LAUNDRY SELESAI =====\n";
            cout<<"Total Laundry yang selesai pada tanggal " << tgl << ": ";
            cout << "Laundry Selesai: " << total << endl;
        }

        else if (pilih == 7) {
            string nama;
            cout << "Masukkan nama customer: ";
            cin >> nama;

            addressCustomer C = searchCustomer(LC, nama);
            if (C != nullptr) {
                cout << "Customer ditemukan\n";
                cout << "Nama   : " << C->info.name << endl;
                cout << "No Tlp : " << C->info.noTlp << endl;
                cout << "Alamat : " << C->info.alamat << endl;
            } else {
                cout << "Customer tidak ditemukan.\n";
            }
        }

        else if (pilih == 8) {
            printCustomer(LC);
        }

        else if (pilih == 9) {
            string key;
            cout << "\nMasukkan nama customer pemilik laundry: ";
            cin >> key;
            addressCustomer C = searchCustomer(LC, key);
            printLaundry(C);
        }

        else if (pilih == 10) {
            printAllCustomerWithLaundry(LC);
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

