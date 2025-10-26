#include <bits/stdc++.h>
using namespace std;

// Brute force: check max in every window
vector<int> slidingWindowMaxBF(const vector<int>& nums, int k) {
    vector<int> res;
    for (int i=0; i<= (int)nums.size()-k; i++) {
        int maxVal = nums[i];
        for (int j=i+1; j<i+k; j++) {
            maxVal = max(maxVal, nums[j]);
        }
        res.push_back(maxVal);
    }
    return res;
}

// Optimized: dequeue stores indices of potentially max elements
vector<int> slidingWindowMaxOpt(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i=0; i<(int)nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i-k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) res.push_back(nums[dq.front()]);
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = slidingWindowMaxOpt(nums, 3);
    for (int x : res) cout << x << " ";
    cout << '\n';
    return 0;
}
