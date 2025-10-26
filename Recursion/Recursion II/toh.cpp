#include <bits/stdc++.h>
using namespace std;

// Brute force and optimized use same recursive logic

void toh(int n, char from, char to, char aux) {
    if (n == 0) return;
    toh(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    toh(n - 1, aux, to, from);
}

int main() {
    int n = 3;
    toh(n, 'A', 'C', 'B');
    return 0;
}

/*
Logic: Recursively move n-1 disks, then largest disk, then n-1 disks again.  
Total moves: 2^n -1
*/