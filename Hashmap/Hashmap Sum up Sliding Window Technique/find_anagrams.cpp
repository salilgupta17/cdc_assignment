#include <bits/stdc++.h>
using namespace std;

// Brute force: check every substring if anagram
vector<int> findAnagramsBF(string s, string p) {
    int n = s.size(), m = p.size();
    vector<int> res;
    sort(p.begin(), p.end());
    for (int i = 0; i <= n - m; i++) {
        string sub = s.substr(i, m);
        sort(sub.begin(), sub.end());
        if (sub == p) res.push_back(i);
    }
    return res;
}

// Optimized: sliding window with frequency count arrays
vector<int> findAnagramsOpt(string s, string p) {
    vector<int> res;
    int ns = s.size(), np = p.size();
    if (ns < np) return res;
    vector<int> pCount(26, 0), sCount(26, 0);
    for (char c : p) pCount[c - 'a']++;
    for (int i = 0; i < np; i++) sCount[s[i] - 'a']++;
    if (sCount == pCount) res.push_back(0);
    for (int i = np; i < ns; i++) {
        sCount[s[i] - 'a']++;
        sCount[s[i - np] - 'a']--;
        if (sCount == pCount) res.push_back(i - np + 1);
    }
    return res;
}

/*
Logic: BF sorts each window O(m log m) * O(n),  
Opt uses O(1) freq map updates sliding window O(n).
*/