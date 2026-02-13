#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> a, seg;

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
}

int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return INF;   
    if (ql <= l && r <= qr) return seg[idx]; 
    int mid = (l + r) / 2;
    return min(query(2 * idx, l, mid, ql, qr),
               query(2 * idx + 1, mid + 1, r, ql, qr));
}

void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx, l, mid, pos, val);
    else
        update(2 * idx + 1, mid + 1, r, pos, val);
    seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    seg.assign(4 * n, INF);
    build(1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int l, r;
            cin >> l >> r;
            
            l--; r--;
            cout << query(1, 0, n - 1, l, r) << "\n";
        } else {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(1, 0, n - 1, pos, val);
        }
    }

    return 0;
}
