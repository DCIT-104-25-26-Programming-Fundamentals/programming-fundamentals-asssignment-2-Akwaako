#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;

    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << setw(2) << i << " = " << (number * i) << endl;
    }
}

void printTablesUpTo(int n) {
    for (int num = 1; num <= n; num++) {
        printTable(num);

        if (num != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;

    cout << "1. Single table" << endl;
    cout << "2. Tables from 1 to N" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) {
        int number;
        cout << "Enter a number: ";
        cin >> number;

        if (number <= 0) {
            cout << "Error: Number must be positive." << endl;
            return 0;
        }

        printTable(number);
    } else if (choice == 2) {
        int n;
        cout << "Enter a number N: ";
        cin >> n;

        if (n <= 0) {
            cout << "Error: N must be a positive integer." << endl;
            return 0;
        }

        printTablesUpTo(n);
    } else {
        cout << "Error: Invalid option." << endl;
    }

    return 0;
}