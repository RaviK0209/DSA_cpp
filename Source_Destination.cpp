#include <bits/stdc++.h>
using namespace std;

void traverse(int i, int j, string &result, int rows, int cols) {
    if (i == rows - 1 && j == cols - 1) {
        cout << result << endl;
        return;
    }

    if (j < cols - 1) {
        result.push_back('H');
        traverse(i, j + 1, result, rows, cols);
        result.pop_back();
    }

    if (i < rows - 1) {
        result.push_back('V');
        traverse(i + 1, j, result, rows, cols);
        result.pop_back();
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows" << endl;
    cin >> rows;
    cout << "Enter number of columns" << endl;
    cin >> cols;

    string result = "";
    traverse(0, 0, result, rows, cols);

    return 0;
}
