#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, int n, vector<vector<int>>& adj) {
    vector<int> visited(n, 0);
    vector<int> result;
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main() {
    // Example usage
    int n = 6; // Number of vertices
    vector<vector<int>> adj(n);
    
    // Add edges (Example graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2, 5};
    adj[5] = {4};

    // Run BFS starting from vertex 0
    vector<int> bfsOrder = bfs(0, n, adj);
    
    cout << "BFS traversal starting from vertex 0:" << endl;
    for (int node : bfsOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}