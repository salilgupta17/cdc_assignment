#include <bits/stdc++.h>
using namespace std;

// Brute force: count frequencies and sort all
vector<int> topKFrequentBF(const vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;
    vector<pair<int,int>> freqArr(freq.begin(), freq.end());
    sort(freqArr.begin(), freqArr.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    vector<int> res;
    for (int i=0; i<k; i++) res.push_back(freqArr[i].first);
    return res;
}

// Optimized: use min heap of size k on frequencies
vector<int> topKFrequentOpt(const vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
    for (auto& p : freq) {
        minHeap.push({p.second, p.first});
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    vector<int> res;
    while (!minHeap.empty()) {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    auto res = topKFrequentOpt(nums, 2);
    for (int x : res) cout << x << " ";
    cout << '\n';
    return 0;
}
