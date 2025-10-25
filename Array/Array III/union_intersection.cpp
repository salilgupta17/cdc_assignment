#include <bits/stdc++.h>
using namespace std;

// Brute force: merge both arrays, sort and remove duplicates for union;
// nested loop to find common elements for intersection
pair<vector<int>, vector<int>> uniInterBF(const vector<int>& a, const vector<int>& b) {
    vector<int> uni, inter;
    vector<int> merged(a.begin(), a.end());
    merged.insert(merged.end(), b.begin(), b.end());
    sort(merged.begin(), merged.end());
    for (int i = 0; i < (int)merged.size(); i++)
        if (i == 0 || merged[i] != merged[i-1]) uni.push_back(merged[i]);
    for (int x : a) {
        for (int y : b) {
            if (x == y && (inter.empty() || inter.back() != x)) {
                inter.push_back(x);
                break;
            }
        }
    }
    return {uni, inter};
}

// Optimized: two pointer approach to get union and intersection in O(n + m)
pair<vector<int>, vector<int>> uniInterOpt(const vector<int>& a, const vector<int>& b) {
    vector<int> uni, inter;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] == b[j]) {
            if (uni.empty() || uni.back() != a[i]) uni.push_back(a[i]);
            if (inter.empty() || inter.back() != a[i]) inter.push_back(a[i]);
            i++; j++;
        }
        else if (a[i] < b[j]) {
            if (uni.empty() || uni.back() != a[i]) uni.push_back(a[i]);
            i++;
        } else {
            if (uni.empty() || uni.back() != b[j]) uni.push_back(b[j]);
            j++;
        }
    }
    while (i < (int)a.size()) {
        if (uni.empty() || uni.back() != a[i]) uni.push_back(a[i]);
        i++;
    }
    while (j < (int)b.size()) {
        if (uni.empty() || uni.back() != b[j]) uni.push_back(b[j]);
        j++;
    }
    return {uni, inter};
}

int main() {
    vector<int> a = {1, 2, 4, 5, 6};
    vector<int> b = {2, 3, 5, 7};
    auto resBF = uniInterBF(a,b);
    auto resOpt = uniInterOpt(a,b);

    cout << "Union BF: ";
    for (int x : resBF.first) cout << x << " ";
    cout << "\nIntersection BF: ";
    for (int x : resBF.second) cout << x << " ";

    cout << "\nUnion Opt: ";
    for (int x : resOpt.first) cout << x << " ";
    cout << "\nIntersection Opt: ";
    for (int x : resOpt.second) cout << x << " ";

    return 0;
}

/*
Logic Explanation:
Brute force merges then sorts combined arrays to find union, 
and uses nested loops to find common elements for intersection,
resulting in high time complexity.

Optimized method uses two pointers on sorted arrays simultaneously, 
adding unique elements to union and shared elements to intersection,
achieving linear time complexity of O(n + m).
*/