#include <bits/stdc++.h>
using namespace std;

// Brute force: check all pairs
vector<int> twoSumBF(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (nums[i]+nums[j] == target) return {i, j};
        }
    }
    return {};
}

// Optimized: hashmap to find complement
vector<int> twoSumOpt(const vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i=0; i<(int)nums.size(); i++) {
        int comp = target - nums[i];
        if (mp.count(comp)) return {mp[comp], i};
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto res = twoSumOpt(nums, target);
    if (!res.empty()) cout << res[0] << " " << res[1] << '\n';
    return 0;
}
