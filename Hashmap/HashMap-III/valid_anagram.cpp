#include <bits/stdc++.h>
using namespace std;

// Brute force: sort and check equality
bool isAnagramBF(string s, string t) {
    if (s.size() != t.size()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Optimized: frequency count comparison
bool isAnagramOpt(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) {
        if (--count[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    cout << (isAnagramOpt("anagram","nagaram") ? "Yes" : "No") << '\n';
    cout << (isAnagramOpt("rat","car") ? "Yes" : "No") << '\n';
    return 0;
}
