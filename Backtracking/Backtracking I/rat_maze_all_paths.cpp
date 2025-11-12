#include <bits/stdc++.h>
using namespace std;

bool isSafeAll(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y]);
}

void findAllPaths(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited, 
                 string path, vector<string>& res) {
    // Base case: reached destination
    if (x == n - 1 && y == n - 1) {
        res.push_back(path);
        return;
    }

    // Mark current cell as visited
    visited[x][y] = 1;

    // Possible movements: Down, Left, Right, Up
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'}; // Direction characters

    // Try all possible directions
    for (int k = 0; k < 4; k++) {
        int newX = x + dx[k];
        int newY = y + dy[k];
        if (isSafeAll(newX, newY, n, maze, visited)) {
            findAllPaths(newX, newY, n, maze, visited, path + dir[k], res);
        }
    }

    // Backtrack
    visited[x][y] = 0;
}

/*
Logic: Use backtracking to find all possible paths
1. Start from (0,0) and try to reach (n-1,n-1)
2. For each cell, try all directions (D, L, R, U)
3. Keep track of path using string of directions
4. Store each valid path when destination is reached
5. Backtrack to find all possible paths

Time Complexity: O(4^(n²)) - 4 choices for each cell
Space Complexity: O(n²) for visited array + O(L) for path string
where L is length of longest path
*/

// Helper function to print maze
void printMaze(vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
}

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
    vector<string> paths1;
    
    cout << "Maze:" << endl;
    printMaze(maze1);
    
    findAllPaths(0, 0, n1, maze1, visited1, "", paths1);
    cout << "All possible paths:" << endl;
    if (paths1.empty()) {
        cout << "No path exists" << endl;
    } else {
        for (const string& path : paths1) {
            cout << path << endl;
        }
    }
    
    // Test Case 2
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> maze2 = {
        {1, 1},
        {1, 1}
    };
    int n2 = maze2.size();
    vector<vector<int>> visited2(n2, vector<int>(n2, 0));
    vector<string> paths2;
    
    cout << "Maze:" << endl;
    printMaze(maze2);
    
    findAllPaths(0, 0, n2, maze2, visited2, "", paths2);
    cout << "All possible paths:" << endl;
    for (const string& path : paths2) {
        cout << path << endl;
    }
    
    return 0;
}