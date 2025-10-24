#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// ---------------- Helper: Print Matrix ----------------
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << setw(4) << val;
        cout << "\n";
    }
    cout << endl;
}

// ---------------- Problem 1: Read Matrices ----------------
bool readMatrices(const string& filename, vector<vector<int>>& A, vector<vector<int>>& B, int& N) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << endl;
        return false;
    }

    file >> N;
    if (N <= 0) {
        cerr << "Invalid matrix size!" << endl;
        return false;
    }

    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> B[i][j];

    file.close();

    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "Matrix B:\n";
    printMatrix(B);
    return true;
}

// ---------------- Problem 2: Add Matrices ----------------
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// ---------------- Problem 3: Multiply Matrices ----------------
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

// ---------------- Problem 4: Diagonal Sums ----------------
void diagonalSums(const vector<vector<int>>& M) {
    int N = M.size();
    int mainSum = 0, secSum = 0;

    for (int i = 0; i < N; i++) {
        mainSum += M[i][i];
        secSum += M[i][N - 1 - i];
    }

    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secSum << endl << endl;
}

// ---------------- Problem 5: Swap Rows ----------------
void swapRows(vector<vector<int>>& M, int r1, int r2) {
    int N = M.size();
    if (r1 < 0 || r2 < 0 || r1 >= N || r2 >= N) {
        cout << "Invalid row indices!\n";
        return;
    }
    swap(M[r1], M[r2]);
    printMatrix(M);
}

// ---------------- Problem 6: Swap Columns ----------------
void swapColumns(vector<vector<int>>& M, int c1, int c2) {
    int N = M.size();
    if (c1 < 0 || c2 < 0 || c1 >= N || c2 >= N) {
        cout << "Invalid column indices!\n";
        return;
    }
    for (int i = 0; i < N; i++)
        swap(M[i][c1], M[i][c2]);
    printMatrix(M);
}

// ---------------- Problem 7: Update Element ----------------
void updateElement(vector<vector<int>>& M, int r, int c, int newVal) {
    int N = M.size();
    if (r < 0 || c < 0 || r >= N || c >= N) {
        cout << "Invalid indices!\n";
        return;
    }
    M[r][c] = newVal;
    printMatrix(M);
}

// ---------------- Main ----------------
int main(int argc, char* argv[]) {
    string filename;

    if (argc > 1)
        filename = argv[1];
    else {
        cout << "Enter input filename: ";
        cin >> filename;
    }

    vector<vector<int>> A, B;
    int N;
    if (!readMatrices(filename, A, B, N))
        return 1;

    cout << "\n=== Matrix Addition ===\n";
    vector<vector<int>> add = addMatrices(A, B);
    printMatrix(add);

    cout << "=== Matrix Multiplication ===\n";
    vector<vector<int>> mult = multiplyMatrices(A, B);
    printMatrix(mult);

    cout << "=== Diagonal Sums of Matrix A ===\n";
    diagonalSums(A);

    cout << "=== Swap Rows in A ===\n";
    int r1 = 0, r2 = N - 1;
    cout << "Swapping row " << r1 << " and " << r2 << "...\n";
    swapRows(A, r1, r2);

    cout << "=== Swap Columns in B ===\n";
    int c1 = 0, c2 = N - 1;
    cout << "Swapping column " << c1 << " and " << c2 << "...\n";
    swapColumns(B, c1, c2);

    cout << "=== Update Element in A ===\n";
    int r = 1, c = 1, newVal = 999;
    cout << "Updating element (" << r << "," << c << ") to " << newVal << "...\n";
    updateElement(A, r, c, newVal);

    return 0;
}
