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
void
