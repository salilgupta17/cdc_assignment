#include <bits/stdc++.h>
using namespace std;

// Brute force: create new string, skip if seen
string rmDupBF(string s) {
    string res = "";
    for (char c : s) {
        if (res.find(c) == string::npos)
            res += c;
    }
    return res;
}

// Optimized: hash set to track seen chars
string rmDupOpt(string s) {
    unordered_set<char> seen;
    string res = "";
    for (char c : s) {
        if (!seen.count(c)) {
            res += c;
            seen.insert(c);
        }
    }
    return res;
}

int main() {
    string s = "abracadabra";
    cout << "BF: " << rmDupBF(s) << "\n";
    cout << "Opt: " << rmDupOpt(s) << "\n";
    return 0;
}

/*
Logic: BF checks substring for duplicates O(n^2).  
Opt uses hash set, O(n).
*/