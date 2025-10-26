#include <bits/stdc++.h>
using namespace std;

// Brute force: count frequency for each character, find max
char maxOccCharBF(string s) {
    int maxCount = 0;
    char res = '\0';
    for (char c : s) {
        int count = 0;
        for (char ch : s) {
            if (ch == c) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            res = c;
        }
    }
    return res;
}

// Optimized: use frequency array or map
char maxOccCharOpt(string s) {
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;
    char res = '\0';
    int maxCount = 0;
    for (auto& p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            res = p.first;
        }
    }
    return res;
}

int main() {
    string s = "abbcccddddeeeee";
    cout << "BF: " << maxOccCharBF(s) << "\n";
    cout << "Opt: " << maxOccCharOpt(s) << "\n";
    return 0;
}

/*
Logic: BF counts for each char with nested loops, O(n^2).  
Opt uses hashmap to find max freq char in O(n).  
Space: Opt O(n).
*/