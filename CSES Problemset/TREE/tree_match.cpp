#include<bits/stdc++.h>
using namespace std;
int dfs(int node,int parent, vector<vector<int>>&adj, vector<vector<int>>&dp){
      dp[0][node]=dp[1][node] = 0;
      
      // take no matches
      int total_no_match = 0;
      for(auto & child:adj[node]){
            if(child == parent)continue;
            total_no_match += dfs(child, node, adj, dp);
      }
      dp[0][node]= total_no_match;

      // gett max of match
      
      for(auto & child:adj[node]){
            if(child == parent)continue;
            int candidate = 1 +dp[0][child] + (total_no_match - max(dp[0][child], dp[1][child]));
        dp[1][node] = max(dp[1][node], candidate);
      }
      return max(dp[0][node], dp[1][node]);// take max of both by taking current and not taking curr
}
int main(){
      int n;
      cin>> n;
      vector<vector<int>>adj(n+1);
      for(int i=1;i<n;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      vector<vector<int>>dp(2, vector<int>(n+1, -1));
      cout << dfs(1, -1, adj, dp)<<"\n";
      return 0;

}