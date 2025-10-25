#include <bits/stdc++.h>
using namespace std;

// Brute force: linear search
int searchRotatedBF(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Optimized: modified binary search
int searchRotatedOpt(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[left] <= arr[mid]) { // left half sorted
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else { // right half sorted
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> a = {4,5,6,7,0,1,2};
    cout << "BF: " << searchRotatedBF(a, 0) << "\n";
    cout << "Opt: " << searchRotatedOpt(a, 0) << "\n";
    return 0;
}

/*
Logic: BF linear scan O(n).  
Opt locates target by binary search in rotated array in O(log n).
*/