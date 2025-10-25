#include <bits/stdc++.h>
using namespace std;

// Brute force: create new array without duplicates
int rmDupBF(vector<int>& arr) {
    vector<int> tmp;
    for (int x : arr) {
        if (tmp.empty() || tmp.back() != x)
            tmp.push_back(x);
    }
    arr = tmp;
    return arr.size();
}

// Optimized: two pointers to overwrite duplicates in place
int rmDupOpt(vector<int>& arr) {
    if (arr.empty()) return 0;
    int idx = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) arr[idx++] = arr[i];
    }
    return idx;
}

int main() {
    vector<int> a = {1, 1, 2, 2, 3};
    cout << "BF length: " << rmDupBF(a) << "\n";
    vector<int> b = {1, 1, 2, 2, 3};
    cout << "Opt length: " << rmDupOpt(b) << "\n";
    return 0;
}

/*
Logic: BF copies unique elements to new array, Opt overwrites in place.  
Time: O(n), Space: BF O(n), Opt O(1).
*/