#include <bits/stdc++.h>
using namespace std;

vector<int> seg, heights, first_occur, euler;
vector<bool> vis;

void dfs(vector<vector<int>>& adj, int node, int height = 0) {
    vis[node] = true;
    heights[node] = height;
    first_occur[node] = euler.size();
    euler.push_back(node);

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(adj, nbr, height + 1);
            euler.push_back(node); 
        }
    }
}

void build(int node, int low, int high) {
    if (low == high) {
        seg[node] = euler[low];
        return; 
    }
    int mid = low + ((high - low) >> 1);
    build(node << 1, low, mid);
    build(node << 1 | 1, mid + 1, high);

    int l = seg[node << 1];
    int r = seg[node << 1 | 1];
    seg[node] = (heights[l] < heights[r]) ? l : r;
}

int query(int node, int low, int high, int left, int right) {
    if (low > right || high < left) return -1; 
    if (low >= left && high <= right) return seg[node]; 

    int mid = low + ((high - low) >> 1);
    int l = query(node << 1, low, mid, left, right);
    int r = query(node << 1 | 1, mid + 1, high, left, right);

    if (l == -1) return r;
    if (r == -1) return l;
    return heights[l] < heights[r] ? l : r;
}

int lca(int u, int v) {
    int left = first_occur[u], right = first_occur[v];
    if (left > right) swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
}

int main() {
    int n, q;
    cin >> n >> q;

    heights.resize(n + 1);
    first_occur.resize(n + 1, -1);
    vis.resize(n + 1, false);

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
            cin >>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
    }

    dfs(adj, 1);
    int m = euler.size();
    seg.resize(4 * m);
    build(1, 0, m - 1);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout <<heights[u]+heights[v]-2*heights[lca(u, v)] << "\n";
    }
    return 0;
}
