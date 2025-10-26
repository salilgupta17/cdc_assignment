#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

/*
Logic: Efficiently finds all primes up to n by marking multiples of primes.
Time: O(n log log n)
*/