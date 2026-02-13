#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int depth, vector<vector<int>>&adj, vector<int>&dist, int &endNode){
      dist[node] = depth;
      if(depth > dist[endNode]){
            endNode = node;
      }
      for(auto nbr: adj[node]){
            if(nbr==parent)continue;
            dfs(nbr, node,depth+1, adj, dist, endNode);
      }
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
      vector<int> distA(n + 1), distB(n + 1);
      int A = 1;
      dfs(1, -1, 0, adj, distA, A); 
      fill(distA.begin(), distA.end(), 0);
      dfs(A, -1, 0, adj, distA, A);
      dfs(A, -1, 0, adj, distB, A);
      for(int i=1;i<=n;i++){
            cout<<max(distA[i], distB[i])<<" ";
      }
      cout<<"\n";
      return 0;
}