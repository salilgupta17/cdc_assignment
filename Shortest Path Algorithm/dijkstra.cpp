#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // {dist, node}
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue;
        for (auto [neigh, w] : adj[node]) {
            if (dist[node] + w < dist[neigh]) {
                dist[neigh] = dist[node] + w;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    return dist; // distances from src to every node
}

/*
Logic:
- Expands nodes in order of increasing distance from the source.
- Updates neighbor distances whenever a shorter path is found.
- No negative edge weights allowed.
Time Complexity: O(E log V)

Algorithm Steps:
1. Set distance of the source to 0, all others to infinity.
2. Use a min-heap to always expand the node with smallest current distance.
3. For each neighbor, update its distance if a shorter path is found.
4. Once a node's shortest distance is finalized (popped from heap), it isn't updated again.

Dijkstra's algorithm finds the shortest distance from a source node to all other nodes 
in a weighted graph (directed or undirected), as long as all edge weights are non-negative.
It uses a priority queue (min-heap) to greedily select the next node with the minimum distance.
*/