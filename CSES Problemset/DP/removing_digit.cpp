#include<bits/stdc++.h>
using namespace std;
int solve(int amount, vector<int>&dp){
      if(amount==0) return 0;
      if(amount < 0) return INT_MAX;
      if(dp[amount] != -1) return dp[amount];
      int ans= INT_MAX;
      string val = to_string(amount);

      for(auto &i:val){
            int temp =int( i-'0');
            if(temp != 0){
                  int temp2 = solve(amount-temp, dp);
                  if(temp2 != INT_MAX){
                        ans= min(ans, 1+temp2);
                  }
            }
      }
      return dp[amount]=ans;
}
int solve_tab(int amount){
      vector<int>dp(amount+1, INT_MAX);
      dp[0]=0;
      for(int i=1;i<=amount;i++){
            string s = to_string(i);
            for(int j =0;j<s.size(); j++){
                  int val = int(s[j]-'0');
                  if(val >=0 && i-val >=0 && dp[i-val] != INT_MAX){
                        dp[i]= min(dp[i], 1+dp[i-val]);
                  }
            }
      }
      return dp[amount];
}
int main(){
      int n;
      cin >> n;
      // vector<int>dp(n+1, -1);
      cout << solve_tab(n)<<endl;
      return 0;
}