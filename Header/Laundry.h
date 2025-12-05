#ifndef LAUNDRY_HPP
#define LAUNDRY_HPP
#include <string>
#include "../Header/Customer.h"
using namespace std;

typedef struct elmList_Laundry *addressLaundry;

struct Laundry {
    string name;
    int noTlp;
    string alamat;
    int beratPakaian;
    string layanan;
    int harga;
    string jenisPakaian;
};

struct elmList_Laundry {
    Laundry info;
    addressLaundry next;
    addressLaundry prev;
};

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
