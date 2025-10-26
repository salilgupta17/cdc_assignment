#include <bits/stdc++.h>
using namespace std;

// Brute force: check mapping using two arrays
bool isIsomorphicBF(string s, string t) {
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i + 1; j < (int)s.size(); j++) {
            if ((s[i] == s[j]) != (t[i] == t[j])) return false;
        }
    }
    return true;
}

// Optimized: use two hash maps for char mapping both ways
bool isIsomorphicOpt(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> sToT, tToS;
    for (int i = 0; i < (int)s.size(); i++) {
        if (sToT.count(s[i]) && sToT[s[i]] != t[i]) return false;
        if (tToS.count(t[i]) && tToS[t[i]] != s[i]) return false;
        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
    }
    return true;
}

/*
Logic: BF quadratic due to double loops,  
Opt uses hash maps O(n).
*/