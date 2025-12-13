#include <iostream>
#include "Header/header.h"
using namespace std;

int main(){
    mainMenu();
}

void mainMenu(){
    cout << "----- Menu Aplikasi Laundry -----" << endl;
    cout << "1. Admin -----------------------" << endl;
    cout << "2. User ------------------------" << endl;
    cout << "3. Exit ------------------------" << endl;
    cout << "---------------------------------" << endl;
    cout << "Pilih Menu : ";
    int x;
    cin >> x;
    if (x == 1){
        menuAdmin();
    }else if (x == 2){
        menuUser();
    }else if (x == 3){

    }
}