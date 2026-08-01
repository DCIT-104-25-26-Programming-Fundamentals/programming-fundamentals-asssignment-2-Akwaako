#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rows, cols;

    cout << "=== PART A: Transpose ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int original[10][10];
    int transposed[10][10];

    readMatrix(original, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(original, rows, cols);

    transposeMatrix(original, rows, cols, transposed);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int a[10][10];
    int b[10][10];
    int sum[10][10];

    cout << "Matrix A:" << endl;
    readMatrix(a, rows, cols);

    cout << "Matrix B:" << endl;
    readMatrix(b, rows, cols);

    addMatrices(a, b, rows, cols, sum);

    cout << "\nSum Matrix:" << endl;
    printMatrix(sum, rows, cols);

    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns of Matrix A: ";
    cin >> colsA;
    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Columns of A must equal rows of B." << endl;
        return 0;
    }

    int matA[10][10];
    int matB[10][10];
    int product[10][10];

    cout << "Matrix A:" << endl;
    readMatrix(matA, rowsA, colsA);

    cout << "Matrix B:" << endl;
    readMatrix(matB, rowsB, colsB);

    multiplyMatrices(matA, matB, rowsA, colsA, colsB, product);

    cout << "\nProduct Matrix:" << endl;
    printMatrix(product, rowsA, colsB);

    return 0;
}