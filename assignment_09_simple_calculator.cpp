#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }

    result = a / b;
    return true;
}

bool computeModulus(int a, int b, int& result) {
    if (b == 0) {
        return false;
    }

    result = a % b;
    return true;
}

double exponent(double base, int power) {
    double result = 1.0;
    for (int i = 0; i < power; i++) {
        result *= base;
    }
    return result;
}

void printMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    int choice;
    cout << fixed << setprecision(2);

    do {
        printMenu();
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            double num1, num2;
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            if (choice == 1) {
                cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
            } else if (choice == 2) {
                cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
            } else if (choice == 3) {
                cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
            } else if (choice == 4) {
                double result;
                if (divide(num1, num2, result)) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
            } else if (choice == 5) {
                int intResult;
                if (computeModulus((int)num1, (int)num2, intResult)) {
                    cout << "Result: " << (int)num1 << " % " << (int)num2 << " = " << intResult << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
            } else if (choice == 6) {
                cout << "Result: " << num1 << " ^ " << (int)num2 << " = " << exponent(num1, (int)num2) << endl;
            }
        } else if (choice == 7) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Error: Invalid choice. Please enter 1-7." << endl;
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}