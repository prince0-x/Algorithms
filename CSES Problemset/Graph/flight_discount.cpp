#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long INF = 1e18;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<vector<int>> dist(n+1, vector<int>(2, INF));
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<>
    > pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while(!pq.empty()) {
        auto [cost, u, used] = pq.top();
        pq.pop();
        if(cost > dist[u][used]) continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v][used] > cost + w) {
                dist[v][used] = cost + w;
                pq.push({dist[v][used], v, used});
            }
            if(used == 0) {
                if(dist[v][1] > cost + w/2) {
                    dist[v][1] = cost + w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << endl;
}
