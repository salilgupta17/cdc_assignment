#include <bits/stdc++.h>
using namespace std;

int maxChunksToSortedII(vector<int>& arr) {
    int n = arr.size();
    
    // Create array to store minimum value to the right
    vector<int> rightMin(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], arr[i]);
    }
    
    // Count chunks while maintaining maximum on left
    int count = 0;
    int leftMax = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        leftMax = max(leftMax, arr[i]);
        // If max of left <= min of right, we can make a cut here
        if (leftMax <= rightMin[i + 1]) {
            count++;
        }
    }
    
    return count;
}

/*
Logic: Split array into maximum sorted chunks
1. For each position i, we can make a cut if:
   - All elements to left are <= all elements to right
2. Precompute minimum value to right of each position
3. Track maximum value to left while scanning
4. When leftMax <= rightMin, we can make a cut

Why Greedy Works:
- If max of left subset <= min of right subset
- Then left and right can be sorted independently
- This gives optimal chunk boundary

Time Complexity: O(n) - two passes through array
Space Complexity: O(n) - for rightMin array
*/

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Multiple chunks possible
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {5, 4, 3, 2, 1};
    cout << "Array: ";
    printArray(arr1);
    cout << "Maximum chunks possible: " << maxChunksToSortedII(arr1) << endl;
    
    // Test Case 2: Array with duplicates
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {2, 1, 3, 4, 4};
    cout << "Array: ";
    printArray(arr2);
    cout << "Maximum chunks possible: " << maxChunksToSortedII(arr2) << endl;
    
    // Test Case 3: Already sorted array
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Array: ";
    printArray(arr3);
    cout << "Maximum chunks possible: " << maxChunksToSortedII(arr3) << endl;
    
    // Test Case 4: Two chunk case
    cout << "\nTest Case 4:" << endl;
    vector<int> arr4 = {2, 1, 4, 3};
    cout << "Array: ";
    printArray(arr4);
    cout << "Maximum chunks possible: " << maxChunksToSortedII(arr4) << endl;
    
    return 0;
}