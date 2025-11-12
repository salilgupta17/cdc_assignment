#include <bits/stdc++.h>
using namespace std;

// ===== Tabulation (Bottom-up) =====
int numSquares_tab(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int sq = 1; sq*sq <= i; sq++)
            dp[i] = min(dp[i], dp[i - sq*sq] + 1);
    return dp[n];
}

/*
===== Perfect Squares =====

Problem Statement:
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer (1, 4, 9, 16, 25, ...).

Examples:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4 (three perfect squares)

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9 (two perfect squares)

Input: n = 1
Output: 1
Explanation: 1 = 1 (one perfect square)

===== Solution Approach =====

State Definition:
- dp[i] = minimum number of perfect squares that sum to i

Recurrence Relation:
- For each number i, try all perfect squares j² where j² ≤ i
- If we use j², we need dp[i - j²] more squares
- dp[i] = min(dp[i], dp[i - j²] + 1) for all valid j

Base Case:
- dp[0] = 0 (zero squares needed to sum to 0)

Algorithm:
1. Initialize dp[0] = 0, all others to infinity
2. For each number i from 1 to n:
   - For each perfect square j² ≤ i:
     - Update dp[i] = min(dp[i], dp[i - j²] + 1)
3. Return dp[n]

===== Step-by-Step Example =====

n = 12

Perfect squares ≤ 12: 1, 4, 9

dp[0] = 0

dp[1]:
- Try 1²=1: dp[1] = min(∞, dp[0]+1) = 1
- Result: 1

dp[2]:
- Try 1²=1: dp[2] = min(∞, dp[1]+1) = 2
- Result: 2

dp[3]:
- Try 1²=1: dp[3] = min(∞, dp[2]+1) = 3
- Result: 3

dp[4]:
- Try 1²=1: dp[4] = min(∞, dp[3]+1) = 4
- Try 2²=4: dp[4] = min(4, dp[0]+1) = 1
- Result: 1 (using 4)

dp[5]:
- Try 1²=1: dp[5] = min(∞, dp[4]+1) = 2
- Try 2²=4: dp[5] = min(2, dp[1]+1) = 2
- Result: 2 (4+1)

...continuing...

dp[12]:
- Try 1²=1: dp[12] = min(∞, dp[11]+1) = 4
- Try 2²=4: dp[12] = min(4, dp[8]+1) = 3
- Try 3²=9: dp[12] = min(3, dp[3]+1) = 3
- Result: 3 (4+4+4)

===== Complexity Analysis =====

Time Complexity: O(n * √n)
- Outer loop: n iterations
- Inner loop: √n iterations (checking all perfect squares ≤ i)

Space Complexity: O(n)
- DP array of size n+1

===== Optimization Techniques =====

1. Mathematical Optimization (Lagrange's Four Square Theorem):
   - Every positive integer can be represented as sum of at most 4 perfect squares
   - Can check if n is perfect square → return 1
   - Can check if n = a² + b² → return 2
   - Can check if n = a² + b² + c² → return 3
   - Otherwise → return 4

2. BFS Approach:
   - Treat as shortest path problem
   - Each perfect square is an edge
   - Find shortest path from 0 to n

===== Usage Example =====

int main() {
    vector<int> test_cases = {1, 12, 13, 7, 25, 100};
    
    for (int n : test_cases) {
        int result = numSquares_tab(n);
        cout << "numSquares(" << n << ") = " << result << endl;
    }
    
    return 0;
}

Output:
numSquares(1) = 1    → 1
numSquares(12) = 3   → 4+4+4
numSquares(13) = 2   → 4+9
numSquares(7) = 4    → 1+1+1+4
numSquares(25) = 1   → 25
numSquares(100) = 1  → 100

===== Pattern Recognition =====

Numbers requiring:
- 1 square: 1, 4, 9, 16, 25, 36, 49, ... (perfect squares)
- 2 squares: 2, 5, 8, 10, 13, 17, 18, ... (sum of 2 squares)
- 3 squares: 3, 6, 11, 12, 15, 19, 21, ... 
- 4 squares: 7, 15, 23, 28, 31, ... (by Four Square Theorem)

===== Related Problems =====

1. Coin Change (similar DP pattern)
2. Minimum Cost For Tickets
3. Perfect Squares II (count ways instead of minimum)
4. Partition Equal Subset Sum

===== Key Insights =====

1. This is an unbounded knapsack variant
2. We can use each perfect square multiple times
3. Similar to coin change problem where coins are perfect squares
4. DP builds solution from smaller subproblems
5. Greedy approach doesn't work (e.g., 12: greedy would give 9+1+1+1=4, but optimal is 4+4+4=3)

===== Common Mistakes =====

1. Not initializing dp values to infinity
2. Forgetting that squares can be reused
3. Wrong loop bounds (sq*sq <= i, not sq <= i)
4. Not considering all perfect squares up to i
*/