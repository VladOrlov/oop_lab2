#pragma once

#include <iostream>
#include <cstring>

using namespace std;

namespace orlov {
    char *DrawLine(int N) {
        char *line = new char[N];
        for (int i = 0; i < N; i++) {
            line[i] = char(196);
        }
        return line;
    }

    struct Date {
        int day;
        int month;
        int year;
    };

    class certificate {
        char *name = new char[15];
        char *surname = new char[15];
        int number;
        float salary;
        Date date;

    public:

        certificate() {
        }
        ~certificate() {
        }
        void Input() {
            cout << "Input name\n";
            cin >> name;
            cout << "Input surname\n";
            cin >> surname;
            cout << "Input number\n";
            cin >> number;
            cout << "Input salary\n";
            cin >> salary;
            cout << "Input date(day,month,year)\n";
            cin >> date.day >> date.month >> date.year;
        }

        void Show() {
            printf("\n%c%.10s%c%.10s%c%.7s%c%.10s%c%.12s%c", 195, DrawLine(10), 197, DrawLine(10), 197, DrawLine(7), 197,
                   DrawLine(10), 197, DrawLine(12), 180);
            printf("\n%c %8s %c %8s %c %.5d %c %8.2f %c %.2d.%.2d.%.4d %c", 179, surname, 179, name, 179, (int) *this, 179,
                   salary, 179, date.day, date.month, date.year, 179);
        }

        operator int() {
            return number;
        }

        friend bool operator>(certificate a, certificate b) {
            if (a.number > b.number)
                return true;
            else
                return false;
        }

        void operator=(certificate val) {
            name = val.name;
            surname = val.surname;
            number = val.number;
            salary = val.salary;
            date = val.date;
        }

        friend void operator+(certificate &a, certificate &b) {
            certificate tmp = a;
            a = b;
            b = tmp;
        }
    };

}