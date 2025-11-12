#include <bits/stdc++.h>
using namespace std;

int findMinPlatform(vector<int>& arrival, vector<int>& departure) {
    // Sort arrival and departure times
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int platforms_needed = 1;  // At least one platform
    int result = 1;           // Track maximum platforms needed
    int i = 1, j = 0;        // Pointers for arrival and departure
    
    // Process all arrivals and departures
    while (i < arrival.size() && j < departure.size()) {
        // If next train arrives before one departs
        if (arrival[i] <= departure[j]) {
            platforms_needed++;  // Need extra platform
            i++;
        }
        // If a train departs
        else {
            platforms_needed--;  // Free up platform
            j++;
        }
        
        // Update maximum platforms needed
        result = max(result, platforms_needed);
    }
    
    return result;
}

/*
Logic: Find minimum platforms needed for all trains
1. Sort arrival and departure times separately
2. Use two pointers to process events chronologically
3. For each arrival before next departure:
   - Need an extra platform
4. For each departure:
   - Free up one platform
5. Track maximum platforms needed at any time

Why Greedy Works:
- Sorting ensures we process events in chronological order
- At any time, platforms needed = (arrivals - departures)
- Maximum value gives minimum platforms required

Time Complexity: O(n log n) for sorting
Space Complexity: O(1) excluding input arrays
*/

void printSchedule(const vector<int>& arr, const vector<int>& dep) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "Train " << i+1 << ": Arrival=" << arr[i] 
             << ", Departure=" << dep[i] << endl;
    }
}

int main() {
    // Test Case 1: Normal case
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {200, 300, 500, 600};
    vector<int> dep1 = {400, 700, 600, 800};
    cout << "Train Schedule:" << endl;
    printSchedule(arr1, dep1);
    cout << "Minimum platforms needed: " << findMinPlatform(arr1, dep1) << endl;
    
    // Test Case 2: All trains arrive at same time
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {100, 100, 100, 100};
    vector<int> dep2 = {200, 300, 400, 500};
    cout << "Train Schedule:" << endl;
    printSchedule(arr2, dep2);
    cout << "Minimum platforms needed: " << findMinPlatform(arr2, dep2) << endl;
    
    // Test Case 3: No overlap
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {100, 300, 500};
    vector<int> dep3 = {200, 400, 600};
    cout << "Train Schedule:" << endl;
    printSchedule(arr3, dep3);
    cout << "Minimum platforms needed: " << findMinPlatform(arr3, dep3) << endl;
    
    return 0;
}