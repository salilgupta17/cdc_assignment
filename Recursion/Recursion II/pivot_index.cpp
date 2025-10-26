#include <bits/stdc++.h>
using namespace std;

// Brute force: sum left and right separately for each index
int pivotBF(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int left = 0, right = 0;
        for (int j = 0; j < i; j++) left += arr[j];
        for (int j = i + 1; j < n; j++) right += arr[j];
        if (left == right) return i;
    }
    return -1;
}

// Optimized: prefix sums with total sum tracking
int pivotOpt(const vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        if (leftSum == total - leftSum - arr[i]) return i;
        leftSum += arr[i];
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
Logic: BF sums left/right at each index O(n^2).  
Opt uses prefix sums and total sum, O(n).
*/