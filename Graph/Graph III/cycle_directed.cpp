#include <bits/stdc++.h>
using namespace std;

bool dfsDirected(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVis) {
    visited[node] = 1;
    pathVis[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsDirected(neighbor, adj, visited, pathVis)) return true;
        } else if (pathVis[neighbor]) {
            return true; // back edge -> cycle exists
        }
    }
    pathVis[node] = 0;
    return false;
}

bool hasCycleDirected(int n, vector<vector<int>>& adj) {
    vector<int> visited(n, 0), pathVis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsDirected(i, adj, visited, pathVis)) return true;
        }
    }
    return false;
}

/*
Logic:
- Track nodes visited in the current DFS recursion stack (pathVis[]).
- If we revisit a node still in recursion path, a cycle is found.
Time: O(V + E)
*/