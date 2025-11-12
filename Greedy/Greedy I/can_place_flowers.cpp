#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    
    for (int i = 0; i < size; i++) {
        // Check if current plot is empty
        if (flowerbed[i] == 0) {
            // Check if prev plot is empty (or first plot)
            bool prevEmpty = (i == 0 || flowerbed[i-1] == 0);
            // Check if next plot is empty (or last plot)
            bool nextEmpty = (i == size-1 || flowerbed[i+1] == 0);
            
            // If both adjacent plots are empty, we can plant here
            if (prevEmpty && nextEmpty) {
                flowerbed[i] = 1;  // Plant flower
                count++;           // Increment count
            }
        }
        
        // Early return if we've planted enough flowers
        if (count >= n) return true;
    }
    
    return count >= n;
}

/*
Logic: Greedily plant flowers whenever possible
1. For each empty plot, check adjacent plots
2. If both adjacent plots are empty, plant a flower
3. Mark plot as planted to affect future decisions
4. Count planted flowers and return true if target reached

Key Points:
- Consider edge cases (first and last plots)
- Plant as soon as possible (greedy approach)
- Update array to maintain adjacency constraint

Time Complexity: O(n) where n is length of flowerbed
Space Complexity: O(1) as we modify input array
*/

int main() {
    // Test Case 1: Basic case
    cout << "Test Case 1:" << endl;
    vector<int> bed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << "Flowerbed: ";
    for (int x : bed1) cout << x << " ";
    cout << "\nTarget flowers: " << n1;
    cout << "\nCan place flowers? " << (canPlaceFlowers(bed1, n1) ? "Yes" : "No") << endl;
    
    // Test Case 2: Edge case - all empty plots
    cout << "\nTest Case 2:" << endl;
    vector<int> bed2 = {0, 0, 0, 0, 0};
    int n2 = 3;
    cout << "Flowerbed: ";
    for (int x : bed2) cout << x << " ";
    cout << "\nTarget flowers: " << n2;
    cout << "\nCan place flowers? " << (canPlaceFlowers(bed2, n2) ? "Yes" : "No") << endl;
    
    // Test Case 3: Impossible case
    cout << "\nTest Case 3:" << endl;
    vector<int> bed3 = {1, 0, 0, 0, 1};
    int n3 = 2;
    cout << "Flowerbed: ";
    for (int x : bed3) cout << x << " ";
    cout << "\nTarget flowers: " << n3;
    cout << "\nCan place flowers? " << (canPlaceFlowers(bed3, n3) ? "Yes" : "No") << endl;
    
    return 0;
}