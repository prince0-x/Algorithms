#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int solve(int i, int j,int n, vector<string>&grid, vector<vector<int>>&dp){

      if(i<0 || i>=n || j<0 || j>=n)return 0;
      if (grid[i][j] == '*') return 0;
      if (i == n - 1 && j == n - 1) return 1;

      if(dp[i][j] != -1){
            return dp[i][j];
      }  

      int down = solve(i + 1, j, n, grid, dp);
      int right = solve(i, j + 1, n, grid, dp);
      
      return dp[i][j] = (0LL+down + right) % MOD;
}
int main(){
      int n;
      cin >> n ;
      vector<string>mat(n);

      for(int i=0;i<n;i++){
            cin>> mat[i];
      }

      vector<vector<int>>dp(n, vector<int>(n, -1));
      cout<<solve(0, 0,n, mat, dp)<<endl;
      return 0;
}