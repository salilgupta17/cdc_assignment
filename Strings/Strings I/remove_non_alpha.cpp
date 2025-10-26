#include <bits/stdc++.h>
using namespace std;

// Brute force: construct new string with only alphabets
string rmNonAlphaBF(string s) {
    string res;
    for (char c : s)
        if (isalpha(c)) res += c;
    return res;
}

// Optimized: same as BF since linear scan needed
string rmNonAlphaOpt(string s) {
    return rmNonAlphaBF(s);
}

int main() {
    string s = "Hello, 123 World!";
    cout << "BF: " << rmNonAlphaBF(s) << "\n";
    cout << "Opt: " << rmNonAlphaOpt(s) << "\n";
    return 0;
}

/*
Logic: Build new string with alphabet characters only.  
Time: O(n), Space: O(n).
*/