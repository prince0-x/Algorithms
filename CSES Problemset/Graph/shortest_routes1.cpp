#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    dist.assign(n + 1, LLONG_MAX);

    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dv, v] = pq.top();
        pq.pop();
        if (dv > dist[v]) continue;

        for (auto [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
