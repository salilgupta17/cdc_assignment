#include <bits/stdc++.h>
using namespace std;

// Brute force: for each day scan backward to count span
vector<int> stockSpanBF(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n, 1);
    for (int i=0; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (prices[j] <= prices[i]) span[i]++;
            else break;
        }
    }
    return span;
}

// Optimized: use stack to store indices, calculate span in one pass
vector<int> stockSpanOpt(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s;
    for (int i=0; i<n; i++) {
        while (!s.empty() && prices[s.top()] <= prices[i]) s.pop();
        span[i] = s.empty() ? i+1 : i - s.top();
        s.push(i);
    }
    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    auto res = stockSpanOpt(prices);
    cout << "Span: "; for (int x: res) cout << x << " "; cout << "\n";
    return 0;
}

/*
Logic: BF checks backwards per day O(n^2).  
Opt stack finds last greater price for O(n).  
Space: O(n).
*/