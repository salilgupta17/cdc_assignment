#include <bits/stdc++.h>
using namespace std;

// Brute force: separate loops or recursive calls for sequences
void printIncBF(int n) {
    for (int i = 1; i <= n; i++) cout << i << " ";
}
void printDecBF(int n) {
    for (int i = n; i >= 1; i--) cout << i << " ";
}
void printDecIncBF(int n) {
    for (int i = n; i >= 1; i--) cout << i << " ";
    for (int i = 2; i <= n; i++) cout << i << " ";
}

// Optimized: recursion for all sequences
void printIncOpt(int n) {
    if (n == 0) return;
    printIncOpt(n - 1);
    cout << n << " ";
}
void printDecOpt(int n) {
    if (n == 0) return;
    cout << n << " ";
    printDecOpt(n - 1);
}
void printDecIncOpt(int n) {
    if (n == 0) return;
    cout << n << " ";
    printDecIncOpt(n - 1);
    cout << n << " ";
}

int main() {
    int n = 5;
    cout << "BF inc: "; printIncBF(n); cout << "\n";
    cout << "Opt inc: "; printIncOpt(n); cout << "\n";

    cout << "BF dec: "; printDecBF(n); cout << "\n";
    cout << "Opt dec: "; printDecOpt(n); cout << "\n";

    cout << "BF decinc: "; printDecIncBF(n); cout << "\n";
    cout << "Opt decinc: "; printDecIncOpt(n); cout << "\n";
    return 0;
}

/*
Logic: BF uses loops; Opt uses recursion to print sequences.  
Time: O(n), Space: O(1) BF, O(n) recursion stack.
*/