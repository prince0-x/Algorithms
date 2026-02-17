#include <bits/stdc++.h>
#define int long long
using namespace std;
static const int MAXV = 40;
struct Node {
    long long inv;
    int freq[41];
    Node() {
        inv = 0;
        memset(freq, 0, sizeof(freq));
    }
};
int n, q;
vector<int> arr;
vector<Node> seg;


Node mergeNode(const Node &L, const Node &R) {
    Node res;

    res.inv = L.inv + R.inv;

    // cross inversions
    int greater_count = 0;
    for (int v = 40; v >= 1; v--) {
        // all left values > v
        res.inv += 1LL * R.freq[v] * greater_count;
        greater_count += L.freq[v];
    }

    // merge frequency
    for (int v = 1; v <= 40; v++) {
        res.freq[v] = L.freq[v] + R.freq[v];
    }

    return res;
}


void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].freq[arr[l]] = 1;
        seg[idx].inv = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
}


void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        memset(seg[idx].freq, 0, sizeof(seg[idx].freq));
        seg[idx].freq[val] = 1;
        seg[idx].inv = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(idx << 1, l, mid, pos, val);
    else update(idx << 1 | 1, mid + 1, r, pos, val);

    seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return Node(); 
    if (ql <= l && r <= qr) return seg[idx];

    int mid = (l + r) >> 1;
    Node left = query(idx << 1, l, mid, ql, qr);
    Node right = query(idx << 1 | 1, mid + 1, r, ql, qr);

    return mergeNode(left, right);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg.resize(4 * (n + 1));
    build(1, 1, n);

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            Node res = query(1, 1, n, x, y);
            cout << res.inv << "\n";
        } 
        else {
            arr[x] = y;
            update(1, 1, n, x, y);
        }
    }

    return 0;
}





