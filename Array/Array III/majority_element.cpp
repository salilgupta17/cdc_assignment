#include <bits/stdc++.h>
using namespace std;

// Brute force: count frequencies and find majority
int majBF(const vector<int>& arr) {
    unordered_map<int,int> freq;
    int res = -1, maxC = 0;
    for (int x : arr) freq[x]++;
    for (auto& p : freq) {
        if (p.second > maxC) {
            maxC = p.second;
            res = p.first;
        }
    }
    return res;
}

// Optimized: Moore's Voting algorithm to find candidate
int majOpt(const vector<int>& arr) {
    int count = 0, candidate = -1;
    for (int x : arr) {
        if (count == 0) candidate = x;
        count += (x == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "Majority elem BF: " << majBF(arr) << "\n";
    cout << "Majority elem Opt: " << majOpt(arr) << "\n";
    return 0;
}

/*
Logic Explanation:
Brute force uses a hashmap to tally all elements’ counts, 
which consumes extra space.

Moore's algorithm identifies majority element in O(n) time
and O(1) space by cancelling out minority elements.
*/