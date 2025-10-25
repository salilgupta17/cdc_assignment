#include <bits/stdc++.h>
using namespace std;

pair<int,int> findMinMax(vector<int>& nums) {
    // Brute force: two separate scans
    int minimum = *min_element(nums.begin(), nums.end());
    int maximum = *max_element(nums.begin(), nums.end());

    // Optimized: single scan to find both min and max
    int minVal = nums[0], maxVal = nums[0];
    for (int val : nums) {
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
    return {minVal, maxVal};
}

int main() {
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    auto [minVal, maxVal] = findMinMax(nums);
    cout << "Minimum: " << minVal << ", Maximum: " << maxVal;
    return 0;
}

/*
Logic: Brute force separately finds min and max with two passes.  
Optimized does it in a single pass.  
Time Complexity: O(n)  
Space Complexity: O(1)
*/