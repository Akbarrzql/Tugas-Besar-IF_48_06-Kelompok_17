#include <iostream>
#include "Header/header.h"
using namespace std;

listCustomer LC;

Customer inputCustomer() {
    Customer c;
    cout << "Nama Customer       : ";
    cin >> c.name;
    cout << "No Telepon          : ";
    cin >> c.noTlp;
    cout << "Alamat              : ";
    cin >> c.alamat;
    return c;
}

Laundry inputLaundry() {
    Laundry L;
    cout << "Nama Laundry        : ";
    cin >> L.name;
    cout << "No Telepon          : ";
    cin >> L.noTlp;
    cout << "Alamat              : ";
    cin >> L.alamat;
    cout << "Berat Pakaian       : ";
    cin >> L.beratPakaian;
    cout << "Jenis Layanan       : ";
    cin >> L.layanan;
    cout << "Harga               : ";
    cin >> L.harga;
    cout << "Jumlah Pakaian      : ";
    cin >> L.jumlahPakaian;
    cout << "Tanggal Masuk       : ";
    cin >> L.tglMasuk;
    cout << "Tanggal Selesai     : ";
    cin >> L.tglSelesai;
    return L;
}

void menuAdmin() {
    int pilih, pilih1, pilih2;
    string key;

    while (true) {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Menu Customer (Parent)\n";
        cout << "2. Menu Laundry (Child)\n";
        cout << "3. Kembali ke main menu\n";
        cout << "Pilih [1-3]: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "\n--- Menu Customer ---\n";
            cout << "1. Insert Customer\n";
            cout << "2. Delete Customer\n";
            cout << "3. Print Customer\n";
            cout << "4. Search Customer\n";
            cout << "5. Kembali\n";
            cout << "Pilih: ";
            cin >> pilih1;

            if (pilih1 == 1) {
                cout << "\n1. Insert First\n";
                cout << "2. Insert Last\n";
                cout << "3. Insert After\n";
                cout << "4. Kembali\n";
                cout << "Pilih: ";
                cin >> pilih2;

                if (pilih2 == 1) {
                    Customer data = inputCustomer();
                    addressCustomer P = createElemenCustomer(data);
                    insertFirstCustomer(LC, P);
                    cout << "Customer berhasil ditambahkan!\n";
                } else if (pilih2 == 2) {
                    Customer data = inputCustomer();
                    addressCustomer P = createElemenCustomer(data);
                    insertLastCustomer(LC, P);
                    cout << "Customer berhasil ditambahkan!\n";
                } else if (pilih2 == 3) {
                    cout << "Masukkan nama customer sebelumnya: ";
                    cin >> key;
                    addressCustomer Prec = searchCustomer(LC, key);

                    if (Prec == nullptr) {
                        cout << "Customer tidak ditemukan!\n";
                    } else {
                        Customer data = inputCustomer();
                        addressCustomer P = createElemenCustomer(data);
                        insertAfterCustomer_103012430046(LC, Prec, P);
                        cout << "Customer berhasil ditambahkan!\n";
                    }
                }
            }

            else if (pilih1 == 2) {
                cout << "\n1. Delete First\n";
                cout << "2. Delete Last\n";
                cout << "3. Delete After\n";
                cout << "4. Kembali\n";
                cout << "Pilih: ";
                cin >> pilih2;

                addressCustomer P = nullptr;

                if (pilih2 == 1) {
                    deleteFirstCustomer(LC, P);
                } else if (pilih2 == 2) {
                    deleteLastCustomer(LC, P);
                } else if (pilih2 == 3) {
                    cout << "Masukkan nama customer sebelumnya: ";
                    cin >> key;
                    addressCustomer Prec = searchCustomer(LC, key);

                    if (Prec != nullptr) {
                        deleteAfterCustomer(LC, Prec, P);
                    } else {
                        cout << "Customer tidak ditemukan!\n";
                    }
                }
            } else if (pilih1 == 3) {
                printCustomer(LC);
            } else if (pilih1 == 4) {
                cout << "Masukkan nama customer: ";
                cin >> key;
                addressCustomer C = searchCustomer(LC, key);

                if (C != nullptr) {
                    cout << "Customer ditemukan: " << C->info.name << endl;
                } else {
                    cout << "Customer tidak ditemukan.\n";
                }
            }
        } else if (pilih == 2) {
            cout << "\nMasukkan nama customer pemilik laundry: ";
            cin >> key;
            addressCustomer C = searchCustomer(LC, key);

            if (C == nullptr) {
                cout << "Customer tidak ditemukan!\n";
            }

            cout << "\n--- Menu Laundry ---\n";
            cout << "1. Insert Laundry\n";
            cout << "2. Delete Laundry\n";
            cout << "3. Print Laundry\n";
            cout << "4. Search Laundry\n";
            cout << "5. Kembali\n";
            cout << "Pilih: ";
            cin >> pilih1;

            if (pilih1 == 1) {
                cout << "1. Insert First\n";
                cout << "2. Insert Last\n";
                cout << "3. Insert After\n";
                cout << "Pilih: ";
                cin >> pilih2;

                Laundry Ldata = inputLaundry();
                addressLaundry P = createElemenLaundry(Ldata);

                if (pilih2 == 1) insertFirstLaundry(C, P);
                else if (pilih2 == 2) insertLastLaundry(C, P);
                else if (pilih2 == 3) {
                    cout << "Masukkan layanan sebelumnya: ";
                    cin >> key;
                    addressLaundry Prec = searchLaundry(C, key);
                    if (Prec != nullptr) insertAfterLaundry(C, Prec, P);
                    else cout << "Laundry tidak ditemukan!\n";
                }
            }

            else if (pilih1 == 2) {
                cout << "1. Delete First\n";
                cout << "2. Delete Last\n";
                cout << "3. Delete After\n";
                cout << "Pilih: ";
                cin >> pilih2;

                addressLaundry P;

                if (pilih2 == 1) deleteFirstLaundry(C, P);
                else if (pilih2 == 2) deleteLastLaundry(C, P);
                else if (pilih2 == 3) {
                    cout << "Masukkan layanan sebelumnya: ";
                    cin >> key;
                    addressLaundry Prec = searchLaundry(C, key);
                    if (Prec != nullptr) deleteAfterLaundry(C, Prec, P);
                }
            }

            else if (pilih1 == 3) {
                printLaundry(C);
            }

            else if (pilih1 == 4) {
                cout << "Masukkan layanan laundry: ";
                cin >> key;
                addressLaundry L = searchLaundry(C, key);
                if (L != nullptr) {
                    cout << "Laundry ditemukan: " << L->info.layanan << endl;
                } else {
                    cout << "Laundry tidak ditemukan!\n";
                }
                continue;
            }
        }else if (pilih == 3) {
            cout << "Kembali ke main...\n";
            return;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}