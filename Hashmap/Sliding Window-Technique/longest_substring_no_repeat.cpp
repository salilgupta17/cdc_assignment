#include <bits/stdc++.h>
using namespace std;

// Brute force: check all substrings
int lengthOfLongestSubstringBF(string s) {
    int n = s.size(), maxLen = 0;
    for (int i=0; i<n; i++) {
        unordered_set<char> seen;
        for (int j=i; j<n; j++) {
            if (seen.count(s[j])) break;
            seen.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}

// Optimized: sliding window using hashmap
int lengthOfLongestSubstringOpt(const string& s) {
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;
    for (int right=0; right<(int)s.size(); right++) {
        if (lastSeen.count(s[right]))
            left = max(left, lastSeen[s[right]] + 1);
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right-left+1);
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "BF: " << lengthOfLongestSubstringBF(s) << '\n';
    cout << "Opt: " << lengthOfLongestSubstringOpt(s) << '\n';
    return 0;
}
