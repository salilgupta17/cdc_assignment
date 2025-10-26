#include <bits/stdc++.h>
using namespace std;

// Brute force: check nodes and children directly
bool isMaxHeapBF(const vector<int>& arr) {
    int n = arr.size();
    for (int i=0; i<= (n-2)/2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

// Optimized: same linear check; no faster approach
bool isMaxHeapOpt(const vector<int>& arr) {
    return isMaxHeapBF(arr);
}

int main() {
    vector<int> a = {10, 9, 8, 5, 6, 7};
    cout << (isMaxHeapOpt(a) ? "Is Max Heap" : "Not Max Heap") << '\n';
    return 0;
}
