#include <bits/stdc++.h>
using namespace std;

// Given piles and h hours, find min eating speed k so Koko can finish on time

// Brute force: check all k from 1 to max pile size
int canFinishBF(const vector<int>& piles, int h, int k) {
    long long hours = 0;
    for(int p : piles) hours += (p + k - 1) / k; // ceil division
    return hours <= h;
}

int minEatingSpeedBF(const vector<int>& piles, int h) {
    int maxPile = *max_element(piles.begin(), piles.end());
    for(int k = 1; k <= maxPile; k++) {
        if(canFinishBF(piles, h, k)) return k;
    }
    return maxPile;
}

// Optimized: binary search for minimum k
int minEatingSpeedOpt(const vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        long long hours = 0;
        for(int p : piles) hours += (p + mid - 1) / mid;
        if (hours <= h) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    vector<int> piles = {3,6,7,11};
    cout << "BF: " << minEatingSpeedBF(piles, 8) << "\n";
    cout << "Opt: " << minEatingSpeedOpt(piles, 8) << "\n";
    return 0;
}

/*
Logic: BF tries all speeds;  
Opt binary searches possible speed range efficiently.  
Time: BF O(n * maxPile), Opt O(n log maxPile)
*/