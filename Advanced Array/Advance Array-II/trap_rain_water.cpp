#include <bits/stdc++.h>
using namespace std;

// Brute force: for each position find max left and max right, calculate trapped water
int trapWaterBF(const vector<int>& height) {
    int n = height.size();
    int res = 0;
    for(int i=0; i<n; i++) {
        int leftMax = 0, rightMax = 0;
        for(int j=0; j<=i; j++) leftMax = max(leftMax, height[j]);
        for(int j=i; j<n; j++) rightMax = max(rightMax, height[j]);
        res += min(leftMax, rightMax) - height[i];
    }
    return res;
}

// Optimized: precompute maxLeft and maxRight arrays
int trapWaterOpt(const vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for(int i=1; i<n; i++)
        leftMax[i] = max(leftMax[i-1], height[i]);
    rightMax[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--)
        rightMax[i] = max(rightMax[i+1], height[i]);
    int res = 0;
    for(int i=0; i<n; i++)
        res += min(leftMax[i], rightMax[i]) - height[i];
    return res;
}

int main() {
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "BF: " << trapWaterBF(h) << "\n";
    cout << "Opt: " << trapWaterOpt(h) << "\n";
    return 0;
}

/*
Logic: BF scans each position left and right max height O(n^2).  
Opt uses precomputed arrays for O(n) time.  
Space: O(n) for precomputed arrays.
*/