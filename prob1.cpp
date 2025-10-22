// main.cpp
#include <bits/stdc++.h>
using namespace std;

bool loadMatrices(const string &filename, int &N,
                  vector<vector<int>> &A, vector<vector<int>> &B) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    if (!(fin >> N)) return false;
    if (N <= 0) return false;

    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    // read first matrix A
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(fin >> A[i][j])) return false;
        }
    }
    // read second matrix B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(fin >> B[i][j])) return false;
        }
    }

    return true;
}

int digitsCount(int x) {
    if (x == 0) return 1;
    if (x < 0) x = -x;
    int d = 0;
    while (x) { x /= 10; ++d; }
    return d;
}

void printMatrix(const vector<vector<int>> &M) {
    int N = (int)M.size();
    int maxDigits = 1;

    // find maximum digits among elements
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            maxDigits = max(maxDigits, digitsCount(M[i][j]));

    // enforce a minimum width of 2 (matches the sample input style like "01")
    maxDigits = max(maxDigits, 2);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // pad with leading zeros to width=maxDigits
            cout << setw(maxDigits) << setfill('0') << M[i][j];
            if (j + 1 < N) cout << " ";
            cout << setfill(' '); // reset fill for safety
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string filename;
    if (argc >= 2) filename = argv[1];
    else {
        cout << "Enter input filename: ";
        if (!getline(cin, filename)) return 1;
        if (filename.size() == 0) return 1;
    }

    int N;
    vector<vector<int>> A, B;
    if (!loadMatrices(filename, N, A, B)) {
        cerr << "Error: failed to read matrices from file '" << filename << "'.\n";
        cerr << "Ensure file exists and has format: N then two N x N matrices of integers.\n";
        return 1;
    }

    cout << "Matrix A (" << N << "x" << N << "):\n";
    printMatrix(A);
    cout << "\nMatrix B (" << N << "x" << N << "):\n";
    printMatrix(B);

    return 0;
}
