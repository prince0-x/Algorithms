#include <bits/stdc++.h>
using namespace std;
const int B = 20;
struct seg {
    int len;
    int cnt[B];
    int lazy;
    seg(){ len = 0; lazy = 0; memset(cnt, 0, sizeof(cnt)); }
};
int n;
vector<vector<pair<int,int>>> g;
vector<int> tin, tout, euler, val;
int timer_;

void dfs(int u, int p, int cur_xor){
    tin[u] = timer_;
    euler[timer_++] = u;
    val[u] = cur_xor;
    for (auto &e : g[u]){
        int v = e.first, w = e.second;
        if (v == p) continue;
        dfs(v, u, cur_xor ^ w);
    }
    tout[u] = timer_ - 1;
}

vector<seg> st;

seg merge_seg(const seg &a, const seg &b){
    seg r;
    r.len = a.len + b.len;
    r.lazy = 0;
    for (int i = 0; i < B; ++i) r.cnt[i] = a.cnt[i] + b.cnt[i];
    return r;
}

void apply_xor(int id, int x){
    if (x == 0) return;
    for (int b = 0; b < B; ++b){
        if (x & (1 << b)) st[id].cnt[b] = st[id].len - st[id].cnt[b];
    }
    st[id].lazy ^= x;
}

void build(int id, int l, int r, const vector<int> &arr){
    if (l == r){
        st[id].len = 1;
        st[id].lazy = 0;
        for (int b = 0; b < B; ++b) st[id].cnt[b] = ((arr[l] >> b) & 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(id<<1, l, mid, arr);
    build(id<<1|1, mid+1, r, arr);
    st[id] = merge_seg(st[id<<1], st[id<<1|1]);
}

void push(int id){
    int x = st[id].lazy;
    if (x){
        apply_xor(id<<1, x);
        apply_xor(id<<1|1, x);
        st[id].lazy = 0;
    }
}

void update(int id, int l, int r, int ql, int qr, int x){
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr){
        apply_xor(id, x);
        return;
    }
    push(id);
    int mid = (l + r) >> 1;
    update(id<<1, l, mid, ql, qr, x);
    update(id<<1|1, mid+1, r, ql, qr, x);
    st[id] = merge_seg(st[id<<1], st[id<<1|1]);
}

seg query(int id, int l, int r, int ql, int qr){
    if (ql > r || qr < l) return seg();
    if (ql <= l && r <= qr) return st[id];
    push(id);
    int mid = (l + r) >> 1;
    seg left = query(id<<1, l, mid, ql, qr);
    seg right = query(id<<1|1, mid+1, r, ql, qr);
    return merge_seg(left, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--){
        int q;
        cin >> n;
        g.assign(n+1, {});
        for (int i = 0; i < n-1; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        tin.assign(n+1, 0);
        tout.assign(n+1, 0);
        euler.assign(n, 0);
        val.assign(n+1, 0);
        timer_ = 0;
        dfs(1, 0, 0);

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = val[euler[i]];

        st.assign(4*n + 5, seg());
        build(1, 0, n-1, arr);

        cin >> q;
        while (q--){
            int type;
            cin >> type;
            if (type == 1){
                int u, x;
                cin >> u >> x;
                int l = tin[u], r = tout[u];
                update(1, 0, n-1, l, r, x);
            } else {
                int u;
                cin >> u;
                int l = tin[u], r = tout[u];
                seg res = query(1, 0, n-1, l, r);
                long long m = res.len;
                long long ans = 0;
                for (int b = 0; b < B; ++b){
                    long long c1 = res.cnt[b];
                    long long c0 = m - c1;
                    ans += c1 * c0 * (1LL << b);
                }
                cout << ans <<'\n';
            }
        }
    }
    return 0;
}
