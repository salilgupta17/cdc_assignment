#include <bits/stdc++.h>
using namespace std;

// Brute force: for each element search left for smaller element
vector<int> smallerLeftBF(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    for (int i=0; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (arr[j] < arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}

// Optimized: use stack to maintain decreasing elements
vector<int> smallerLeftOpt(const vector<int>& arr) {
    vector<int> res;
    stack<int> s;
    for (int x : arr) {
        while (!s.empty() && s.top() >= x) s.pop();
        res.push_back(s.empty() ? -1 : s.top());
        s.push(x);
    }
    return res;
}

int main() {
    vector<int> a = {1, 3, 0, 2, 5};
    auto bf = smallerLeftBF(a);
    auto opt = smallerLeftOpt(a);
    cout << "BF: "; for (int x: bf) cout << x << " ";
    cout << "\nOpt: "; for (int x: opt) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF scans left for smaller element for each index O(n^2).  
Opt uses stack to maintain decreasing order, O(n).  
*/