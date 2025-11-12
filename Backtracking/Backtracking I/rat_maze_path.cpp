#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMaze(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    // Base case: reached destination
    if (x == n - 1 && y == n - 1) return true;

    // Mark current cell as visited
    visited[x][y] = 1;

    // Possible movements: Down, Left, Right, Up
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};

    // Try all possible directions
    for (int k = 0; k < 4; k++) {
        int newX = x + dx[k];
        int newY = y + dy[k];
        if (isSafe(newX, newY, n, maze, visited)) {
            if (solveMaze(newX, newY, n, maze, visited)) 
                return true;
        }
    }

    // If no path found, backtrack
    visited[x][y] = 0;
    return false;
}

/*
Logic: Classic backtracking to check if path exists from start to end
1. Start from (0,0) and try to reach (n-1,n-1)
2. For each cell, try all possible directions (Down, Left, Right, Up)
3. If path exists, mark cells as visited
4. If no path exists, backtrack by unmarking cells

Time Complexity: O(2^(n²)) - each cell has 2 choices (visit/don't visit)
Space Complexity: O(n²) for visited array and recursion stack
*/

int main() {
    // Test Case 1
    cout << "Test Case 1:" << endl;
    vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int n1 = maze1.size();
    vector<vector<int>> visited1(n1, vector<int>(n1, 0));
    
    cout << "Maze:" << endl;
    for (const auto& row : maze1) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
    
    bool pathExists1 = solveMaze(0, 0, n1, maze1, visited1);
    cout << "Path exists: " << (pathExists1 ? "Yes" : "No") << endl;
    
    // Test Case 2
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> maze2 = {
        {1, 0},
        {0, 1}
    };
    int n2 = maze2.size();
    vector<vector<int>> visited2(n2, vector<int>(n2, 0));
    
    cout << "Maze:" << endl;
    for (const auto& row : maze2) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
    
    bool pathExists2 = solveMaze(0, 0, n2, maze2, visited2);
    cout << "Path exists: " << (pathExists2 ? "Yes" : "No") << endl;
    
    return 0;
}