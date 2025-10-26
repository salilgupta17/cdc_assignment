#include <bits/stdc++.h>
using namespace std;

// Using max heap of size k
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    for (int num : nums) {
        maxHeap.push(num);
        if ((int)maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
}

int main() {
    vector<int> nums = {7,10,4,3,20,15};
    cout << "3rd smallest: " << findKthSmallest(nums, 3) << '\n';
    return 0;
}
