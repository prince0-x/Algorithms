#include <bits/stdc++.h>
using namespace std;

int n, m;
const long long INF = 1e18;

vector<vector<long long>> cost;
vector<vector<long long>> dp;
vector<vector<bool>> blocked;
vector<vector<bool>> vis;

long long memo(int i, int j){
    if(i < 0 || j < 0) return INF;
    if(blocked[i][j]) return INF;
    if(i == 0 && j == 0) return cost[0][0];

    if(vis[i][j]) return dp[i][j];
    vis[i][j] = true;

    long long best = min(
        memo(i-1, j),
        memo(i, j-1)
    );

    if(best >= INF) dp[i][j] = INF;
    else dp[i][j] = best + cost[i][j];

    return dp[i][j];
}

void solve(){
    cin >> n >> m;

    cost.assign(n, vector<long long>(m, 0));
    blocked.assign(n, vector<bool>(m, false));
    dp.assign(n, vector<long long>(m, 0));
    vis.assign(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            long long x;
            cin >> x;
            if(x == -1){
                blocked[i][j] = true;
            } else {
                cost[i][j] = x;
            }
        }
    }

    if(blocked[0][0]){
        cout << -1 << "\n";
        return;
    }

    long long ans = memo(n-1, m-1);
    cout << (ans >= INF ? -1 : ans) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
