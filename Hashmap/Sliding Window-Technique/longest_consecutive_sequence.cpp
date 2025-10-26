#include <bits/stdc++.h>
using namespace std;

// Brute force: sort and check consecutive sequences
int longestConseqSeqBF(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int longest = 1, current = 1;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] == nums[i-1] + 1) current++;
        else if (nums[i] != nums[i-1]) current = 1;
        longest = max(longest, current);
    }
    return longest;
}

// Optimized: use set and check start of sequence
int longestConseqSeqOpt(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int n : nums) {
        if (!s.count(n-1)) {
            int length = 1;
            while (s.count(n+length)) length++;
            longest = max(longest, length);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    cout << "Longest BF: " << longestConseqSeqBF(nums) << '\n';
    cout << "Longest Opt: " << longestConseqSeqOpt(nums) << '\n';
    return 0;
}
