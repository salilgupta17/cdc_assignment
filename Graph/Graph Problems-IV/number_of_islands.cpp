#include <bits/stdc++.h>
using namespace std;

void dfsIsland(int r, int c, vector<vector<char>>& grid, int rows, int cols) {
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
        return;

    grid[r][c] = '0'; // mark cell visited

    // Explore 4 directions
    dfsIsland(r - 1, c, grid, rows, cols);
    dfsIsland(r + 1, c, grid, rows, cols);
    dfsIsland(r, c - 1, grid, rows, cols);
    dfsIsland(r, c + 1, grid, rows, cols);
}

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size(), count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfsIsland(i, j, grid, rows, cols);
            }
        }
    }
    return count;
}

/*
Logic:
- Treat each grid cell as a graph node.
- Whenever an unvisited '1' (land) is found, start DFS to mark the full island as visited.
- Each new DFS call corresponds to one new island.
Time complexity: O(R*C)

This is a classic grid-based graph problem similar to finding connected components.
Each "1" (land) represents a node, and adjacent (up, down, left, right) land cells form one island.
*/