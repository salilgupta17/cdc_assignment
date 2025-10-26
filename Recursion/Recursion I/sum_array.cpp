#include <bits/stdc++.h>
using namespace std;

// Brute force: iterative sum
int sumArrBF(const vector<int>& arr) {
    int res = 0;
    for (int x : arr) res += x;
    return res;
}

// Optimized: recursive sum
int sumArrOpt(const vector<int>& arr, int idx=0) {
    if (idx == arr.size()) return 0;
    return arr[idx] + sumArrOpt(arr, idx + 1);
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    cout << "BF: " << sumArrBF(arr) << "\n";
    cout << "Opt: " << sumArrOpt(arr) << "\n";
    return 0;
}

/*
Logic: BF iterative sum; Opt recursive accumulation.  
Time: O(n), Space: O(1) BF, O(n) recursion stack.
*/