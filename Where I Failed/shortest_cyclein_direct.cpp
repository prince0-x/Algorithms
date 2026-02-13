#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,long long>>> g(n);
    for(int i=0;i<m;i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    long long best = INF;

    for(int start = 0; start < n; start++) {
        vector<long long> dist(n, INF);
        dist[start] = 0;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        pq.push({0, start});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;

            for(auto &e : g[u]) {
                int v = e.first;
                long long w = e.second;

                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for(auto &e : g[start]) {
            int v = e.first;
            long long w = e.second;
            if(dist[v] < INF)
                best = min(best, dist[v] + w);
        }
    }

    if(best == INF) cout << -1 << "\n";
    else cout << best << "\n";
}
