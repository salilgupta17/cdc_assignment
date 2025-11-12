#include <bits/stdc++.h>
using namespace std;

bool hasPathDFS(int src, int dest, vector<vector<int>>& adj, vector<int>& visited) {
    if (src == dest) return true;
    visited[src] = 1;
    for (auto neighbor : adj[src]) {
        if (!visited[neighbor]) {
            if (hasPathDFS(neighbor, dest, adj, visited))
                return true;
        }
    }
    return false;
}

bool hasPath(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> visited(n, 0);
    return hasPathDFS(src, dest, adj, visited);
}

/*
Logic:
- Perform DFS from source vertex.
- If destination is reached, return true.
- Otherwise, recursively explore neighbors.
Time complexity: O(V + E)

This problem checks if there exists a path between a source and destination vertex in a graph. 
It can be solved using DFS or BFS traversal.
*/