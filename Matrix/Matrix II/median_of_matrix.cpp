#include <bits/stdc++.h>
using namespace std;

// Brute force: flatten matrix, sort, find median
int medianBF(vector<vector<int>>& mat) {
    vector<int> vals;
    for (auto& row : mat)
        for (int x : row) vals.push_back(x);
    sort(vals.begin(), vals.end());
    return vals[vals.size()/2];
}

// Optimized: binary search on value range using count of smaller elements
int countLessEqual(const vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}
int medianOpt(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (auto& row : mat) {
        low = min(low, row[0]);
        high = max(high, row[c-1]);
    }
    int desired = (r * c + 1) / 2;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int place = 0;
        for (auto& row : mat) place += countLessEqual(row, mid);
        if (place < desired) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    vector<vector<int>> mat = {{1,3,5},{2,6,9},{3,6,9}};
    cout << "BF median: " << medianBF(mat) << "\n";
    cout << "Opt median: " << medianOpt(mat) << "\n";
    return 0;
}

/*
Logic: BF flattens and sorts.  
Opt binary searches value range, counts elements <= mid in rows.  
Time: BF O(r*c log(r*c)), Opt O(r log(max-min) * log c)
*/