#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>dp;
int dfs(int node, int parent){
      if(dp[node] != -1)return dp[node];
      int sz=0;
      for(auto child:adj[node]){
            if(child != parent){
                  sz+=dfs(child, node) + 1;
            }
      }
      return dp[node]=sz;
}
int main(){
      int n;
      cin >> n;
      adj.resize(n+1);
      dp.resize(n+1, -1);
      for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
      }
      dfs(1,0);
      for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
      cout<<"\n";
      return 0;
}