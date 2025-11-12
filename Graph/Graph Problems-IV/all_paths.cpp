#include <bits/stdc++.h>
using namespace std;

void printAllPathsDFS(int src, int dest, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {
    visited[src] = 1;
    path.push_back(src);

    if (src == dest) {
        for (int node : path) cout << node << " ";
        cout << endl;
    } else {
        for (int neighbor : adj[src]) {
            if (!visited[neighbor])
                printAllPathsDFS(neighbor, dest, adj, visited, path);
        }
    }

    path.pop_back();
    visited[src] = 0;
}

void printAllPaths(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> visited(n, 0);
    vector<int> path;
    printAllPathsDFS(src, dest, adj, visited, path);
}

/*
Logic:
- Use recursive DFS to explore all paths from source to destination.
- Track nodes in current path.
- Backtrack after exploring a branch to explore others.
Time complexity: O(V + E) per path.

This uses backtracking to explore all possible paths between two vertices.
*/