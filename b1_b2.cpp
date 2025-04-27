/*
You are given a directed graph G=(V,E) on which each edge (u,v) ∈ E has an an associated value r(u.v),
which is a real number in the range 0 ≤ r(u,v) ≤ 1 that represents the reliability of a communication
channel from vertex u to vertex v. We interpret r(u,v) as the probability that the channel from u to v will
not fail and we assume these probabilities are independent. Give an efficient algorithm to find the most
reliable path between two given vertices.
Input: The first line of the input file will contain the number of vertices n (≤ 1000) and the number of
edges m (≤ 10000) followed by m lines each containing origin u, end v and r(u,v) of an edge of the
directed graph. The last line will contain a source vertex s and a destination vertex d.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

double ans(vector<vector<vector<double>>>& adj, int N, int s, int d) {
    vector<double> reliability(N + 1, 0.0);
    reliability[s] = 1.0;
    priority_queue<vector<double>> pq;
    pq.push({1.0, (double)s}); // {reliability, node}

    while (!pq.empty()) {
        double rel = pq.top()[0];
        int u = (int)pq.top()[1];
        pq.pop();

        if (rel < reliability[u]) continue; // outdated entry

        for (auto child : adj[u]) {
            int v = (int)child[0];
            double r = child[1];
            if (reliability[v] < reliability[u] * r) {
                reliability[v] = reliability[u] * r;
                pq.push({reliability[v], (double)v});
            }
        }
    }

    return reliability[d];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<vector<double>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        double r;
        cin >> u >> v >> r;
        adj[u].push_back({(double)v, r});
    }
    int s, d;
    cin >> s >> d;

    cout.precision(6);
    cout << fixed << ans(adj, N, s, d) << endl;

    return 0;
}
