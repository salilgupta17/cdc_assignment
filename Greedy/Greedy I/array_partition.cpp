#include <bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    // Sort array to ensure optimal pairing
    sort(nums.begin(), nums.end());
    
    int sum = 0;
    // Take every alternate element (first of each pair)
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}

/*
Logic: Maximize sum of minimum elements in pairs
1. Sort array to group similar numbers together
2. Pair consecutive elements (minimizes difference in pairs)
3. Sum first element of each pair (will be minimum in pair)
4. Greedy approach ensures maximum possible sum

Why this works:
- Sorting ensures minimum difference between paired elements
- Taking every alternate element gives minimum of each pair
- This maximizes the overall sum of minimums

Time Complexity: O(nlogn) due to sorting
Space Complexity: O(1) as we sort in-place
*/

int main() {
    // Test Case 1: Basic even-length array
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 4, 3, 2};
    cout << "Array: ";
    for (int x : nums1) cout << x << " ";
    cout << "\nMaximum sum: " << arrayPairSum(nums1) << endl;
    
    // Test Case 2: Array with duplicates
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {6, 2, 6, 5, 1, 2};
    cout << "Array: ";
    for (int x : nums2) cout << x << " ";
    cout << "\nMaximum sum: " << arrayPairSum(nums2) << endl;
    
    // Test Case 3: Array with negative numbers
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {-1, -4, -3, -2};
    cout << "Array: ";
    for (int x : nums3) cout << x << " ";
    cout << "\nMaximum sum: " << arrayPairSum(nums3) << endl;
    
    return 0;
}