#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>
#include <iostream>

using namespace std;

typedef struct elmList_Customer *addressCustomer;
typedef struct elmList_Laundry *addressLaundry;

struct Customer {
    string name;
    int noTlp;
    string alamat;
};

struct Laundry {
    string name;
    int noTlp;
    string alamat;
    int beratPakaian;
    string layanan;
    int harga;
    string jenisPakaian;
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


#endif
