#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      int n;cin>>n;
      vector<int>arr(n);
      for(auto &i:arr)cin>>i;

      int max_sum= accumulate(arr.begin(), arr.end(), 0);
      vector<bool>dp(max_sum+1, 0);
      dp[0]=1;
      for(int c: arr){
            for(int j=max_sum; j>=c; j--){
                  if(dp[j-c]){
                        dp[j]= true;
                  }
            }
      }
      vector<int>ans;
      for(int i=1; i<=max_sum; i++){
            if(dp[i])ans.push_back(i);
      }
      cout<<ans.size()<<"\n";
      for(int i=0; i<(int)ans.size(); i++){
            cout<<ans[i]<<" ";
      }
      cout<<"\n";
      return 0;
}