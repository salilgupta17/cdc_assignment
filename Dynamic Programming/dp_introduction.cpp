/*
===== Introduction to Dynamic Programming =====

Dynamic Programming (DP) is a technique to solve problems by breaking them into 
overlapping subproblems, storing intermediate results to avoid redundant calculations, 
and building the solution using these stored results.

===== Prerequisites =====

1. Optimal Substructure:
   - Solution to a problem can be composed from optimal solutions to its subproblems
   - If an optimal solution contains optimal solutions to subproblems
   - Example: Shortest path problem - shortest path from A to C through B 
     = shortest(A to B) + shortest(B to C)

2. Overlapping Subproblems:
   - Same subproblem appears and is solved multiple times
   - Without DP, we recalculate the same values repeatedly
   - Example: Fibonacci - fib(5) calls fib(3) and fib(4), both call fib(3) again
   - DP stores computed results to avoid redundant work

===== Core Approaches =====

1. Memoization (Top-down):
   - Use recursion
   - Cache results of subproblems as they're computed
   - Store in hash map or array
   - Check cache before computing
   - Natural recursive structure

2. Tabulation (Bottom-up):
   - Build results iteratively from the smallest subproblems
   - Store results in a DP table (array)
   - Fill table systematically
   - No recursion overhead
   - Iterative approach

===== When to Use Dynamic Programming =====

Use DP when problem has:
✓ Optimal substructure
✓ Overlapping subproblems
✓ Optimization (maximize/minimize)
✓ Counting (number of ways)
✓ Decision making (yes/no)

Common DP Problem Patterns:
- Fibonacci-like sequences
- Climbing stairs variants
- Grid path problems
- Knapsack problems
- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
- Edit Distance
- Coin Change
- Matrix Chain Multiplication
- Partition problems

===== Benefits of Dynamic Programming =====

1. Avoids Redundant Computation:
   - Exponential → Polynomial time complexity
   - Example: Fibonacci O(2^n) → O(n)

2. Systematic Approach:
   - Clear structure to solve optimization problems
   - Bottom-up or top-down strategy

3. Optimal Solutions:
   - Guarantees optimal solution when conditions are met
   - Mathematically provable correctness

===== DP vs Other Techniques =====

DP vs Greedy:
- Greedy: Makes locally optimal choice at each step
- DP: Considers all possibilities, guarantees global optimum
- Greedy is faster but doesn't always work

DP vs Divide & Conquer:
- D&C: Subproblems are independent (no overlap)
- DP: Subproblems overlap (reuse solutions)
- Example: Merge Sort (D&C) vs Fibonacci (DP)

===== Steps to Solve DP Problems =====

1. Identify if it's a DP problem (check prerequisites)
2. Define state (what information do we need to track?)
3. Formulate recurrence relation (how to compute current state from previous?)
4. Identify base cases
5. Decide: Memoization or Tabulation
6. Implement the solution
7. Optimize space if possible (rolling array, etc.)
*/