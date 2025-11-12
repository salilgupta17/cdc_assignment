#include <bits/stdc++.h>
using namespace std;

void combSum2Helper(vector<int>& arr, int target, int start, vector<int>& curr, vector<vector<int>>& res) {
    // Base case: target is achieved
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    
    // Try all possible numbers from start
    for (int i = start; i < arr.size(); i++) {
        // Skip duplicates to avoid duplicate combinations
        if (i > start && arr[i] == arr[i - 1]) continue;
        // Break if current number is too large (array is sorted)
        if (arr[i] > target) break;
        
        // Include current number
        curr.push_back(arr[i]);
        // Recur with next index (no reuse allowed)
        combSum2Helper(arr, target - arr[i], i + 1, curr, res);
        // Backtrack
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    // Sort array to handle duplicates and for optimization
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> curr;
    combSum2Helper(arr, target, 0, curr, res);
    return res;
}

/*
Logic: Find all unique combinations that sum to target (no number reuse)
1. Sort array to group duplicates and optimize
2. For each unique number that doesn't exceed target:
   - Include it in current combination
   - Recur with next index (no reuse)
   - Skip duplicates to avoid duplicate combinations
3. Backtrack by removing last number

Time Complexity: O(2^n) in worst case
Space Complexity: O(n) for recursion depth
*/

// Helper function to print combinations
void printCombinations(const vector<vector<int>>& combinations) {
    for (const auto& combo : combinations) {
        cout << "{";
        for (int i = 0; i < combo.size(); i++) {
            cout << combo[i];
            if (i < combo.size() - 1) cout << ",";
        }
        cout << "} ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: [10,1,2,7,6,1,5], target = 8
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    cout << "Array: ";
    for (int num : arr1) cout << num << " ";
    cout << "\nTarget: " << target1 << endl;
    cout << "Combinations: ";
    auto result1 = combinationSum2(arr1, target1);
    printCombinations(result1);
    
    // Test Case 2: [2,5,2,1,2], target = 5
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    cout << "Array: ";
    for (int num : arr2) cout << num << " ";
    cout << "\nTarget: " << target2 << endl;
    cout << "Combinations: ";
    auto result2 = combinationSum2(arr2, target2);
    printCombinations(result2);
    
    // Test Case 3: [1,1,1,1,1], target = 3
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {1, 1, 1, 1, 1};
    int target3 = 3;
    cout << "Array: ";
    for (int num : arr3) cout << num << " ";
    cout << "\nTarget: " << target3 << endl;
    cout << "Combinations: ";
    auto result3 = combinationSum2(arr3, target3);
    printCombinations(result3);
    
    return 0;
}