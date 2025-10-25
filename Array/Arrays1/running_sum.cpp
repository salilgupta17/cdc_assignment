#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    // Brute force: sum for each position
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) sum += nums[j];
        result[i] = sum;
    }

    // Optimized: cumulative sum in-place
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = runningSum(nums);
    for (int val : result) cout << val << " ";
    return 0;
}

/*
Logic: Brute force sums up all elements before index each time.  
Optimized does cumulative sum in one pass.  
Time Complexity: Brute force O(n^2), Optimized O(n)  
Space Complexity: O(n) for result array
*/