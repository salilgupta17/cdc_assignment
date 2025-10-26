#include <bits/stdc++.h>
using namespace std;

// Heapify function to maintain heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;   
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort algorithm
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> data = {4, 10, 3, 5, 1};
    cout << "Before: "; for (int x : data) cout << x << " "; cout << '\n';
    heapSort(data);
    cout << "After: "; for (int x : data) cout << x << " "; cout << '\n';
    return 0;
}
