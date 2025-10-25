#include <bits/stdc++.h>
using namespace std;

// Mock API: isBadVersion(version);

// Brute force: check every version
int firstBadVersionBF(int n, bool (*isBad)(int)) {
    for (int i = 1; i <= n; i++) {
        if (isBad(i)) return i;
    }
    return -1;
}

// Optimized: binary search for first bad version
int firstBadVersionOpt(int n, bool (*isBad)(int)) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (isBad(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

// Example mock isBad implementation for testing
bool isBad(int v) {
    return v >= 4; // versions 4..n are bad
}

int main() {
    int n = 10;
    cout << "BF: " << firstBadVersionBF(n, isBad) << "\n";
    cout << "Opt: " << firstBadVersionOpt(n, isBad) << "\n";
    return 0;
}

/*
Logic: BF linear search O(n);  
Opt binary search O(log n).
*/