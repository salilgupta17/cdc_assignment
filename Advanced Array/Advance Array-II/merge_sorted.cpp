#include <bits/stdc++.h>
using namespace std;

// Brute force: merge then sort
vector<int> mergeSortedBF(const vector<int>& a, const vector<int>& b) {
    vector<int> res = a;
    res.insert(res.end(), b.begin(), b.end());
    sort(res.begin(), res.end());
    return res;
}

// Optimized: merge two sorted arrays in O(n+m)
vector<int> mergeSortedOpt(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while(i < (int)a.size() && j < (int)b.size()) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < (int)a.size()) res.push_back(a[i++]);
    while (j < (int)b.size()) res.push_back(b[j++]);
    return res;
}

int main() {
    vector<int> a = {1,3,5};
    vector<int> b = {2,4,6};
    auto res = mergeSortedOpt(a, b);
    for (int x: res) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF inserts and sorts combined array, O((n+m) log(n+m)).  
Opt merges in O(n+m) linear time.
*/