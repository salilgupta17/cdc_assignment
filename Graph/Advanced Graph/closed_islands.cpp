#include <bits/stdc++.h>
using namespace std;

bool dfsClosedIsland(vector<vector<int>>& grid, int r, int c, int m, int n) {
    if (r < 0 || c < 0 || r >= m || c >= n) return false; // touches boundary
    if (grid[r][c] == 1) return true; // water cell, considered closed

    grid[r][c] = 1; // mark visited land

    bool up = dfsClosedIsland(grid, r - 1, c, m, n);
    bool down = dfsClosedIsland(grid, r + 1, c, m, n);
    bool left = dfsClosedIsland(grid, r, c - 1, m, n);
    bool right = dfsClosedIsland(grid, r, c + 1, m, n);

    // island is closed only if all directions return true
    return up && down && left && right;
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && dfsClosedIsland(grid, i, j, m, n))
                count++;
        }
    }
    return count;
}

/*
Logic:
- DFS traverses each land region.
- A region is "closed" if DFS doesn't reach grid boundaries.
Time Complexity: O(m × n)

In a grid with 0 = land and 1 = water, a closed island is a land region 
completely surrounded by water.
*/