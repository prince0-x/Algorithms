#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<vector<ll>> dp, mat;


void solve(){
    cin >> n >> m;
    dp.assign(n, vector<ll>(m, 0));
    mat.assign(n, vector<ll>(m));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
            cin>>mat[i][j];
      }
    }
    if(mat[0][0]==-1){
      cout<<0<<"\n";
      return;
    }
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        if(mat[i][0] == -1) break;
        dp[i][0] = 1;
    }

    for(int j=1;j<m;j++){
        if(mat[0][j] == -1) break;
        dp[0][j] = 1;
    }
    for(int i=1; i<n; i++){
      for(int j=1; j<m; j++){
            if(mat[i][j]!=-1)dp[i][j]=dp[i-1][j]+ dp[i][j-1];
      }
    }
    cout<<dp[n-1][m-1]<<"\n";
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
