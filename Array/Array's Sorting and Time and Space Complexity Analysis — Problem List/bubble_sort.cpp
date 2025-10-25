#include <bits/stdc++.h>
using namespace std;

// Brute force: Standard bubble sort, swap adjacent if middle elements out of order
void bubbleSortBF(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization to stop if already sorted
    }
}

// Optimized bubble sort: same as above, with early exit optimization included
void bubbleSortOpt(vector<int>& arr) {
    bubbleSortBF(arr); // Already optimized with swapped flag
}

int main() {
    vector<int> arr1 = {5, 1, 4, 2, 8};
    bubbleSortBF(arr1);
    cout << "Bubble sort BF: ";
    for (int x : arr1) cout << x << " ";

    cout << "\n";

    vector<int> arr2 = {5, 1, 4, 2, 8};
    bubbleSortOpt(arr2);
    cout << "Bubble sort Opt: ";
    for (int x : arr2) cout << x << " ";
    return 0;
}

/*
Logic: Bubble sort repeatedly swaps adjacent out-of-order elements.  
Time: Average and worst O(n^2), Best O(n) if array already sorted.  
Space: O(1).
*/