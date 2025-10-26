#include <bits/stdc++.h>
using namespace std;

// Brute force: multiply x, n times
long long powBF(int x, int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) res *= x;
    return res;
}

// Optimized: exponentiation by squaring
long long powOpt(int x, int n) {
    if (n == 0) return 1;
    long long half = powOpt(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return x * half * half;
}

int main() {
    int x = 2, n = 10;
    cout << "BF: " << powBF(x, n) << "\n";
    cout << "Opt: " << powOpt(x, n) << "\n";
    return 0;
}

/*
Logic: BF repeated multiplication; Opt divides problem in halves.  
Time: BF O(n), Opt O(log n). Space: O(1) BF, O(log n) recursion.
*/