#include <bits/stdc++.h>
using namespace std;

// Brute force: nested search (inefficient)
vector<int> intersectionBF(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> res;
    vector<bool> used(nums2.size(), false);
    for (int n1 : nums1) {
        for (int i = 0; i < (int)nums2.size(); i++) {
            if (!used[i] && nums2[i] == n1) {
                res.push_back(n1);
                used[i] = true;
                break;
            }
        }
    }
    return res;
}

// Optimized: hashmap frequency counting
vector<int> intersectionOpt(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_map<int, int> freq;
    for (int n : nums1) freq[n]++;
    vector<int> res;
    for (int n : nums2) {
        if (freq[n] > 0) {
            res.push_back(n);
            freq[n]--;
        }
    }
    return res;
}

int main() {
    vector<int> a = {1,2,2,3};
    vector<int> b = {2,2};
    auto res = intersectionOpt(a,b);
    for (int x : res) cout << x << " ";
    cout << '\n';
    return 0;
}
