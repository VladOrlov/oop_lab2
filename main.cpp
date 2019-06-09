#include <iostream>
#include <cstring>

#include "certificate.hpp"
#include "menu.hpp"

using namespace std;
using namespace orlov;

int n;

certificate *pCertificate;

void SortArray() {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int max = i;
            for (int j = i + 1; j < n; j++) {
                if (pCertificate[j] > pCertificate[max])
                    max = j;
            }
            if (max != i) {
                pCertificate[max] + pCertificate[i];
            }
        }
    }
}

//void ShowTable() {
//    if (n == 0)
//        cout << "List is empty" << endl;
//    else {
//        SortArray();
//        printf("\n%c%.10s%c%.10s%c%.7s%c%.10s%c%.12s%c", 218, DrawLine(10), 194, DrawLine(10), 194, DrawLine(7), 194,
//               DrawLine(10), 194, DrawLine(12), 191);
//        printf("\n%c %8s %c %8s %c %5s %c %8s %c %10s %c", 179, "Surname", 179, "Name", 179, "Num", 179, "Salary", 179,
//               "Date", 179);
//        for (int i = 0; i < n; i++) {
//            arr[i].Show();
//        }
//        printf("\n%c%.10s%c%.10s%c%.7s%c%.10s%c%.12s%c", 192, DrawLine(10), 193, DrawLine(10), 193, DrawLine(7), 193,
//               DrawLine(10), 193, DrawLine(12), 217);
//    }
//}

void Add() {
    certificate *tmp = pCertificate;
    pCertificate = new certificate[++n];
    for (int i = 0; i < n - 1; i++) {
        pCertificate[i] = tmp[i];
    }
    certificate new_obj;
    new_obj.Input();
    pCertificate[n - 1] = new_obj;
}


void initialize_menu() {
    menu main_menu{
            {"Add new certificate ", [&] {
//                execute();
                cout << "done with goods\n";
                main_menu.show();
            }},
    };
    main_menu.show();
}

void add

int main() {

    try {
        initialize_menu();
    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;

//    while (true) {
//        cout << "Input: \n\t'a' to add Posvidchennya to list\n\t's' to show list\n\t'q' to exit\n";
//        char c;
//        cin >> c;
//        if (c == 'q')
//            break;
//        else if (c == 'a')
//            Add();
//        else if (c == 's')
//            ShowTable();
//        cout << endl;
//        //system("pause");
//        system("cls");
//    }
//    return 0;
}

