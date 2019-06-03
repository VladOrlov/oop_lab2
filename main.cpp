#include <iostream>
#include <cstring>

using namespace std;

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

class Posvidchennya {
    char *name = new char[15];
    char *surname = new char[15];
    int number;
    float salary;
    Date date;

public:

    Posvidchennya() {
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

    friend bool operator>(Posvidchennya a, Posvidchennya b) {
        if (a.number > b.number)
            return true;
        else
            return false;
    }

    void operator=(Posvidchennya val) {
        name = val.name;
        surname = val.surname;
        number = val.number;
        salary = val.salary;
        date = val.date;
    }

    friend void operator+(Posvidchennya &a, Posvidchennya &b) {
        Posvidchennya tmp = a;
        a = b;
        b = tmp;
    }
};

int n;

Posvidchennya *arr;

void SortArray() {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int max = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[max])
                    max = j;
            }
            if (max != i)
                arr[max] + arr[i];
        }
    }
}

void ShowTable() {
    if (n == 0)
        cout << "List is empty" << endl;
    else {
        SortArray();
        printf("\n%c%.10s%c%.10s%c%.7s%c%.10s%c%.12s%c", 218, DrawLine(10), 194, DrawLine(10), 194, DrawLine(7), 194,
               DrawLine(10), 194, DrawLine(12), 191);
        printf("\n%c %8s %c %8s %c %5s %c %8s %c %10s %c", 179, "Surname", 179, "Name", 179, "Num", 179, "Salary", 179,
               "Date", 179);
        for (int i = 0; i < n; i++) {
            arr[i].Show();
        }
        printf("\n%c%.10s%c%.10s%c%.7s%c%.10s%c%.12s%c", 192, DrawLine(10), 193, DrawLine(10), 193, DrawLine(7), 193,
               DrawLine(10), 193, DrawLine(12), 217);
    }
}

void Add() {
    Posvidchennya *tmp = arr;
    arr = new Posvidchennya[++n];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = tmp[i];
    }
    Posvidchennya new_obj;
    new_obj.Input();
    arr[n - 1] = new_obj;
}


int main() {
    while (true) {
        cout << "Input: \n\t'a' to add Posvidchennya to list\n\t's' to show list\n\t'q' to exit\n";
        char c;
        cin >> c;
        if (c == 'q')
            break;
        else if (c == 'a')
            Add();
        else if (c == 's')
            ShowTable();
        cout << endl;
        //system("pause");
        system("cls");
    }
    return 0;
}