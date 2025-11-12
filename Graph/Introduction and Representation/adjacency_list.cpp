#include <bits/stdc++.h>
using namespace std;

// Example: Undirected graph with 4 vertices (A,B,C,D) mapped to 0..3
// Edges: (A,B), (A,C), (B,D)
int main() {
    int n = 4; // number of vertices
    vector<vector<int>> adj(n);

    // add edges (undirected)
    adj[0] = {1, 2}; // A -> B, C
    adj[1] = {0, 3}; // B -> A, D
    adj[2] = {0};    // C -> A
    adj[3] = {1};    // D -> B

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << char('A' + i) << " -> ";
        for (int v : adj[i]) cout << char('A' + v) << " ";
        cout << '\n';
    }

    // iterate neighbors of A
    cout << "\nNeighbors of A: ";
    for (int v : adj[0]) cout << char('A' + v) << " ";
    cout << '\n';

    return 0;
}
