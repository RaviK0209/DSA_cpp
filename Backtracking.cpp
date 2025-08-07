#include <iostream>
#include <vector>
using namespace std;

void printPath(vector<vector<int>>& matrix, int i, int j, vector<int>& path) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Add current cell to p
    path.push_back(matrix[i][j]);

    // Base case: if we reach the last cell, print the path
    if (i == rows - 1 && j == cols - 1) {
        for (int val : path)
            cout << val << " ";
        cout << endl;
    } else {
        // Move right
        if (j + 1 < cols)
            printPath(matrix, i, j + 1, path);
        // Move down
        if (i + 1 < rows)
            printPath(matrix, i + 1, j, path);
    }

    // Backtrack: remove current cell before going back
    path.pop_back();
}

int main() {
    int m = 2, n = 3;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<int> path;
    printPath(matrix, 0, 0, path);

    return 0;
}
