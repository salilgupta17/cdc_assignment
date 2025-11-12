#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, node, adj, visited)) return true;
        } 
        else if (neighbor != parent) {
            return true; // Found a back edge → cycle exists
        }
    }
    return false;
}

bool hasCycleUndirected(int n, vector<vector<int>>& adj) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

/*
Logic:
- Use DFS tracking parent node.
- If a visited neighbor reappears (not parent), a cycle exists.
Time: O(V + E)
*/