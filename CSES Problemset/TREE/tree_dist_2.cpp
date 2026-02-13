#include<bits/stdc++.h>
#define ll long long
using namespace std;

//          TLE   O(n^2)

// int dfs(int node, int parent,int depth,  vector<vector<int>>&adj){
//       int ans=depth;
//       for(auto nbr: adj[node]){
//             if(nbr==parent)continue;
//             ans+= dfs(nbr, node,depth+1, adj);
//       }
//       return ans;
// }
// int main(){
//       int n;
//       cin>>n;
//       vector<vector<int>>adj(n+1);
//       for(int i=1;i<n;i++){
//             int u, v;
//             cin>>u>>v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//       }
//       for(int i=1;i<=n;i++){
//             cout<<dfs(i, -1,0, adj)<<" ";
//       }
//       cout<<"\n";
//       return 0;
// }

int n;
vector<vector<int>>adj;
vector<ll>subtree_size, ans;
void dfs1(int node, int parent, ll depth, ll& sumDist){
      sumDist+=depth;
      subtree_size[node]=1;
      for(int nbr: adj[node]){
            if(nbr==parent)continue;
            dfs1(nbr, node, depth+1, sumDist);
            subtree_size[node]+=subtree_size[nbr];
      }

}
void dfs2(int node, int parent){
      for(int nbr: adj[node]){
            if(nbr == parent)continue;
            ans[nbr]= ans[node]+ n-2*subtree_size[nbr];
            dfs2(nbr, node);
      }
}
int main(){
      cin>>n;
      adj.resize(n+1);
      subtree_size.resize(n+1, 0);
      ans.resize(n+1, 0);

      for(int i=1;i<n;i++){
            int u, v;
            cin >> u>> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      ll sumDist_root = 0;
      dfs1(1, -1, 0LL, sumDist_root);
      ans[1]= sumDist_root;
      dfs2(1, -1);
      
      for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
      }
      cout<<"\n";

      return 0;

}