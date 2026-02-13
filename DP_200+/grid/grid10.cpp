#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500, M=500, D=2, T=21;
const ll inf =1e12;
ll dp[N][M][D][T];
int mat[N][M];

void solve(){
      int n, m, r;
      cin>>n>>m>>r;
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cin>>mat[i][j];
            }
      }
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  for(int k=0; k<2; k++){
                        for(int t=0; t<=r; t++){
                              dp[i][j][k][t]=inf;
                        }
                  }
            }
      }
      dp[0][0][0][0] = mat[0][0];
      dp[0][0][1][0] = mat[0][0];
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  for(int k=0; k<2; k++){
                        for(int t=0; t<=r; t++){
                              if(dp[i][j][k][t]==inf)continue;
                              if(k==0){
                                   if(j+1 < m){
                                          dp[i][j+1][0][t]= min(dp[i][j+1][0][t], mat[i][j+1]+dp[i][j][0][t]);
                                   }
                                   if(i+1 <n && t+1 <=r){
                                          dp[i+1][j][1][t+1]= min(dp[i+1][j][1][t+1], mat[i+1][j]+dp[i][j][0][t]);
                                   }
                              }else{
                                    if(i+1 <n){
                                          dp[i+1][j][1][t]= min(dp[i+1][j][1][t], mat[i+1][j]+dp[i][j][1][t]);
                                    }
                                    if(j+1 < m && t+1 <= r){
                                          dp[i][j+1][0][t+1]= min(dp[i][j+1][0][t+1], mat[i][j+1]+dp[i][j][1][t]);
                                    }

                              }
                        }
                  }
            }
      }
      ll ans=inf;
      for(int i=0; i<2; i++){
            for(int j=0; j<=r; j++){
                  ans= min(ans, dp[n-1][m-1][i][j]);
            }
      }
      cout<<(ans>=inf?-1:ans)<<endl;
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      int t=1;
      cin>>t;
      while(t--)solve();
      return 0;
}