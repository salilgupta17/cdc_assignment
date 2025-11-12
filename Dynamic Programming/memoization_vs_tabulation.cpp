/*
===== Differences: Memoization vs Tabulation =====

Feature              | Memoization                    | Tabulation
---------------------|--------------------------------|--------------------------------
Approach             | Top-down (recursive)           | Bottom-up (iterative)
Table Fills          | On-demand (lazily)             | All subproblems, by order
Code                 | Simple from recursion          | Requires careful ordering
Speed                | Slower (recursion cost)        | Faster (iteration)
Subproblems          | Only required are solved       | All possible are solved
Space                | DP table + call stack          | DP table only
Debugging            | Harder (recursion)             | Easier
Stack Overflow       | Possible for deep recursion    | No risk
Initial State        | Not all states initialized     | All states initialized
Natural to Code      | Very natural (recursive)       | Requires thinking bottom-up

===== Memoization (Top-Down) =====

Characteristics:
- Start from the original problem
- Break into subproblems recursively
- Cache results as you compute them
- Return cached value if already computed
- Natural extension of naive recursion

Advantages:
✓ Intuitive - mirrors recursive problem definition
✓ Only computes needed subproblems
✓ Easy to convert from recursive solution
✓ Good for sparse problem spaces

Disadvantages:
✗ Function call overhead
✗ Risk of stack overflow for deep recursion
✗ May use more memory (call stack + cache)
✗ Harder to debug

When to Use:
- Problem has natural recursive structure
- Not all subproblems need to be solved
- Easy to express recursively
- Depth of recursion is manageable

===== Tabulation (Bottom-Up) =====

Characteristics:
- Start from base cases
- Build up to final solution
- Fill table iteratively
- No recursion involved
- Systematic filling order

Advantages:
✓ No function call overhead - faster
✓ No stack overflow risk
✓ Better space optimization possible
✓ Easier to debug (step through loop)
✓ Better cache locality

Disadvantages:
✗ Must solve all subproblems (even unnecessary ones)
✗ Requires figuring out correct filling order
✗ Less intuitive than recursion
✗ Harder to code initially

When to Use:
- All subproblems need to be solved anyway
- Performance is critical
- Deep recursion would cause stack overflow
- Clear iterative order exists
- Space optimization is important

===== Choosing Between Them =====

Choose Memoization when:
- Problem is naturally recursive
- Not all states are reachable
- Quick implementation needed
- Recursion depth is acceptable

Choose Tabulation when:
- Performance is critical
- All states need computation
- Avoiding stack overflow
- Space optimization matters
- Production-level code

Many problems can use both approaches - choose based on:
- Problem constraints
- Performance requirements
- Code readability preferences
- Memory limitations

===== Conversion Tips =====

Memoization → Tabulation:
1. Identify all states and their dependencies
2. Determine order to fill states (topological order)
3. Initialize base cases
4. Iterate through states in correct order
5. Use recurrence relation to fill each state

Tabulation → Memoization:
1. Write recursive relation
2. Add memoization cache (map or array)
3. Check cache before computing
4. Store result before returning
5. Handle base cases
*/