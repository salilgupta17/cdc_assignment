#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();

    // Brute force: rotate one step at a time k times
    // k %= n;
    // for (int i = 0; i < k; i++) {
    //     int last = nums[n-1];
    //     for (int j = n-1; j > 0; j--) {
    //         nums[j] = nums[j-1];
    //     }
    //     nums[0] = last;
    // }

    // Optimized: reverse segments
   
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
   
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotateArray(nums, k);
    for (int x : nums) cout << x << " ";
    return 0;
}

/*
Logic: Brute force rotates elements one at a time.  
Optimized reverses segments to achieve rotation.  
Time Complexity: Brute force O(n*k), Optimized O(n)  
Space Complexity: O(1)
*/
