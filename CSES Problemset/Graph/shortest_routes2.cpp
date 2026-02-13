#include <bits/stdc++.h>
#define int long long
using namespace std;

const long long INF = 1e15; 
int n, m, q;
vector<vector<long long>> ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    ans.assign(n + 1, vector<long long>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        ans[x][y] = min(ans[x][y], w);
        ans[y][x] = min(ans[y][x], w);
    }

    for (int i = 1; i <= n; i++) ans[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ans[i][k] + ans[k][j] < ans[i][j]) {
                    ans[i][j] = ans[i][k] + ans[k][j];
                }
            }
        }
    }

    while (q--) {
        int src, dest;
        cin >> src >> dest;
        if (ans[src][dest] >= INF / 2)
            cout << -1 << '\n';
        else
            cout << ans[src][dest] << '\n';
    }

    return 0;
}
