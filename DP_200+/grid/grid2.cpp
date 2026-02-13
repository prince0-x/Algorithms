#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define ll long long
vvi mat, dp;
int n, m;
int memo(int i, int j){
      if(i<0||j<0) return INT_MIN;
      if(i==0 &&j==0) return mat[0][0];
      if(dp[i][j] != INT_MIN) return dp[i][j];
      int val=max(memo(i-1, j), memo(i, j-1));
      if(val==INT_MIN) return dp[i][j]=INT_MIN;
      return dp[i][j]=mat[i][j]+val;

}
int tabu(){
      dp[0][0]=mat[0][0];
      for(int i=1; i<n; i++){
            dp[i][0]=mat[i][0]+dp[i-1][0];
      }

      for(int j=1; j<m; j++){
            dp[0][j]=mat[0][j]+dp[0][j-1];
      }
      for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                  dp[i][j]=mat[i][j]+max(dp[i-1][j], dp[i][j-1]);
            }
      }
      return dp[n-1][m-1];
}
void solve(){
      cin>>n>>m;
      mat.assign(n, vector<int>(m, 0));
      // dp.assign(n, vector<int>(m, INT_MIN));
       dp.assign(n, vector<int>(m, 0));
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cin>>mat[i][j];
            }
      }
      // cout<<memo(n-1, m-1)<<"\n";
      cout<<tabu()<<"\n";
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}