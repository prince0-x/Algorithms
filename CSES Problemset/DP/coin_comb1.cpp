#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
// int solve(int amount, vector<int>&coins, vector<int>&dp){
//       if(amount==0)return 1;
//       if(amount < 0) return 0;
//       if(dp[amount] != -1) return dp[amount];
//       int ans =0;
//       for(auto &coin : coins){
//           ans+=solve(amount-coin, coins, dp);
//       }
//       return dp[amount]= ans;
// }
int solve_tab(int amount, vector<int>&coins){
      vector<int>dp(amount+1, 0);
      dp[0] =1;
      for(int i= 1;i<=amount; i++){
            for(auto &coin: coins){
                if(i-coin>=0)  dp[i]= (0LL+ dp[i]+dp[i-coin])%MOD;
            }
      }
      return dp[amount];
}

int main(){
      int n, amount;
      cin >> n>> amount;
      vector<int>coins(n);
      for(int i=0;i<n;i++){
            cin >> coins[i];
      }
      // vector<int>dp(amount+1, -1);
      // cout<<solve(amount, coins, dp)<<endl;
      cout<<solve_tab(amount, coins)<<endl;
      return 0;
}