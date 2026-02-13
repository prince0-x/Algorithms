#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }
    bool isPath = true;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] > 2) {
            isPath = false;
            break;
        }
    }

    if (isPath) {
        cout << -1 << "\n";
        return;
    }
    int nodeb = -1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] > 2) {
            nodeb = max(i,nodeb);
            break;
        }
    }//nbrs of b
    int nodea = adj[nodeb][1];
    int nodec = adj[nodea][0];
    cout << nodea << " " << nodeb << " " << nodec << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
