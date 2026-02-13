#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len = 0;   // segment length
    int pref = 0;  // longest prefix of ones
    int suff = 0;  // longest suffix of ones
    int best = 0;  // longest consecutive ones
};

Node mergeNode(const Node &L, const Node &R) {
    Node res;
    res.len = L.len + R.len;
    res.pref = (L.pref == L.len ? L.len + R.pref : L.pref);
    res.suff = (R.suff == R.len ? R.len + L.suff : R.suff);
    res.best = max({L.best, R.best, L.suff + R.pref});
    return res;
}

struct SegTree {
    int n;
    vector<Node> st;
    SegTree() {}
    SegTree(int n_): n(n_) { st.assign(4*n+4, Node()); }

    void build(const vector<int> &arr, int p, int l, int r) {
        if (l == r) {
            st[p].len = 1;
            st[p].pref = st[p].suff = st[p].best = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(arr, p<<1, l, m);
        build(arr, p<<1|1, m+1, r);
        st[p] = mergeNode(st[p<<1], st[p<<1|1]);
    }

    void build(const vector<int> &arr) { // arr is 1-indexed of size n
        if (n <= 0) return;
        build(arr, 1, 1, n);
    }

    void pointUpdate(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p].len = 1;
            st[p].pref = st[p].suff = st[p].best = val;
            return;
        }
        int m = (l + r) >> 1;
        if (idx <= m) pointUpdate(p<<1, l, m, idx, val);
        else pointUpdate(p<<1|1, m+1, r, idx, val);
        st[p] = mergeNode(st[p<<1], st[p<<1|1]);
    }

    void pointUpdate(int idx, int val) { 
        if (n <= 0) return;
        pointUpdate(1, 1, n, idx, val);
    }

    int getBest() const { 
        if (n <= 0) return 0;
        return st[1].best;
    }
};

static inline long long safe_lcm_leqK(long long a, long long b, long long K) {
    // returns lcm(a,b), but if lcm > K (or would overflow), return K+1
    if (a == 0 || b == 0) return 0; 
    long long g = std::gcd(a, b);
    long long x = a / g;
    if (x > K / b) return K + 1;
    long long l = x * b;
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    long long K;
    if (!(cin >> n >> q >> K)) return 0;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (n == 1) {
        while (q--) {
            int idx; long long val;
            cin >> idx >> val;
            a[idx] = val;
            cout << 1 << "\n";
        }
        return 0;
    }
    vector<int> good(n); 
    for (int i = 1; i <= n-1; ++i) {
        long long l = safe_lcm_leqK(a[i], a[i+1], K);
        good[i] = (l <= K) ? 1 : 0;
    }

    SegTree st(n-1);
    st.build(good);

    auto recompute_pair = [&](int i) {
        if (i < 1 || i >= n) return;
        long long l = safe_lcm_leqK(a[i], a[i+1], K);
        int v = (l <= K) ? 1 : 0;
        st.pointUpdate(i, v);
    };

    while (q--) {
        int idx; long long val;
        cin >> idx >> val;
        a[idx] = val;

        recompute_pair(idx-1);
        recompute_pair(idx);

        int best_pairs = st.getBest();  
        int ans = best_pairs + 1;        
        if (ans < 1) ans = 1;
        cout << ans << "\n";
    }
    return 0;
}
