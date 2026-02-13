// some kinda min distance bw two node
// intuition dist[lca(u, v)]from u + dist[lca(u, v)]from v
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int LOG;
vector<vector<int>>up, adj;
vector<int>depths, cnt;


void dfs(int node,int parent){
      up[0][node]=parent;
      for(int i=1;i<LOG;i++){
           if(up[i-1][node] != -1){
             up[i][node]= up[i-1][up[i-1][node]];
           }else{
            up[i][node]= -1;
           }
      }
      for(auto nbr : adj[node]){
            if(nbr != parent){
                  depths[nbr]= depths[node]+1;
                  dfs(nbr, node);
            }
      }
}

int lift(int node, int k){
      for(int i=0;i<LOG;i++){
            if(k&(1<<i)){
                  node= up[i][node];

            }
            if(node==-1){
                  break;
            }
      }
      return node;
}
int lca(int u, int v){
      if(depths[u]<depths[v])swap(u, v);
      u = lift(u, depths[u]-depths[v]);
      if(u==v)return u;
      for(int i=LOG;i>=0;i--){
            if(up[i][u] != up[i][v]){
                  u= up[i][u];
                  v= up[i][v];
                  
            }
      }
      return up[0][u];
}
void post_dfs(int node, int parent){
      for(auto nbr:adj[node]){
            if(nbr != parent){
                  post_dfs(nbr, node);
                  cnt[node]+=cnt[nbr];
            }
      }
}
int main(){
      int n, q;
      cin>>n>>q;
      LOG = __lg(n)+1;

      up.resize(LOG+1, vector<int>(n+1, -1));
      adj.resize(n+1);
      depths.resize(n+1);
      cnt.resize(n+1, 0);
      depths[1]=0;

      for(int i=1;i<n;i++){
            int u, v;
            cin >>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // up[0][i+1]=p;
      }
      dfs(1,-1);
      while(q--){
            int u,v;
            cin>>u>>v;
            int ansester = lca(u, v);
            cnt[u]+=1;
            cnt[v]+=1;
            cnt[ansester]-=1;
            if (up[0][ansester] != -1) { // only if LCA has a parent
                  cnt[up[0][ansester]] -= 1;
            }
      }
      post_dfs(1, -1);
      for(int i=1;i<=n;i++){
            cout<<cnt[i]<<" ";
      }
      cout<<"\n";
      return 0;

}