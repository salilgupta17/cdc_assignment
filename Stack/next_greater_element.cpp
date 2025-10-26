#include <bits/stdc++.h>
using namespace std;

// Brute force: for each element, find next greater by scanning right
vector<int> nextGreaterBF(const vector<int>& arr) {
    int n=arr.size();
    vector<int> res(n, -1);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[j]>arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}

// Optimized: use stack to keep indexes of elements
vector<int> nextGreaterOpt(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i=n-1; i>=0; i--) {
        while (!s.empty() && s.top() <= arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> a = {4, 5, 2, 25};
    auto bf = nextGreaterBF(a);
    auto opt = nextGreaterOpt(a);
    cout << "BF: ";
    for (int x: bf) cout << x << " ";
    cout << "\nOpt: ";
    for (int x: opt) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF checks right of each element;  
Opt uses stack to track next greater in reverse.  
Time: BF O(n^2), Opt O(n).
*/