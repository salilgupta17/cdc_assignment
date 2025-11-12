#include <bits/stdc++.h>
using namespace std;

void combSumHelper(vector<int>& arr, int target, int index, vector<int>& curr, vector<vector<int>>& res) {
    // Base case: target is achieved
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    
    // Try all possible numbers from index
    for (int i = index; i < arr.size(); i++) {
        // Skip if current number is too large
        if (arr[i] > target) continue;
        
        // Include current number
        curr.push_back(arr[i]);
        // Recur with reduced target (same index as number can be reused)
        combSumHelper(arr, target - arr[i], i, curr, res);
        // Backtrack
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    // Sort array for better pruning
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> curr;
    combSumHelper(arr, target, 0, curr, res);
    return res;
}

/*
Logic: Find all combinations that sum to target (numbers can be reused)
1. Sort array for optimization (skip larger numbers)
2. For each number that doesn't exceed target:
   - Include it in current combination
   - Recur with reduced target
   - Can reuse same number (pass same index)
3. Backtrack by removing last number

Time Complexity: O(N^(T/M)) where N is array size, T is target, M is minimum number
Space Complexity: O(T/M) for recursion depth
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
    // Test Case 1: [2,3,6,7], target = 7
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {2, 3, 6, 7};
    int target1 = 7;
    cout << "Array: ";
    for (int num : arr1) cout << num << " ";
    cout << "\nTarget: " << target1 << endl;
    cout << "Combinations: ";
    auto result1 = combinationSum(arr1, target1);
    printCombinations(result1);
    
    // Test Case 2: [2,3,5], target = 8
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {2, 3, 5};
    int target2 = 8;
    cout << "Array: ";
    for (int num : arr2) cout << num << " ";
    cout << "\nTarget: " << target2 << endl;
    cout << "Combinations: ";
    auto result2 = combinationSum(arr2, target2);
    printCombinations(result2);
    
    // Test Case 3: [2], target = 1
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {2};
    int target3 = 1;
    cout << "Array: ";
    for (int num : arr3) cout << num << " ";
    cout << "\nTarget: " << target3 << endl;
    cout << "Combinations: ";
    auto result3 = combinationSum(arr3, target3);
    printCombinations(result3);
    
    return 0;
}