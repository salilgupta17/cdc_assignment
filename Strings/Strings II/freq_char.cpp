#include <bits/stdc++.h>
using namespace std;

// Brute force: count occurrences by loop
int freqCharBF(string s, char c) {
    int count = 0;
    for (char ch : s) {
        if (ch == c) count++;
    }
    return count;
}

// Optimized: same as BF (O(n)) - no better method
int freqCharOpt(string s, char c) {
    return freqCharBF(s, c);
}

int main() {
    string s = "hello world";
    char c = 'l';
    cout << "BF: " << freqCharBF(s, c) << "\n";
    cout << "Opt: " << freqCharOpt(s, c) << "\n";
    return 0;
}

/*
Logic: Count character occurrences by iteration.  
Time: O(n), Space: O(1).
*/