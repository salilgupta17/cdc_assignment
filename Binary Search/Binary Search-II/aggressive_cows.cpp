#include <bits/stdc++.h>
using namespace std;

// Brute force: try all distances for max min distance between cows
bool canPlaceBF(const vector<int>& stalls, int cows, int dist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < (int)stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count++; last = stalls[i];
            if (count == cows) return true;
        }
    }
    return false;
}

int aggressiveCowsBF(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int maxDist = stalls.back() - stalls.front();
    int ans = 0;
    for (int dist = 1; dist <= maxDist; dist++) {
        if (canPlaceBF(stalls, cows, dist)) ans = dist;
    }
    return ans;
}

// Optimized: binary search on distance
int aggressiveCowsOpt(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int left = 1, right = stalls.back() - stalls.front();
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 1, last = stalls[0];
        for (int i = 1; i < (int)stalls.size(); i++) {
            if (stalls[i] - last >= mid) {
                count++; last = stalls[i];
                if (count >= cows) break;
            }
        }
        if (count >= cows) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1,2,8,4,9};
    cout << "BF: " << aggressiveCowsBF(stalls, 3) << "\n";
    cout << "Opt: " << aggressiveCowsOpt(stalls, 3) << "\n";
    return 0;
}

/*
Logic: BF tries all distances up to max gap O(n * maxDist).  
Opt binary searches distance range O(n log maxDist).
*/