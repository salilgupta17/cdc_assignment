#include <bits/stdc++.h>
using namespace std;

// Brute force: create cleaned string and check palindrome
bool validPalBF(string s) {
    string clean = "";
    for (char c : s) {
        if (isalnum(c)) clean += tolower(c);
    }
    string rev = clean;
    reverse(rev.begin(), rev.end());
    return clean == rev;
}

// Optimized: two pointers check ignoring non-alnum chars
bool validPalOpt(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << (validPalBF(s) ? "BF: true\n" : "BF: false\n");
    cout << (validPalOpt(s) ? "Opt: true\n" : "Opt: false\n");
    return 0;
}

/*
Logic: BF cleans string and checks palindrome by reversal.  
Opt uses two pointers moving inward checking chars directly.  
Time: BF O(n), Opt O(n)  
Space: BF O(n), Opt O(1).
*/