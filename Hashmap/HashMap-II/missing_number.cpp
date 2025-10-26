#include <bits/stdc++.h>
using namespace std;

// Brute force: check presence of each number
int missingNumberBF(const vector<int>& nums, int n) {
    for (int i=1; i<=n; i++) {
        if (find(nums.begin(), nums.end(), i) == nums.end()) return i;
    }
    return -1; // no missing
}

// Optimized: use sum formula and calculate difference
int missingNumberOpt(const vector<int>& nums, int n) {
    int total = n*(n+1)/2;
    int sum = 0;
    for (int x : nums) sum += x;
    return total - sum;
}

int main() {
    vector<int> nums = {1,2,4,5};
    cout << missingNumberOpt(nums, 5) << '\n';
    return 0;
}
