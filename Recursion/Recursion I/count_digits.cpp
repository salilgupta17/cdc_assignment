#include <bits/stdc++.h>
using namespace std;

// Brute force: convert to string and count
int countDigitsBF(int n) {
    string s = to_string(n);
    return s.size();
}

// Optimized: recursion by dividing by 10
int countDigitsOpt(int n) {
    if (n == 0) return 0;
    return 1 + countDigitsOpt(n / 10);
}

int main() {
    int n = 123456;
    cout << "BF: " << countDigitsBF(n) << "\n";
    cout << "Opt: " << countDigitsOpt(n) << "\n";
    return 0;
}

/*
Logic: BF uses string conversion; Opt uses digit count with recursion.  
Time: O(log n), Space: O(log n) recursion.
*/