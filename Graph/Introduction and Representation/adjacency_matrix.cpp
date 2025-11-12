#include <bits/stdc++.h>
using namespace std;

// Example: Undirected graph with 4 vertices (A,B,C,D) mapped to 0..3
// Edges: (A,B), (A,C), (B,D)
int main() {
    int n = 4; // number of vertices
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // add edges (undirected)
    adj[0][1] = adj[1][0] = 1; // A-B
    adj[0][2] = adj[2][0] = 1; // A-C
    adj[1][3] = adj[3][1] = 1; // B-D

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << adj[i][j] << " ";
        cout << '\n';
    }

    // Example: check edge existence in O(1)
    cout << "\nEdge (A,D) exists? " << (adj[0][3] ? "Yes" : "No") << '\n';
    cout << "Edge (A,B) exists? " << (adj[0][1] ? "Yes" : "No") << '\n';

    return 0;
}
