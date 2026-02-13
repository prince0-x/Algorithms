#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, W;
      cin>>n>>W;
      vector<int>price(n);
      vector<int>page(n);
      for(auto &x:price)cin>>x;
      for(auto &x:page)cin>>x;
      vector<int>dp(W+1, 0);
      
      for(int i=0;i<n;i++){
            for(int w=W; w>=price[i];--w){
                  dp[w]= max(dp[w],dp[w-price[i]]+page[i]);
            }
      }
      cout<<dp[W]<<"\n";
      return 0;
}