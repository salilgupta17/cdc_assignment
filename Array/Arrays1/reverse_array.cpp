#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr) {
    int n = arr.size();

    // Brute force approach using extra space
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = arr[n - i - 1]; // Copy in reverse order
    }
    // Assign reversed array back
    arr = temp;

    // Optimized in-place two-pointer approach
    int start = 0, end = arr.size() - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr);
    for (int val : arr) cout << val << " ";
    return 0;
}

/*
Logic: Brute-force copies array in reverse order using extra space.  
Optimized swaps elements in place with two pointers.  
Time Complexity: Both O(n)  
Space Complexity: Brute-force O(n), Optimized O(1)
*/