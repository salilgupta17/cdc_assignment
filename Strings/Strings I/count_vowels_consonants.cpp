#include <bits/stdc++.h>
using namespace std;

// Brute force: iterate and count vowels/consonants with separate counters
pair<int,int> countVCBF(string s) {
    int v=0, c=0;
    for (char ch : s) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') v++;
            else c++;
        }
    }
    return {v,c};
}

// Optimized: same as BF (already O(n) time and O(1) space)
pair<int,int> countVCOpt(string s) {
    return countVCBF(s);
}

int main() {
    string s = "Hello, World!";
    auto [v,c] = countVCBF(s);
    cout << "BF Vowels: " << v << ", Consonants: " << c << "\n";
    auto p = countVCOpt(s);
    cout << "Opt Vowels: " << p.first << ", Consonants: " << p.second << "\n";
    return 0;
}

/*
Logic: Iterate string counting vowels and consonants.  
Time: O(n), Space: O(1).
*/