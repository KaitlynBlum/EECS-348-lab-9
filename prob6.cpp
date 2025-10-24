#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << "\t";
        cout << "\n";
    }
}

// Function to swap two columns of a matrix
void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {
    int n = matrix.size();

    if (n == 0 || col1 < 0 || col2 < 0 || col1 >= n || col2 >= n) {
        cout << "Invalid column indices!\n";
        return;
    }

    for (int i = 0; i < n; i++)
        swap(matrix[i][col1], matrix[i][col2]);

    cout << "Matrix after swapping columns " << col1 << " and " << col2 << ":\n";
    printMatrix(matrix);
}

