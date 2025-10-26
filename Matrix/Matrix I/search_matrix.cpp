#include <bits/stdc++.h>
using namespace std;

// Brute force: scan all cells
bool searchBF(vector<vector<int>>& mat, int target) {
    for (auto& row : mat)
        for (int x : row)
            if (x == target) return true;
    return false;
}

// Optimized: start from top-right corner for sorted matrix
bool searchOpt(vector<vector<int>>& mat, int target) {
    int r=0,c=mat[0].size()-1;
    while(r<mat.size() && c>=0) {
        if(mat[r][c]==target) return true;
        if(mat[r][c]>target) c--;
        else r++;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1,4,7,11},{2,5,8,12},{3,6,9,16}};
    cout << (searchBF(mat, 5) ? "BF found\n" : "BF not found\n");
    cout << (searchOpt(mat, 5) ? "Opt found\n" : "Opt not found\n");
    return 0;
}

/*
Logic: BF linear scan O(n*m).  
Opt exploits sorted property, O(n+m).
*/