#include "Matrix.h"

int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "File not found.\n";
        return 1;
    }

    int N;
    file >> N;

    Matrix A(N), B(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> A;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> B;

    // Display matrices
    A.display("Matrix A");
    B.display("Matrix B");

    // Addition
    Matrix sum = A + B;
    sum.display("A + B");

    // Multiplication
    Matrix product = A * B;
    product.display("A * B");

    // Diagonal sums
    A.displayDiagonalSums();

    // Swap rows
    Matrix swappedRows = Matrix::swapRows(A, 0, 1);
    swappedRows.display("After swapping rows 0 and 1");

    // Swap columns
    Matrix swappedCols = Matrix::swapCols(A, 0, 1);
    swappedCols.display("After swapping columns 0 and 1");

    // Update element
    A.updateElement(0, 0, 100);
    A.display("After updating element (0,0) = 100");

    return 0;
}
