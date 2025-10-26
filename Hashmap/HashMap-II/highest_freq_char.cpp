#include <bits/stdc++.h>
using namespace std;

// Brute force: count each character's frequency repeatedly
char highestFreqCharBF(const string& s) {
    int maxFreq = 0;
    char res = '\0';
    for (char c : s) {
        int freq = count(s.begin(), s.end(), c);
        if (freq > maxFreq) {
            maxFreq = freq;
            res = c;
        }
    }
    return res;
}

// Optimized: single pass map count
char highestFreqCharOpt(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    int maxFreq = 0;
    char res = '\0';
    for (auto& p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            res = p.first;
        }
    }
    return res;
}

int main() {
    string s = "abracadabra";
    cout << highestFreqCharOpt(s) << '\n';
    return 0;
}
