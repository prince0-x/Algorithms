#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>dp;
void solve(string &s, string &t){
      dp.resize(n+1, vector<int>(m+1));

      for(int i=0;i<=n;i++){
            dp[i][0]=i;
      }
      for(int i=0;i<=m;i++){
            dp[0][i]=i;
      }
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(s[i-1]==t[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                  }else{
                        dp[i][j] = 1+ min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                  }
            }
      }
}
int main(){
      string s, t;
      cin>>s>>t;
      n= s.size(), m = t.size();
      solve(s, t);
      cout<<dp[n][m]<<endl;
      return 0;
}