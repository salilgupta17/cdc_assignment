#include <bits/stdc++.h>
using namespace std;

// Brute force: nested loops checking for repetition
int findRepBF(vector<int>& arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) return arr[i];
        }
    }
    return -1;
}

// Optimized: use hash set to detect repetition
int findRepOpt(vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) return x;
        seen.insert(x);
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 5, 3};
    cout << "BF repeat: " << findRepBF(arr) << "\n";
    cout << "Opt repeat: " << findRepOpt(arr) << "\n";
    return 0;
}

/*
Logic: BF checks all pairs, Opt tracks seen elements with a hash set.  
Time: BF O(n^2), Opt O(n). Space: Opt O(n).
*/