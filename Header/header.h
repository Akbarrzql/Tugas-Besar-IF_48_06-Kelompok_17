#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>
#include <iostream>

using namespace std;

typedef struct elmList_Customer *addressCustomer;
typedef struct elmList_Laundry *addressLaundry;

struct Customer {
    string name;
    string noTlp;
    string alamat;
    //ada wallet tambahan yang nantinya bisa di top up dan digunnakan untuk membayar laundry
};

struct Laundry {
    string name;
    string noTlp;
    string alamat;
    int beratPakaian;
    string layanan;
    int harga;
    int jumlahPakaian;
    string tglMasuk;
    string tglSelesai;
    // opsi tambahin tanggal masuk sama selesai
};

struct elmList_Customer {
    Customer info;
    addressCustomer next;
    addressLaundry firstLaundry;   
};

struct elmList_Laundry {
    Laundry info;
    addressLaundry next;
    addressLaundry prev;
};

struct listCustomer {
    addressCustomer first;
};


void createListCustomer(listCustomer &L);
bool isEmptyCustomer(listCustomer L);
addressCustomer createElemenCustomer(Customer data);

void insertFirstCustomer(listCustomer &L, addressCustomer P);
void insertLastCustomer(listCustomer &L, addressCustomer P);
void insertAfterCustomer_103012430046(listCustomer &L, addressCustomer Prec, addressCustomer P);

void deleteFirstCustomer(listCustomer &L, addressCustomer &P);
void deleteLastCustomer(listCustomer &L, addressCustomer &P);
void deleteAfterCustomer(listCustomer &L, addressCustomer Prec, addressCustomer &P);
void deleteAllLaundry(addressCustomer C);

addressCustomer searchCustomer(listCustomer L, string nama);
void printCustomer(listCustomer L);

addressLaundry createElemenLaundry(Laundry x);
bool isEmptyLaundry(addressCustomer C);

void insertFirstLaundry(addressCustomer &C, addressLaundry P);
void insertLastLaundry(addressCustomer &C, addressLaundry P);
void insertAfterLaundry(addressCustomer &C, addressLaundry Prec, addressLaundry P);

void deleteFirstLaundry(addressCustomer &C, addressLaundry &P);
void deleteLastLaundry(addressCustomer &C, addressLaundry &P);
void deleteAfterLaundry(addressCustomer &C, addressLaundry Prec, addressLaundry &P);

addressLaundry searchLaundry(addressCustomer C, string layanan);
void printLaundry(addressCustomer C);

//study case
void insertCustomerByCondition(listCustomer &LC);
void deleteCustomerByName(listCustomer &LC);
void insertLaundryByCustomer(listCustomer &LC);
void deleteLaundryByService(listCustomer &LC);
int hitungTotalPendapatan(listCustomer L);
int totalLaundrySelesai(listCustomer LC, string tgl);
void printAllUniqueLaundry(listCustomer LC);
void tampilkanCustomerByLayanan(listCustomer L, string layanan);
void menampilkanLaundryLayanan(listCustomer C, string layanan);
addressLaundry laundryByLayanan(listCustomer L, string layanan);

//dua komputasi di child dan parent 

//function main and menu
void menuStudyCase(listCustomer &LC);
void menuUser(listCustomer &LC);
void menuAdmin(listCustomer &LC);
void mainMenu(listCustomer &LC);
void printAllCustomerWithLaundry(listCustomer LC);
Customer inputCustomer();
Laundry inputLaundry();


//bisa study case dengan tanggal yang di tambahin di child laundry
/*
- sorting berdasarkan tanggal selesai terdekat
- menampilkan berdasarkan hari
- menyelesaikan layanan laundry customer (UI Laundry)
- menampilkan laundry berdasarkan customer 
- menambahkan top up wallet customer 
- membuat pesanan laundry yang langsung yang dibayar
- menampilkan profil customer seperti nama, harga, noTlp
- edit profile customer
*/


#endif