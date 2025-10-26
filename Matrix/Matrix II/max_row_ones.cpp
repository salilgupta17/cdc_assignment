#include <bits/stdc++.h>
using namespace std;

// Brute force: count 1s in each row
int maxRowBF(vector<vector<int>>& mat) {
    int maxCount = -1, idx = -1;
    for (int i=0; i<(int)mat.size(); i++) {
        int c = count(mat[i].begin(), mat[i].end(), 1);
        if (c > maxCount) {
            maxCount = c;
            idx = i;
        }
    }
    return idx;
}

// Optimized: traverse from top-right, find row with max 1s in O(r+c)
int maxRowOpt(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();
    int max_row = -1, j = c - 1;
    for (int i = 0; i < r; i++) {
        while (j >= 0 && mat[i][j] == 1) j--;
        if (j < c - 1) max_row = i;
    }
    return max_row;
}

int main() {
    vector<vector<int>> mat = {{0,0,0,1},{0,1,1,1},{0,0,1,1}};
    cout << "BF row: " << maxRowBF(mat) << "\n";
    cout << "Opt row: " << maxRowOpt(mat) << "\n";
    return 0;
}

/*
Logic: BF counts 1s per row, O(r*c).  
Opt starts from top-right, moves left & down O(r+c).
*/