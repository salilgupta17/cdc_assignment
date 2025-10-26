#include <bits/stdc++.h>
using namespace std;

// Using min heap of size k
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k)
            minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    cout << "3rd largest: " << findKthLargest(nums, 3) << '\n';
    return 0;
}
