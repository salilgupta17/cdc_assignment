#include <bits/stdc++.h>
using namespace std;

void subset2Helper(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
    // Add current subset to result
    res.push_back(curr);
    
    // Try including each remaining number
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates to ensure unique subsets
        if (i > index && nums[i] == nums[i - 1]) continue;
        
        // Include current number
        curr.push_back(nums[i]);
        // Recur with next index
        subset2Helper(nums, i + 1, curr, res);
        // Backtrack
        curr.pop_back();
    }
}

vector<vector<int>> subset2(vector<int>& nums) {
    // Sort array to handle duplicates
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> curr;
    subset2Helper(nums, 0, curr, res);
    return res;
}

/*
Logic: Generate all unique subsets using backtracking
1. Sort array to group duplicates together
2. For each position, decide whether to include current number
3. Skip duplicate numbers at same level to avoid duplicate subsets
4. Add each valid subset to result

Time Complexity: O(2^n) - potentially generate all possible subsets
Space Complexity: O(n) for recursion stack and current subset
where n is the length of input array
*/

// Helper function to print subsets
void printSubsets(const vector<vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "} ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Array with duplicates
    cout << "Test Case 1: [1,2,2]" << endl;
    vector<int> nums1 = {1, 2, 2};
    cout << "All unique subsets: ";
    auto result1 = subset2(nums1);
    printSubsets(result1);
    
    // Test Case 2: Array with multiple duplicates
    cout << "\nTest Case 2: [1,1,2,2]" << endl;
    vector<int> nums2 = {1, 1, 2, 2};
    cout << "All unique subsets: ";
    auto result2 = subset2(nums2);
    printSubsets(result2);
    
    // Test Case 3: Array with no duplicates
    cout << "\nTest Case 3: [1,2,3]" << endl;
    vector<int> nums3 = {1, 2, 3};
    cout << "All unique subsets: ";
    auto result3 = subset2(nums3);
    printSubsets(result3);
    
    return 0;
}