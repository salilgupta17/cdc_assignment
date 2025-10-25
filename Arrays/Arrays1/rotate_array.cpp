#include <bits/stdc++.h>
using namespace std;

// Rotate array to the right by k positions
void rotateBF(vector<int>& a, int k) {
    int n = a.size();
    k %= n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) b[(i + k) % n] = a[i];
    a = b;
}

void rotateOpt(vector<int>& a, int k) {
    int n = a.size();
    k %= n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}

int main() {
    vector<int> a = {1,2,3,4,5,6,7};
    rotateOpt(a, 3);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
