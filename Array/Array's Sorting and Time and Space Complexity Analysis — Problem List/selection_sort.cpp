#include <bits/stdc++.h>
using namespace std;

// Brute force: repeatedly find minimum and swap at front
void selectionSortBF(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Optimized: Selection sort same for all cases, no early exit
void selectionSortOpt(vector<int>& arr) {
    selectionSortBF(arr);
}

int main() {
    vector<int> arr1 = {64, 25, 12, 22, 11};
    selectionSortBF(arr1);
    cout << "Selection sort BF: ";
    for (int x : arr1) cout << x << " ";

    cout << "\n";

    vector<int> arr2 = {64, 25, 12, 22, 11};
    selectionSortOpt(arr2);
    cout << "Selection sort Opt: ";
    for (int x : arr2) cout << x << " ";
    return 0;
}

/*
Logic: Selection sort repeatedly selects minimum element to front.  
Time: Always O(n^2), Space: O(1).
*/