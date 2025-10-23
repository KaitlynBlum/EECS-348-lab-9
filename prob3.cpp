#include <bits/stdc++.h>
using namespace std;

// ---------- Function to load two matrices ----------
bool loadMatrices(const string &filename, int &N,
                  vector<vector<int>> &A, vector<vector<int>> &B) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    if (!(fin >> N)) return false;
    if (N <= 0) return false;

    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    // read first matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!(fin >> A[i][j])) return false;

    // read second matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!(fin >> B[i][j])) return false;

    return true;
}

// ---------- Helper: count digits for formatting ----------
int digitsCount(int x) {
    if (x == 0) return 1;
    if (x < 0) x = -x;
    int d = 0;
    while (x) { x /= 10; ++d; }
    return d;
}

// ---------- Function to print a matrix ----------
void printMatrix(const vector<vector<int>> &M) {
    int N = (int)M.size();
    int maxDigits = 1;

    // find max digits for alignment
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            maxDigits = max(maxDigits, digitsCount(M[i][j]));

    maxDigits = max(maxDigits, 2); // for at least 2 digits (like 01)

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(maxDigits) << setfill('0') << M[i][j];
            if (j + 1 < N) cout << " ";
            cout << setfill(' ');
        }
        cout << "\n";
    }
}

// ---------- Add two matrices ----------
vector<vector<int>> addMatrices(const vector<vector<int>> &A,
                                const vector<vector<int>> &B) {
    int N = (int)A.size();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// ---------- Multiply two matrices ----------
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A,
                                     const vector<vector<int>> &B) {
    int N = (int)A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// ---------- MAIN ----------
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string filename;
    if (argc >= 2) filename = argv[1];
    else {
        cout << "Enter input filename: ";
        getline(cin, filename);
    }

    int N;
    vector<vector<int>> A, B;
    if (!loadMatrices(filename, N, A, B)) {
        cerr << "Error: Could not load matrices from file.\n";
        return 1;
    }

    cout << "Matrix A (" << N << "x" << N << "):\n";
    printMatrix(A);
    cout << "\nMatrix B (" << N << "x" << N << "):\n";
    printMatrix(B);

    // Problem 2: Matrix addition
    cout << "\nA + B =\n";
    vector<vector<int>> sum = addMatrices(A, B);
    printMatrix(sum);

    // Problem 3: Matrix multiplication
    cout << "\nA × B =\n";
    vector<vector<int>> product = multiplyMatrices(A, B);
    printMatrix(product);

    return 0;
}
