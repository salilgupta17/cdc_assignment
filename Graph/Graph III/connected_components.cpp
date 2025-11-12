#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& component) {
    visited[node] = 1;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
}

vector<vector<int>> findConnectedComponents(int n, vector<vector<int>>& adj) {
    vector<int> visited(n, 0);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            components.push_back(component);
        }
    }
    return components;
}

/*
Logic:
- Iterate over all vertices.
- For each unvisited vertex, run a DFS/BFS to mark its connected component.
- Each DFS traversal gives one distinct connected component.
Time Complexity: O(V + E)

A connected component is a subgraph in which all vertices are reachable from each other, 
and no additional vertices from the rest of the graph are connected to it.
In an undirected graph, this can be efficiently found using Depth First Search (DFS) or 
Breadth First Search (BFS).
*/