#include <iostream>
using namespace std;

void printFibonacci(int n) {
    int first = 0;
    int second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++) {
        cout << first << " ";

        int next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

bool isFibonacci(int number) {
    if (number < 0) {
        return false;
    }

    int first = 0;
    int second = 1;

    if (number == first) {
        return true;
    }

    while (first <= number) {
        if (first == number) {
            return true;
        }

        int next = first + second;
        first = second;
        second = next;
    }

    return false;
}

int main() {
    int n;

    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    printFibonacci(n);

    int number;
    cout << "\nEnter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}