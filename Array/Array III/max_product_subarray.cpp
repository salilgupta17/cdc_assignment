#include <bits/stdc++.h>
using namespace std;

// Brute force: multiply all subarray elements to find max product
int maxProdBF(const vector<int>& arr) {
    int maxProd = INT_MIN, n = (int)arr.size();
    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = i; j < n; j++) {
            prod *= arr[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

// Optimized: Track max and min product so far to handle negatives
int maxProdOpt(const vector<int>& arr) {
    int maxP = arr[0], minP = arr[0], res = arr[0];
    for (int i = 1; i < (int)arr.size(); i++) {
        if (arr[i] < 0) swap(maxP, minP);
        maxP = max(arr[i], maxP * arr[i]);
        minP = min(arr[i], minP * arr[i]);
        res = max(res, maxP);
    }
    return res;
}

int main() {
    vector<int> arr = {2,3,-2,4};
    cout << "Max prod BF: " << maxProdBF(arr) << "\n";
    cout << "Max prod Opt: " << maxProdOpt(arr) << "\n";
    return 0;
}

/*
Logic Explanation:
Brute force method considers all subarray products, 
costly due to O(n²) complexity.

Optimized approach maintains both max and min products at each step,
accounting for negative values flipping signs,
achieving O(n) time with constant space.
*/