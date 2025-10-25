#include <bits/stdc++.h>
using namespace std;

int countMaxFrequencyElements(vector<int>& nums) {
    // Brute force: nested counts for each unique element
    unordered_map<int,int> freq;
    for (int num : nums) freq[num]++;
    int maxFreq = 0;
    for (auto& p : freq)
        if (p.second > maxFreq) maxFreq = p.second;
    int total = 0;
    for (auto& p : freq)
        if (p.second == maxFreq) total += p.second;

    // Optimized: same as above since brute force too expensive
    // This approach is already optimal in O(n)

    return total;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
    cout << countMaxFrequencyElements(nums);
    return 0;
}

/*
Logic: Count frequency of each element and sum those with max frequency.  
Time Complexity: O(n)  
Space Complexity: O(n)
*/