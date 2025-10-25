#include <bits/stdc++.h>
using namespace std;

// Brute force: check all buy/sell pairs
int maxProfitBF(const vector<int>& prices) {
    int maxP = 0, n = prices.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            maxP = max(maxP, prices[j] - prices[i]);
        }
    }
    return maxP;
}

// Optimized: track min price so far and max profit
int maxProfitOpt(const vector<int>& prices) {
    int minP = INT_MAX, maxP = 0;
    for(int p : prices) {
        if(p < minP) minP = p;
        else maxP = max(maxP, p - minP);
    }
    return maxP;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << "BF: " << maxProfitBF(prices) << "\n";
    cout << "Opt: " << maxProfitOpt(prices) << "\n";
    return 0;
}

/*
Logic: BF tries all pairs O(n^2),  
Opt computes profit in one pass O(n).  
Space: O(1).
*/