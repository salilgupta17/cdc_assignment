#include <bits/stdc++.h>
using namespace std;

// Brute force: flatten matrix and sort
vector<int> sortedBF(vector<vector<int>>& mat) {
    vector<int> res;
    for (auto& row : mat) for (int x : row) res.push_back(x);
    sort(res.begin(), res.end());
    return res;
}

// Optimized: use min-heap for k-way merge of rows
vector<int> sortedOpt(vector<vector<int>>& mat) {
    int n = mat.size();
    auto cmp = [&](pair<int,int> a,pair<int,int> b){return mat[a.first][a.second]>mat[b.first][b.second];};
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    vector<int> idx(n,0), res;
    for (int i=0; i<n; i++) {
        if (!mat[i].empty()) pq.push({i,0});
    }
    while (!pq.empty()) {
        auto [r,c] = pq.top(); pq.pop();
        res.push_back(mat[r][c]);
        if (c+1 < (int)mat[r].size()) pq.push({r,c+1});
    }
    return res;
}

int main() {
    vector<vector<int>> mat = {{1,3,5},{2,4,6},{7,8,9}};
    auto a = sortedBF(mat);
    auto b = sortedOpt(mat);
    cout << "BF: "; for (int x : a) cout << x << " "; cout << "\n";
    cout << "Opt: "; for (int x : b) cout << x << " "; cout << "\n";
    return 0;
}

/*
Logic: BF flattens and sorts, O(n*m log n*m).  
Opt uses min-heap to merge sorted rows, O(n*m log n).
*/