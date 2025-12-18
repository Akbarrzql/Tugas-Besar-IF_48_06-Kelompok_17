#include <iostream>
#include "Header/header.h"
using namespace std;

listCustomer LC;

Customer inputCustomer()
{
    Customer c;
    cout << "Nama Customer       : ";
    cin >> c.name;
    cout << "No Telepon          : ";
    cin >> c.noTlp;
    cout << "Alamat              : ";
    cin >> c.alamat;
    return c;
}

Laundry inputLaundry()
{
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

void menuAdmin(listCustomer &LC)
{
    int pilih, pilih1, pilih2;
    string key;

    bool adminRunning = true;

    while (adminRunning)
    {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Menu Customer (Parent)\n";
        cout << "2. Menu Laundry (Child)\n";
        cout << "3. Kembali ke Main Menu\n";
        cout << "Pilih [1-3]: ";
        cin >> pilih;

        if (pilih == 1)
        {
            bool customerMenu = true;

            while (customerMenu)
            {
                cout << "\n--- MENU CUSTOMER ---\n";
                cout << "1. Insert Customer\n";
                cout << "2. Delete Customer\n";
                cout << "3. Kembali\n";
                cout << "Pilih: ";
                cin >> pilih1;

                if (pilih1 == 1)
                {
                    cout << "\n1. Insert First\n";
                    cout << "2. Insert Last\n";
                    cout << "3. Insert After\n";
                    cout << "4. Kembali\n";
                    cout << "Pilih: ";
                    cin >> pilih2;

                    if (pilih2 == 1)
                    {
                        addressCustomer P = createElemenCustomer(inputCustomer());
                        insertFirstCustomer(LC, P);
                    }
                    else if (pilih2 == 2)
                    {
                        addressCustomer P = createElemenCustomer(inputCustomer());
                        insertLastCustomer(LC, P);
                    }
                    else if (pilih2 == 3)
                    {
                        cout << "Masukkan nama customer sebelumnya: ";
                        cin >> key;
                        addressCustomer Prec = searchCustomer(LC, key);

                        if (Prec != nullptr)
                        {
                            addressCustomer P = createElemenCustomer(inputCustomer());
                            insertAfterCustomer_103012430046(LC, Prec, P);
                        }
                        else
                        {
                            cout << "Customer tidak ditemukan!\n";
                        }
                    }
                }

                else if (pilih1 == 2)
                {
                    cout << "\n1. Delete First\n";
                    cout << "2. Delete Last\n";
                    cout << "3. Delete After\n";
                    cout << "4. Kembali\n";
                    cout << "Pilih: ";
                    cin >> pilih2;

                    addressCustomer P = nullptr;

                    if (pilih2 == 1)
                    {
                        deleteFirstCustomer(LC, P);
                        if (P != nullptr)
                        {
                            cout << "Customer dengan nama " << P->info.name << " telah dihapus.\n";
                        }
                    }
                    else if (pilih2 == 2)
                    {
                        deleteLastCustomer(LC, P);
                        if (P != nullptr)
                        {
                            cout << "Customer dengan nama " << P->info.name << " telah dihapus.\n";
                        }
                    }
                    else if (pilih2 == 3)
                    {
                        cout << "Masukkan nama customer sebelumnya: ";
                        cin >> key;
                        addressCustomer Prec = searchCustomer(LC, key);
                        if (Prec != nullptr)
                            deleteAfterCustomer(LC, Prec, P);
                        if (P != nullptr)
                        {
                            cout << "Customer dengan nama " << P->info.name << " telah dihapus.\n";
                        }
                    }
                }

                else if (pilih1 == 3)
                {
                    customerMenu = false;
                }
            }
        }

        else if (pilih == 2)
        {
            bool laundryMenu = true;

            cout << "\nMasukkan nama customer pemilik laundry: ";
            cin >> key;
            addressCustomer C = searchCustomer(LC, key);

            if (C == nullptr)
            {
                cout << "Customer tidak ditemukan!\n";
                laundryMenu = false;
            }

            while (laundryMenu)
            {
                cout << "\n--- MENU LAUNDRY ---\n";
                cout << "1. Insert Laundry\n";
                cout << "2. Delete Laundry\n";
                cout << "3. Kembali\n";
                cout << "Pilih: ";
                cin >> pilih1;

                if (pilih1 == 1)
                {
                    cout << "1. Insert First\n";
                    cout << "2. Insert Last\n";
                    cout << "3. Insert After\n";
                    cout << "Pilih: ";
                    cin >> pilih2;

                    addressLaundry P = createElemenLaundry(inputLaundry());

                    if (pilih2 == 1)
                        insertFirstLaundry(C, P);
                    else if (pilih2 == 2)
                        insertLastLaundry(C, P);
                    else if (pilih2 == 3)
                    {
                        cout << "Masukkan layanan sebelumnya: ";
                        cin >> key;
                        addressLaundry Prec = searchLaundry(C, key);
                        if (Prec != nullptr)
                            insertAfterLaundry(C, Prec, P);
                    }
                }

                else if (pilih1 == 2)
                {
                    cout << "1. Delete First\n";
                    cout << "2. Delete Last\n";
                    cout << "3. Delete After\n";
                    cout << "Pilih: ";
                    cin >> pilih2;

                    addressLaundry P = nullptr;

                    if (pilih2 == 1)
                    {
                        deleteFirstLaundry(C, P);
                        if (P != nullptr)
                        {
                            cout << "Laundry dengan nama " << P->info.name << " telah dihapus." << "dan layanan " << P->info.layanan << "Telah dihapus.\n";
                        }
                    }
                    else if (pilih2 == 2)
                    {
                        deleteLastLaundry(C, P);
                        if (P != nullptr)
                        {
                            cout << "Laundry dengan nama " << P->info.name << " telah dihapus." << "dan layanan " << P->info.layanan << "Telah dihapus.\n";
                        }
                    }
                    else if (pilih2 == 3)
                    {
                        cout << "Masukkan layanan sebelumnya: ";
                        cin >> key;

                        addressLaundry Prec = searchLaundry(C, key);

                        if (Prec == nullptr)
                        {
                            cout << "Laundry dengan layanan tersebut tidak ditemukan.\n";
                        }

                        else if (Prec->next == nullptr)
                        {
                            cout << "Tidak ada laundry setelah layanan '"
                                 << Prec->info.layanan << "'.\n";
                        }

                        else
                        {
                            deleteAfterLaundry(C, Prec, P);

                            if (P != nullptr)
                            {
                                cout << "Laundry dengan nama " << P->info.name
                                     << " dan layanan " << P->info.layanan
                                     << " telah dihapus.\n";
                            }
                        }
                    }
                }
                else if (pilih1 == 3)
                {
                    laundryMenu = false;
                }
            }
        }
        else if (pilih == 3)
        {
            adminRunning = false;
        }
        else
        {
            cout << "Pilihan tidak valid!\n";
        }
    }
}
