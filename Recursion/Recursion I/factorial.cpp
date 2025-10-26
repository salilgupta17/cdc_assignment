#include <bits/stdc++.h>
using namespace std;

// Brute force: iterative factorial
long long factBF(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

// Optimized: recursive factorial
long long factOpt(int n) {
    if (n <= 1) return 1;
    return n * factOpt(n - 1);
}

int main() {
    int n = 6;
    cout << "BF: " << factBF(n) << "\n";
    cout << "Opt: " << factOpt(n) << "\n";
    return 0;
}

/*
Logic: BF uses loop; Opt uses simple recursion.  
Time: O(n), Space: O(1) BF, O(n) Call Stack for recursion.
*/