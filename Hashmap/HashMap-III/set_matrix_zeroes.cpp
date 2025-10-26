#include <bits/stdc++.h>
using namespace std;

// Brute force: mark rows and cols with zeros separately
void setZeroesBF(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> rows(m, false), cols(n, false);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (rows[i] || cols[j]) matrix[i][j] = 0;
        }
    }
}

// Optimized: use first row and column as markers, O(1) space
void setZeroesOpt(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;
    for (int j=0; j<n; j++)
        if (matrix[0][j] == 0) firstRow = true;
    for (int i=0; i<m; i++)
        if (matrix[i][0] == 0) firstCol = true;
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (firstRow) for (int j=0; j<n; j++) matrix[0][j] = 0;
    if (firstCol) for (int i=0; i<m; i++) matrix[i][0] = 0;
}

int main() {
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroesOpt(mat);
    for (auto &r: mat) {
        for (int x: r) cout << x << " ";
        cout << '\n';
    }
    return 0;
}
