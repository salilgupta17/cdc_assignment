#include <bits/stdc++.h>
using namespace std;

// ===== Tabulation (Bottom-up) =====
vector<int> countBits_tab(int n) {
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i>>1] + (i&1);
    return dp;
}

/*
===== Counting Bits =====

Problem Statement:
Given an integer n, return an array ans of length n+1 such that for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.

Examples:
Input: n = 5
Output: [0, 1, 1, 2, 1, 2]
Explanation:
0 → 0000 → 0 ones
1 → 0001 → 1 one
2 → 0010 → 1 one
3 → 0011 → 2 ones
4 → 0100 → 1 one
5 → 0101 → 2 ones

Input: n = 2
Output: [0, 1, 1]

===== Solution Approach =====

Key Insight:
- The number of 1's in i is related to i/2 (right shift by 1)
- When we right shift, we lose the least significant bit
- If the lost bit was 1, add 1 to the count of i/2
- If the lost bit was 0, count remains same as i/2

Recurrence Relation:
- dp[i] = dp[i >> 1] + (i & 1)
- i >> 1: right shift i by 1 bit (equivalent to i/2)
- i & 1: check if last bit is 1 (equivalent to i % 2)

Examples:
i = 5 (binary: 101)
- i >> 1 = 2 (binary: 10)
- dp[2] = 1 (one '1' in binary 10)
- i & 1 = 1 (last bit of 101 is 1)
- dp[5] = dp[2] + 1 = 1 + 1 = 2

i = 6 (binary: 110)
- i >> 1 = 3 (binary: 11)
- dp[3] = 2 (two '1's in binary 11)
- i & 1 = 0 (last bit of 110 is 0)
- dp[6] = dp[3] + 0 = 2 + 0 = 2

===== Why This Works =====

Mathematical Proof:
1. Right shifting by 1 removes the rightmost bit
2. The count of 1's in (i >> 1) is almost the answer for i
3. We just need to add back 1 if the removed bit was 1
4. (i & 1) checks if rightmost bit is 1

Pattern Recognition:
Number | Binary | Count | Relation
-------|--------|-------|----------
0      | 0000   | 0     | base
1      | 0001   | 1     | dp[0] + 1
2      | 0010   | 1     | dp[1] + 0
3      | 0011   | 2     | dp[1] + 1
4      | 0100   | 1     | dp[2] + 0
5      | 0101   | 2     | dp[2] + 1
6      | 0110   | 2     | dp[3] + 0
7      | 0111   | 3     | dp[3] + 1

===== Complexity Analysis =====

Time Complexity: O(n)
- Single pass through numbers 0 to n
- Each calculation is O(1)

Space Complexity: O(n)
- Array to store results for 0 to n

===== Alternative Approaches =====

1. Naive Approach: Count bits for each number individually
   Time: O(n * log n) - for each number, count bits
   
2. Using Brian Kernighan's Algorithm:
   dp[i] = dp[i & (i-1)] + 1
   Explanation: i & (i-1) removes the rightmost set bit
   
3. Using Last Set Bit:
   dp[i] = dp[i - (i & -i)] + 1
   Explanation: (i & -i) isolates rightmost set bit

===== Usage Example =====

int main() {
    int n = 5;
    vector<int> result = countBits_tab(n);
    
    cout << "Number of 1's in binary representation:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << " (" << bitset<4>(i) << ") → " << result[i] << " ones" << endl;
    }
    
    return 0;
}

Output:
Number of 1's in binary representation:
0 (0000) → 0 ones
1 (0001) → 1 ones
2 (0010) → 1 ones
3 (0011) → 2 ones
4 (0100) → 1 ones
5 (0101) → 2 ones

===== Applications =====

1. Hamming Distance Calculation
2. Population Count in Sets
3. Optimization in Bit Manipulation Problems
4. Cryptography and Error Detection
5. Computer Graphics (color manipulation)

===== Key Takeaways =====

1. DP can be applied to bit manipulation problems
2. Understanding bit operations is crucial (>>, &)
3. Current state often depends on previous simpler state
4. Extremely efficient: O(n) time, O(n) space
5. This is a classic example of using DP with bit operations
*/