#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n) : n(n), f(n + 1, 0) {}
    void add(int i, int v) {
        while (i <= n) {
            f[i] += v;
            i += i & -i;
        }
    }
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += f[i];
            i -= i & -i;
        }
        return s;
    }
    int range_sum(int l, int r) {
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vi arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    Fenwick bit(n);
    for (int i = 1; i <= n; i++) bit.add(i, 1);
    ll ans = 0;
    for (int val = n; val >= 1; val--) {
        int idx = pos[val];
        int left = bit.range_sum(1, idx - 1);
        int right = bit.range_sum(idx + 1, n);
        ans += min(left, right);
        bit.add(idx, -1);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
