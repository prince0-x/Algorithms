#include<bits/stdc++.h>
using namespace std;

int solve(int amount, vector<int>&coins, vector<int>&dp){
      if(amount==0) return 0;
      if(amount < 0)return INT_MAX;
      if(dp[amount] != -1)return dp[amount];
      
      int ans= INT_MAX;
      for(auto &coin : coins){
            int state = solve(amount-coin, coins,dp);
            if(state != INT_MAX && state + 1 > 0){
                  ans= min(ans, 1+state);
            }
      }
      return dp[amount] = ans!=INT_MAX?ans:-1;
}


int solve_tab(int amount, vector<int>&coins){
      vector<int>dp(amount+1, INT_MAX);
      dp[0]=0;

      for(int i=1;i<=amount;i++){
            for(auto &coin:coins){
                if(i-coin >= 0 && dp[i-coin] != INT_MAX){
                  dp[i]=min(dp[i],1+ dp[i-coin]);
                }
            }
      }
      return dp[amount]==INT_MAX?-1:dp[amount];
}
int main(){
      int n, amount;
      cin >> n>> amount;
      vector<int>coins(n);
      for(int i=0;i<n;i++){
            cin >> coins[i];
      }
      vector<int>dp(amount+1, -1);
      // cout<<solve(amount, coins,dp)<<endl;
      cout<<solve_tab(amount, coins)<<endl;
      return 0;
}