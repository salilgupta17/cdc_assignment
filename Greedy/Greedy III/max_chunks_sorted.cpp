#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0;
    int maxVal = 0;
    
    // One pass through array
    for (int i = 0; i < arr.size(); i++) {
        // Update maximum value seen so far
        maxVal = max(maxVal, arr[i]);
        
        // If max value equals current index, we can make a chunk
        if (maxVal == i) {
            chunks++;
        }
    }
    return chunks;
}

/*
Logic: Split array into maximum number of chunks that can be sorted
1. Array contains permutation of [0 to n-1]
2. A chunk can end at index i if:
   - All elements till i are <= i
   - Maximum value seen till i equals i
3. This ensures all elements in chunk belong there after sorting

Why Greedy Works:
- For permutation 0 to n-1, each element must be in its correct chunk
- If max value seen equals current index, all previous elements
  must be less than or equal to this index
- This forms a valid chunk boundary

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only use two variables
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
    vector<int> arr1 = {1, 0, 2, 3, 4};
    cout << "Array: ";
    printArray(arr1);
    cout << "Maximum chunks possible: " << maxChunksToSorted(arr1) << endl;
    
    // Test Case 2: Only one chunk possible
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {4, 3, 2, 1, 0};
    cout << "Array: ";
    printArray(arr2);
    cout << "Maximum chunks possible: " << maxChunksToSorted(arr2) << endl;
    
    // Test Case 3: Maximum chunks (already sorted)
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {0, 1, 2, 3, 4};
    cout << "Array: ";
    printArray(arr3);
    cout << "Maximum chunks possible: " << maxChunksToSorted(arr3) << endl;
    
    // Test Case 4: Simple two chunk case
    cout << "\nTest Case 4:" << endl;
    vector<int> arr4 = {1, 0, 3, 2};
    cout << "Array: ";
    printArray(arr4);
    cout << "Maximum chunks possible: " << maxChunksToSorted(arr4) << endl;
    
    return 0;
}