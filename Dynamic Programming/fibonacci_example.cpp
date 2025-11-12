#include <bits/stdc++.h>
using namespace std;

// ===== Memoization (Top-down) =====
unordered_map<int, int> memo;

int fib_memo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib_memo(n-1) + fib_memo(n-2);
}

/*
Memoization Approach:
- Recursive function with caching
- Start from fib(n) and break down
- Cache stores computed values
- Time: O(n) - each subproblem computed once
- Space: O(n) for cache + O(n) for call stack

Execution Flow for fib_memo(5):
fib(5) → fib(4) + fib(3)
  fib(4) → fib(3) + fib(2)
    fib(3) → fib(2) + fib(1) = 1 + 1 = 2 [cached]
    fib(2) → fib(1) + fib(0) = 1 + 0 = 1 [cached]
  fib(4) = 2 + 1 = 3 [cached]
  fib(3) [retrieved from cache] = 2
fib(5) = 3 + 2 = 5

Notice: fib(3) and fib(2) computed once and reused
*/

// ===== Tabulation (Bottom-up) =====
int fib_tab(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1);
    dp[0] = 0; 
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

/*
Tabulation Approach:
- Iterative approach starting from base cases
- Build up from fib(0), fib(1) to fib(n)
- No recursion, uses array
- Time: O(n) - single pass through array
- Space: O(n) for dp array only

Execution Flow for fib_tab(5):
dp[0] = 0
dp[1] = 1
dp[2] = dp[1] + dp[0] = 1 + 0 = 1
dp[3] = dp[2] + dp[1] = 1 + 1 = 2
dp[4] = dp[3] + dp[2] = 2 + 1 = 3
dp[5] = dp[4] + dp[3] = 3 + 2 = 5

Clear bottom-up progression, no redundant computation
*/

// ===== Space Optimized Tabulation =====
int fib_optimized(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/*
Space Optimization:
- Only need previous 2 values, not entire array
- Use two variables instead of array
- Time: O(n)
- Space: O(1) - constant space!

This is often the final optimization step after understanding the DP pattern.
Many DP problems can be space-optimized this way if only a few previous states are needed.
*/

// ===== Comparison Example =====
int main() {
    int n = 10;
    
    // Memoization
    memo.clear();
    cout << "Fibonacci(" << n << ") using Memoization: " << fib_memo(n) << endl;
    
    // Tabulation
    cout << "Fibonacci(" << n << ") using Tabulation: " << fib_tab(n) << endl;
    
    // Optimized
    cout << "Fibonacci(" << n << ") using Optimized: " << fib_optimized(n) << endl;
    
    return 0;
}

/*
===== Performance Comparison =====

Naive Recursion (without DP):
- Time: O(2^n) - exponential
- Space: O(n) - recursion depth
- Recomputes same values many times

Memoization:
- Time: O(n) - each state computed once
- Space: O(n) cache + O(n) stack = O(n)
- Computes only needed states
- Easy to code from recursion

Tabulation:
- Time: O(n) - single iteration
- Space: O(n) for array
- Computes all states
- Slightly faster (no function calls)

Space Optimized:
- Time: O(n)
- Space: O(1)
- Best space complexity
- Requires understanding of dependency pattern

===== Key Takeaways =====

1. DP dramatically improves time complexity: O(2^n) → O(n)
2. Memoization is easier to code but uses more space
3. Tabulation is faster and allows space optimization
4. Choose approach based on problem and constraints
5. Space optimization is possible when only few previous states needed
*/