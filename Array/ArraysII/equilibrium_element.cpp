#include <bits/stdc++.h>
using namespace std;

// Brute force: sum left and right for each index
int pivotBF(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int left = 0, right = 0;
        for (int j = 0; j < i; j++) left += arr[j];
        for (int j = i+1; j < n; j++) right += arr[j];
        if (left == right) return i;
    }
    return -1;
}

// Optimized: use prefix sums
int pivotOpt(vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    int left = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (left == total - left - arr[i]) return i;
        left += arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 7, 3, 6, 5, 6};
    cout << "BF pivot: " << pivotBF(arr) << "\n";
    cout << "Opt pivot: " << pivotOpt(arr) << "\n";
    return 0;
}

/*
Logic: BF checks left/right sums per element, Opt uses total and prefix sums.  
Time: BF O(n^2), Opt O(n). Space: O(1).
*/