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

// Function to swap two rows of a matrix
void swapRows(vector<vector<int>>& matrix, int row1, int row2) {
    int n = matrix.size();

    if (row1 < 0 || row2 < 0 || row1 >= n || row2 >= n) {
        cout << "Invalid row indices!\n";
        return;
    }

    swap(matrix[row1], matrix[row2]);

    cout << "Matrix after swapping rows " << row1 << " and " << row2 << ":\n";
    printMatrix(matrix);
}
