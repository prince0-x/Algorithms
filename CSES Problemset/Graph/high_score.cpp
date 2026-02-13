#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<tuple<int,int,int>> edges;
int n, m;
int NEG_INF = LLONG_MIN/4;

signed main() {
    cin >> n >> m;
    edges.reserve(m);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    vector<int> dist(n + 1, NEG_INF);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] == NEG_INF) continue;
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect nodes affected by positive cycles
    vector<int> bad(n + 1, 0);
    for (auto &[u, v, w] : edges) {
        if (dist[u] == NEG_INF) continue;
        if (dist[u] + w > dist[v]) {
            bad[v] = 1;
        }
    }
    bool any = false;
    for (int i = 1; i <= n; i++)
        if (bad[i]) any = true;
    if (!any) {
        cout << dist[n] << "\n";
        return 0;
    }

    // Build a simple adjacency list
    vector<vector<int>> g(n + 1);
    for (auto &[u, v, w] : edges) g[u].push_back(v);

    // BFS/DFS from all bad nodes
    vector<int> vis(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (bad[i]) {
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    if (vis[n]) {
        cout << "-1\n";
        return 0;
    }

    cout << dist[n] << "\n";
    return 0;
}
