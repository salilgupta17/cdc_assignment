#include <bits/stdc++.h>
using namespace std;

// Brute force: find first index where element >= target by linear search
int lowerBoundBF(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] >= target) return i;
    }
    return -1;
}

// Optimized: binary search for first position of >= target
int lowerBoundOpt(const vector<int>& arr, int target) {
    int l = 0, r = arr.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l < (int)arr.size() ? l : -1;
}

int main() {
    vector<int> a = {1,2,4,4,5,7};
    cout << "BF: " << lowerBoundBF(a, 4) << "\n";
    cout << "Opt: " << lowerBoundOpt(a, 4) << "\n";
    return 0;
}

/*
Logic: BF linear scan O(n).  
Opt uses binary search O(log n).
*/