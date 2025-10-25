#include <bits/stdc++.h>
using namespace std;

// Brute force: check all subarrays and find max sum
int maxSubBF(const vector<int>& arr) {
    int maxSum = INT_MIN, n = (int)arr.size();
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Optimized: Kadane's algorithm to find max sum of contiguous subarray
int maxSubOpt(const vector<int>& arr) {
    int maxEnding = 0, maxSoFar = INT_MIN;
    for (int x : arr) {
        maxEnding = max(x, maxEnding + x);
        maxSoFar = max(maxSoFar, maxEnding);
    }
    return maxSoFar;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max subarray sum BF: " << maxSubBF(arr) << "\n";
    cout << "Max subarray sum Opt: " << maxSubOpt(arr) << "\n";
    return 0;
}

/*
Logic Explanation:
The brute force approach tries every subarray,
leading to O(n²) time due to nested loops.

Kadane’s algorithm efficiently computes the maximum subarray 
sum in O(n) by keeping track of maximum sum ending at current index,
making it optimal for large inputs.
*/