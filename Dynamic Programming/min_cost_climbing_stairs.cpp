#include <bits/stdc++.h>
using namespace std;

// ===== Tabulation (Bottom-up) =====
int minCostClimbingStairs_tab(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    return dp[n];
}

// ===== Space Optimized =====
int minCostClimbingStairs_optimized(vector<int>& cost) {
    int n = cost.size();
    int prev2 = 0, prev1 = 0;
    for (int i = 2; i <= n; i++) {
        int curr = min(prev1 + cost[i-1], prev2 + cost[i-2]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/*
===== Min Cost Climbing Stairs =====

Problem Statement:
You are given an integer array cost where cost[i] is the cost of the i-th step on a staircase.
Once you pay the cost, you can either climb 1 or 2 steps.
You can start from step 0 or step 1.
Return the minimum cost to reach the top of the floor (beyond the last step).

Examples:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Start at index 1, pay 15, climb 2 steps to reach top

Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Start at index 0, pay costs: 1+1+1+1+1+1 = 6
Path: 0→2→3→4→5→6→7→9→top

===== Solution Approach =====

State Definition:
- dp[i] = minimum cost to reach step i
- Final answer is dp[n] (reaching beyond last step)

Recurrence Relation:
- To reach step i, you can come from step (i-1) or (i-2)
- If coming from (i-1): cost is dp[i-1] + cost[i-1]
- If coming from (i-2): cost is dp[i-2] + cost[i-2]
- dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])

Base Cases:
- dp[0] = 0 (can start at step 0 for free)
- dp[1] = 0 (can start at step 1 for free)

Key Insight:
- You pay the cost WHEN you step on that stair, not when leaving it
- You can start from index 0 or 1 without paying initially
- Need to reach position n (beyond last step), not n-1

===== Complexity Analysis =====

Tabulation:
- Time: O(n) - single loop through array
- Space: O(n) for dp array

Space Optimized:
- Time: O(n)
- Space: O(1) - only two variables needed

===== Step-by-Step Example =====

cost = [10, 15, 20]

Initial state:
dp[0] = 0 (start here for free)
dp[1] = 0 (or start here for free)

Step 2 (index 2):
dp[2] = min(dp[1] + cost[1], dp[0] + cost[0])
      = min(0 + 15, 0 + 10)
      = 10

Step 3 (top, beyond array):
dp[3] = min(dp[2] + cost[2], dp[1] + cost[1])
      = min(10 + 20, 0 + 15)
      = 15

Answer: 15

===== Usage Example =====

int main() {
    vector<int> cost1 = {10, 15, 20};
    cout << "Min cost: " << minCostClimbingStairs_tab(cost1) << endl;
    
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Min cost: " << minCostClimbingStairs_tab(cost2) << endl;
    
    return 0;
}

===== Common Mistakes =====

1. Confusing when to pay the cost (pay when stepping ON, not leaving)
2. Forgetting you can start from either step 0 or 1
3. Not reaching position n (beyond last step)
4. Wrong indexing in the recurrence relation

===== Related Problems =====

1. Climbing Stairs (count ways)
2. House Robber (can't use adjacent)
3. Jump Game (variable step sizes)
4. Minimum Path Sum (2D grid version)
*/