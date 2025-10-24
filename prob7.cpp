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

// Function to update a specific element in the matrix
void updateElement(vector<vector<int>>& matrix, int row, int col, int newValue) {
    int n = matrix.size();

    if (row < 0 || col < 0 || row >= n || col >= n) {
        cout << "Invalid indices!\n";
        return;
    }

    matrix[row][col] = newValue;

    cout << "Matrix after updating element at (" << row << ", " << col << "):\n";
    printMatrix(matrix);
}
