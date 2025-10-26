#include <bits/stdc++.h>
using namespace std;

// Brute force: pure recursion (exponential)
int fibBF(int n) {
    if (n <= 1) return n;
    return fibBF(n - 1) + fibBF(n - 2);
}

// Optimized: DP with memoization
int fibOptHelp(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibOptHelp(n - 1, dp) + fibOptHelp(n - 2, dp);
}
int fibOpt(int n) {
    vector<int> dp(n + 1, -1);
    return fibOptHelp(n, dp);
}

int main() {
    int n = 10;
    cout << "BF: " << fibBF(n) << "\n";
    cout << "Opt: " << fibOpt(n) << "\n";
    return 0;
}

/*
Logic: BF is exponential recursion; Opt uses memoized DP O(n).
*/