#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,long long>>> g(n);
    vector<tuple<int,int,long long>>edges;
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    long long best = INF;
    for(auto &[u, v, w] : edges) {
        vector<long long> dist(n, INF);
        dist[u] = 0;
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;
        pq.push({0, u});
        while(!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if(d > dist[x]) continue;
            for(auto &e : g[x]) {
                int y = e.first;
                long long wt = e.second;
                if((x == u && y == v) || (x == v && y == u))
                    continue;
                if(dist[y] > d + wt) {
                    dist[y] = d + wt;
                    pq.push({dist[y], y});
                }
            }
        }
        if(dist[v] < INF)
            best = min(best, dist[v] + w);
    }
    if(best == INF) cout << -1 << "\n";
    else cout << best << "\n";
}
