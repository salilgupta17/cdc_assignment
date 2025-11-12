#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[node] = 1;
    result.push_back(node);
    for (auto& neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfs(int start, int n, vector<vector<int>>& adj) {
    vector<int> visited(n, 0);
    vector<int> result;
    dfsUtil(start, adj, visited, result);
    return result;
}

int main() {
    // Example usage
    int n = 6; // Number of vertices
    vector<vector<int>> adj(n);
    
    // Add edges (Example graph - same as BFS for comparison)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2, 5};
    adj[5] = {4};

    // Run DFS starting from vertex 0
    vector<int> dfsOrder = dfs(0, n, adj);
    
    cout << "DFS traversal starting from vertex 0:" << endl;
    for (int node : dfsOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}