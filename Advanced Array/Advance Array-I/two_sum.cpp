#include <bits/stdc++.h>
using namespace std;

// Brute force: check all pairs for complement sum
bool twoSumBF(const vector<int>& arr, int target) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == target) return true;
        }
    }
    return false;
}

// Optimized: use hash set to find complement in O(n)
bool twoSumOpt(const vector<int>& arr, int target) {
    unordered_set<int> seen;
    for(int x : arr) {
        int c = target - x;
        if(seen.count(c)) return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    vector<int> a = {2,7,11,15};
    cout << (twoSumBF(a, 9) ? "BF: true" : "BF: false") << "\n";
    cout << (twoSumOpt(a, 9) ? "Opt: true" : "Opt: false") << "\n";
    return 0;
}

/*
Logic: BF checks all pairs, O(n^2).  
Opt checks complements in hash set, O(n).
Space: BF O(1), Opt O(n).
*/