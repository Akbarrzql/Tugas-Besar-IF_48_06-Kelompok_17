#include <iostream>
#include "Header/header.h"
using namespace std;

int main(){
    listCustomer LC;
    createListCustomer(LC);
    mainMenu(LC); 
    return 0;
}

void mainMenu(listCustomer &LC) {
    bool running = true;

    while (running) {
        cout << "\n----- Menu Aplikasi Laundry -----\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Pilih Menu : ";

        int x;
        cin >> x;

        if (x == 1) {
            menuAdmin(LC);
        }
        else if (x == 2) {
            menuUser(LC); 
        }
        else if (x == 3) {
            running = false;
        }
    }
}
