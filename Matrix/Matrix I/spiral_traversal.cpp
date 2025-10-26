#include <bits/stdc++.h>
using namespace std;

// Brute force: simulate spiral with direction and visited cells
vector<int> spiralBF(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<int> res;
    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int r=0,c=0,di=0;
    for (int i=0; i<n*m; i++) {
        res.push_back(mat[r][c]);
        vis[r][c] = true;
        int nr = r + dirs[di][0], nc = c + dirs[di][1];
        if(nr<0 || nr>=n || nc<0 || nc>=m || vis[nr][nc]) di=(di+1)%4;
        r += dirs[di][0]; c += dirs[di][1];
    }
    return res;
}

// Optimized: keep boundaries and traverse inward
vector<int> spiralOpt(vector<vector<int>>& mat) {
    int r1=0,r2=mat.size()-1,c1=0,c2=mat[0].size()-1;
    vector<int> res;
    while(r1<=r2 && c1<=c2) {
        for(int c=c1;c<=c2;c++) res.push_back(mat[r1][c]);
        r1++;
        for(int r=r1;r<=r2;r++) res.push_back(mat[r][c2]);
        c2--;
        if(r1<=r2) for(int c=c2;c>=c1;c--) res.push_back(mat[r2][c]);
        r2--;
        if(c1<=c2) for(int r=r2;r>=r1;r--) res.push_back(mat[r][c1]);
        c1++;
    }
    return res;
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    auto r1 = spiralBF(mat);
    auto r2 = spiralOpt(mat);
    cout << "BF: "; for (int x : r1) cout << x << " "; cout << "\n";
    cout << "Opt: "; for (int x : r2) cout << x << " "; cout << "\n";
    return 0;
}

/*
Logic: BF simulates movement with visited tracking, O(n*m) time and space.  
Opt uses boundary shrinking to traverse directly, also O(n*m) but simpler space O(1).
*/