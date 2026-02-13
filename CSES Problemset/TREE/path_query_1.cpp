#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
vector<vector<int>> adj;
vector<int> val, tin, tout;
int timer = 0;

struct BIT {
    int N; vector<ll> bit;
    BIT() {}
    BIT(int n): N(n), bit(n + 2, 0) {} 
    void add(int idx, ll delta) {
        for (; idx <= N; idx += (idx & -idx)) bit[idx] += delta;
    }
    ll sumPrefix(int idx) const {
        ll s = 0;
        for (; idx > 0; idx -= (idx & -idx)) s += bit[idx];
        return s;
    }
    ll prefixMax(int idx)const{
        ll maxi = LLONG_MIN;
        for(;idx>0; idx-=(idx&-idx))maxi=max(maxi, bit[idx]);
        return maxi;
    }
};

void dfs(int u, int p) {
    tin[u] = ++timer;
    for (int v: adj[u]) if (v != p) dfs(v, u);
    tout[u] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    adj.assign(n + 1, {});
    val.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1, 0);

    BIT bit(n + 2);
    for (int u = 1; u <= n; ++u) {
        bit.add(tin[u], val[u]);
        bit.add(tout[u] + 1, -val[u]);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {

            int u; ll newVal; cin >> u >> newVal;
            ll diff = newVal - val[u];
            val[u] = newVal;

            bit.add(tin[u], diff);
            bit.add(tout[u] + 1, -diff);
        } else {

            int v; cin >> v;
            cout << bit.sumPrefix(tin[v]) << '\n';
        }
    }
    return 0;
}
