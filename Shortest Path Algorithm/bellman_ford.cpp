#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto& e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    // Detect negative cycle
    for (auto& e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            throw runtime_error("Graph contains negative weight cycle");
    }
    return dist;
}

/*
Logic:
- Iteratively "relaxes" all edges V - 1 times.
- Handles negative weights, can detect negative cycles.
Time Complexity: O(VE)

Algorithm Steps:
1. Initialize distances (0 for source, infinity for others).
2. Repeat V-1 times: for each edge, update its endpoint's distance if a shorter path is found.
3. After V-1 relaxations, check all edges again; if further improvement, negative cycle exists.

Bellman-Ford finds single-source shortest paths in a weighted directed graph and can 
handle negative weights. It is slower than Dijkstra (O(VE)), but crucial for graphs 
with negative edges. Also, it detects negative cycles — if found, shortest paths 
aren't well-defined.
*/