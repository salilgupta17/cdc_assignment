#include <bits/stdc++.h>
using namespace std;

// ===== Memoization (Top-down) =====
int climbStairs_memo(int n, vector<int>& memo) {
    if (n <= 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = climbStairs_memo(n-1, memo) + climbStairs_memo(n-2, memo);
}

// ===== Tabulation (Bottom-up) =====
int climbStairs_tab(int n) {
    if (n <= 2) return n;
    vector<int> dp(n+1, 0);
    dp[1] = 1; 
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// ===== Space Optimized =====
int climbStairs_optimized(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/*
===== Staircase Problem (Ways to Reach Top) =====

Problem Statement:
You are climbing a staircase with n steps. Each time you can either climb 1 or 2 steps.
In how many distinct ways can you reach the top?

Examples:
Input: n = 2
Output: 2 (1+1, or 2)

Input: n = 3
Output: 3 (1+1+1, 1+2, or 2+1)

Input: n = 4
Output: 5 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2)

===== Solution Approach =====

Recurrence Relation:
- To reach step n, you can come from step (n-1) or step (n-2)
- dp[n] = dp[n-1] + dp[n-2]
- This is the Fibonacci sequence!

Base Cases:
- dp[1] = 1 (one way: take 1 step)
- dp[2] = 2 (two ways: 1+1 or 2)

State Definition:
- dp[i] = number of ways to reach step i

===== Complexity Analysis =====

Memoization:
- Time: O(n) - each state computed once
- Space: O(n) for memo array + O(n) for recursion stack

Tabulation:
- Time: O(n) - single loop
- Space: O(n) for dp array

Space Optimized:
- Time: O(n)
- Space: O(1) - only two variables needed

===== Usage Example =====

int main() {
    int n = 5;
    
    // Memoization
    vector<int> memo(n+1, -1);
    cout << "Ways (Memoization): " << climbStairs_memo(n, memo) << endl;
    
    // Tabulation
    cout << "Ways (Tabulation): " << climbStairs_tab(n) << endl;
    
    // Optimized
    cout << "Ways (Optimized): " << climbStairs_optimized(n) << endl;
    
    return 0;
}

===== Variations =====

1. If you can climb 1, 2, or 3 steps at a time:
   dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

2. If certain steps are broken (can't step on them):
   Skip those steps in the calculation

3. With minimum cost (see Min Cost Climbing Stairs problem)

4. Count ways with exactly k steps:
   Use different DP state tracking step count
*/