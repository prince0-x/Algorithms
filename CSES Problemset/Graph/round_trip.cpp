#include <bits/stdc++.h>
using namespace std;

int n, m, startNode = -1, endNode = -1;
vector<vector<int>> adj;
vector<int> vis, parent;

bool dfs(int u, int p) {
    vis[u] = 1;
    parent[u] = p;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) {
            if (dfs(v, u)) return true;
        } else {
            startNode = v;
            endNode = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) {
            vector<int> cycle;
            for (int v = endNode; v != startNode; v = parent[v]){
                  cycle.push_back(v);
            }
            cycle.push_back(startNode);
            cycle.push_back(endNode);
            reverse(cycle.begin(), cycle.end());

            cout << cycle.size() << "\n";
            for (int v : cycle) cout << v << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
