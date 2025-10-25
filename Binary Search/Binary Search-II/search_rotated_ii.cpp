#include <bits/stdc++.h>
using namespace std;

// Brute force is same as BF above

// Optimized: handles duplicates by slight modification
bool searchRotatedIIOpt(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
            left++; right--;
        } else if (arr[left] <= arr[mid]) {
            if (target >= arr[left] && target < arr[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (target > arr[mid] && target <= arr[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> a = {2,5,6,0,0,1,2};
    cout << (searchRotatedIIOpt(a, 0) ? "Found" : "Not Found") << "\n";
    cout << (searchRotatedIIOpt(a, 3) ? "Found" : "Not Found") << "\n";
    return 0;
}

/*
Logic: Handles duplicates by shrinking edges when equal to mid.  
Maintains O(log n) average time, worst O(n).
*/