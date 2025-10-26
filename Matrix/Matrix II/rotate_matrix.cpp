#include <bits/stdc++.h>
using namespace std;

// Brute force: create new matrix rotated clockwise
vector<vector<int>> rotateBF(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();
    vector<vector<int>> res(c, vector<int>(r));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            res[j][r-1-i] = mat[i][j];
        }
    }
    return res;
}

// Optimized: in-place transpose and reverse rows
void rotateOpt(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i=0; i<n; i++) reverse(mat[i].begin(), mat[i].end());
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    auto b = rotateBF(mat);
    cout << "BF: \n";
    for (auto &row : b) { for (int x : row) cout << x << " "; cout << "\n"; }

    rotateOpt(mat);
    cout << "Opt: \n";
    for (auto &row : mat) { for (int x : row) cout << x << " "; cout << "\n"; }
    return 0;
}

/*
Logic: BF allocates new matrix for rotated result.  
Opt transposes matrix then reverses rows in place.  
Time: O(n^2), Space: BF O(n^2), Opt O(1)
*/