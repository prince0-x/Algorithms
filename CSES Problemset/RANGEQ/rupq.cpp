#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, q;
vector<int> bit;

void add(int idx, int delta) {
    for (; idx <= n; idx += (idx & -idx)) {
        bit[idx] += delta;
    }
}

int sum(int idx) {
    int res = 0;
    for (; idx > 0; idx -= (idx & -idx)) {
        res += bit[idx];
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    bit.assign(n + 2, 0);

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        add(i, arr[i] - arr[i-1]);
    }

    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            add(l, u);
            add(r + 1, -u);
        } else {
            int k;
            cin >> k;
            cout << sum(k) << endl;
        }
    }
    return 0;
}
