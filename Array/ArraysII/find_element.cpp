#include <bits/stdc++.h>
using namespace std;

// Brute force: linear search
int findElemBF(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// Optimized: no better approach for unsorted arrays
int findElemOpt(vector<int>& arr, int x) {
    return findElemBF(arr, x);
}

int main() {
    vector<int> arr = {4, 2, 7, 1};
    cout << "BF Index: " << findElemBF(arr, 7) << "\n";
    cout << "Opt Index: " << findElemOpt(arr, 7) << "\n";
    return 0;
}

/*
Logic: Simple linear search for target element in array.  
Time: O(n), Space: O(1).
*/