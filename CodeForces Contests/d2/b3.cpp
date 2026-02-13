#include <bits/stdc++.h>
using namespace std;


void solv() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> st(n);
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        st[i].resize(l);
        for (int j = 0; j < l; ++j) {
            int x; cin >> x;
            st[i][j] = x;
            ++cnt[x];
        }
    }
    for (int x = 1; x <= m; ++x) {
        if (cnt[x] == 0) {
            cout << "NO\n";
            return;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int x : st[i]) {
            if (cnt[x] == 1) {
                flag = true;
                break;
            }
        }
        if (flag) ++count;
    }
    int free_st = n - count;
    cout << (free_st >= 2 ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--) solv();
    return 0;
}
