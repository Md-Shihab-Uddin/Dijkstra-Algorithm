#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
    int n;
    vector<vector<vector<int>>> adj;

public:
    Graph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
    }

    // Modified Dijkstra: returns distances + parent array
    pair<vector<int>, vector<int>> dijkstra(int src) {
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top()[1];
            pq.pop();

            for (auto &x : adj[u]) {
                int v = x[0];
                int wt = x[1];
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;  // Store the path
                    pq.push({dist[v], v});
                }
            }
        }

        return {dist, parent};
    }

    // Reconstruct path from source to target
    vector<int> getPath(int target, const vector<int>& parent) {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        } 
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int n, m, src;
    cout << "Enter number of nodes, edges, and source vertex: ";
    cin >> n >> m >> src;

    Graph g(n);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt);
    }

    auto [dist, parent] = g.dijkstra(src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << i << " -> ";
        if (dist[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << " | Path: ";
            vector<int> path = g.getPath(i, parent);
            for (int node : path)
                cout << node << " ";
            cout << "\n";
        }
    }

    return 0;
}
