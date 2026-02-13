#include<bits/stdc++.h>
using namespace std;
int dfs(int node, int parent,vector<vector<int>>&adj, int &ans){
      priority_queue<int>pq;
      for(int nbr: adj[node]){
            if(nbr== parent)continue;
            int depth= dfs(nbr, node, adj, ans);
            pq.push(1+depth);
      }
      if(pq.size()>=1){
            int first= pq.top();
            pq.pop();
            int second= pq.empty()?0:pq.top();
            ans = max(ans, first+second);
            pq.push(first);
      }
      return pq.empty()?0:pq.top();
}
int main(){
      int n;
      cin>>n;
      vector<vector<int>>adj(n+1);
      for(int i=1;i<n;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }
      int ans=0;
      dfs(1, -1, adj, ans);
      cout<<ans<<endl;
      return 0;
}