#include <bits/stdc++.h>
using namespace std;

void dfsProvince(int node, vector<vector<int>>& isConnected, vector<int>& visited, int n) {
    visited[node] = 1;
    for (int j = 0; j < n; j++) {
        if (isConnected[node][j] && !visited[j]) {
            dfsProvince(j, isConnected, visited, n);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            dfsProvince(i, isConnected, visited, n);
        }
    }
    return provinces;
}

/*
Logic:
- Treat adjacency matrix as graph.
- Each DFS traversal explores all directly or indirectly connected cities.
- Count total connected components.
Time Complexity: O(n²)

A province is a group of directly or indirectly connected cities represented as a graph 
— essentially, counting connected components in an adjacency matrix.
*/