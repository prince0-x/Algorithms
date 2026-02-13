#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q, timer = 0;
vector<vector<int>> adj;
vector<int> values, tin, tout, flat_arr, seg;

void dfs(int node, int parent) {
    tin[node] = timer++;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
    tout[node] = timer - 1;
}


void calc_flatarr() {
    for (int i = 1; i <= n; i++) {
        flat_arr[tin[i]] = values[i];
    }
}

void build(int node, int low, int high) {
    if (low == high) {
        seg[node] = flat_arr[low];
        return;
    }
    int mid = low + ((high - low) >> 1);
    build(node << 1, low, mid);
    build(node << 1 | 1, mid + 1, high);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

// Query sum in range [l, r]
int query(int node, int low, int high, int l, int r) {
    if (r < low || high < l) return 0;
    if (l <= low && high <= r) return seg[node];
    int mid = low + ((high - low) >> 1);
    return query(node << 1, low, mid, l, r) + query(node << 1 | 1, mid + 1, high, l, r);
}

// Update value at position pos
void update(int node, int low, int high, int pos, int val) {
    if (low == high) {
        seg[node] = val;
        return;
    }
    int mid = low + ((high - low) >> 1);
    if (pos <= mid) update(node << 1, low, mid, pos, val);
    else update(node << 1 | 1, mid + 1, high, pos, val);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n>>q;
    adj.resize(n + 1);
    values.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);

    flat_arr.resize(n);
    
    for (int i = 1; i <= n; i++) cin >> values[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1, -1);
    calc_flatarr();

    seg.resize(4 * n);
    build(1, 0, n - 1);

    
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int v, new_val;
            cin >> v >> new_val;
            update(1, 0, n - 1, tin[v], new_val);
        } else {
            int s;
            cin >> s;
            cout << query(1, 0, n - 1, tin[s], tout[s]) << "\n";
        }
    }
    return 0;
}
