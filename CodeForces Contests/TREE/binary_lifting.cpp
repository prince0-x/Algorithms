#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent){
      up[node][0] = parent;
      for(int i=1;i<=L;i++){
            up[node][i]= up[up[node][i-1]][i-1];
      }
      for(auto nbr:adj[node]){
            if(nbr != parent){
                  dfs(nbr, node);
            }
      }
}