#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v;
    int capacity;
    int rev;
};

class MaxFlow {
public:
    int n;
    vector<vector<Edge>> adj;

    MaxFlow(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v, int cap) {
        Edge a = {v, cap, (int)adj[v].size()};
        Edge b = {u, 0,   (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    int bfs(int s, int t, vector<int>& parent, vector<int>& parentEdge) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;

        q.push(s);
        parent[s] = -2;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < adj[u].size(); i++) {
                Edge &e = adj[u][i];

                if (parent[e.v] == -1 && e.capacity > 0) {
                    parent[e.v] = u;
                    parentEdge[e.v] = i;

                    if (e.v == t)
                        return 1;  // path found

                    q.push(e.v);
                }
            }
        }

        return 0;
    }

    int edmondsKarp(int s, int t) {
        int maxFlow = 0;
        vector<int> parent(n), parentEdge(n);

        while (bfs(s, t, parent, parentEdge)) {
            int flow = INT_MAX;
            int cur = t;

            // Find bottleneck
            while (cur != s) {
                int prev = parent[cur];
                flow = min(flow, adj[prev][parentEdge[cur]].capacity);
                cur = prev;
            }

            // Update residual graph
            cur = t;
            while (cur != s) {
                int prev = parent[cur];
                int edgeIndex = parentEdge[cur];

                adj[prev][edgeIndex].capacity -= flow;
                adj[cur][adj[prev][edgeIndex].rev].capacity += flow;

                cur = prev;
            }

            maxFlow += flow;
        }

        return maxFlow;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    MaxFlow mf(n);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        mf.addEdge(u, v, c);
    }

    int s, t;
    cin >> s >> t;

    cout << mf.edmondsKarp(s, t) << endl;
}
