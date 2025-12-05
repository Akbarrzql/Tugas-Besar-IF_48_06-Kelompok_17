#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <string>
#include "../Header/Laundry.h" 
using namespace std;

typedef struct elmList_Customer *addressCustomer;

struct Customer {
    string name;
    int noTlp;
    string alamat;
};

struct elmList_Customer {
    Customer info;
    addressCustomer next;
    addressLaundry firstLaundry;   
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

addressCustomer searchCustomer(listCustomer L, string nama);
void printCustomer(listCustomer L);


#endif
