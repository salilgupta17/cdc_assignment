#include <bits/stdc++.h>
using namespace std;

// Brute force: insert elements in sorted order by shifting
void insertionSortBF(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Optimized: same as above, but best case runs in O(n)
void insertionSortOpt(vector<int>& arr) {
    insertionSortBF(arr);
}

int main() {
    vector<int> arr1 = {12, 11, 13, 5, 6};
    insertionSortBF(arr1);
    cout << "Insertion sort BF: ";
    for (int x : arr1) cout << x << " ";

    cout << "\n";

    vector<int> arr2 = {12, 11, 13, 5, 6};
    insertionSortOpt(arr2);
    cout << "Insertion sort Opt: ";
    for (int x : arr2) cout << x << " ";
    return 0;
}

/*
Logic: Insert element into sorted subarray by shifting.  
Time: Worst O(n^2), Best O(n) if already sorted.  
Space: O(1).
*/