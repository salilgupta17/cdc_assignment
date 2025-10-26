#include <bits/stdc++.h>
using namespace std;

// Brute force: count set bits using built-in function
int countBitsBF(int n) {
    return __builtin_popcount(n);
}

// Optimized: Brian Kernighan's algorithm
int countBitsOpt(int n) {
    int count = 0;
    while (n) {
        n &= (n-1);
        count++;
    }
    return count;
}

/*
Logic: BF uses built-in func.  
Opt uses Brian Kernighan's algo to count set bits in O(number of set bits).
*/