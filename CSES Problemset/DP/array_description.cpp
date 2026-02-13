#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
      int n, m, mod = 1000000007;
      cin>>n>>m;
      vector<int>arr(n);
      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
      for(int i=1;i<=m;i++){
            dp[1][i]= (arr[0]==i || arr[0]==0);
      }
      for(int i=2;i<=n;i++){
            for(int k=1;k<=m;k++){
                  if(arr[i-1] != 0 && arr[i-1]!= k){
                        dp[i][k]=0; continue;
                  }
                  for(int diff = -1; diff<=1;diff++){
                        int val = k+diff;
                        if (val < 1 || val > m) continue; 
                        dp[i][k] += dp[i-1][val];
                  }
                  dp[i][k]%= mod;
            }
      }
      int ans=0;
      for(int i=1;i<=m;i++){
            ans=(ans +dp[n][i])%mod;
      }
      
      cout<<ans<<"\n";
      return 0;
}