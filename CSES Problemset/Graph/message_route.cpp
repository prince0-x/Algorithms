#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
vvi adj;
vi parent, vis;
void solve(){
      int n, m;
      cin>>n>>m;
      adj.resize(n+1);
      vis.resize(n+1,  0);
      parent.resize(n+1,  -1);
      for(int i=0; i<m;i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }   

      queue<pair<int, int>>q;
      q.push({1, 1}); 
      int ans=-1;
      vis[1]=1;
      while(!q.empty()){
            auto [node,dis] = q.front();
            q.pop();
            if(node == n){
                  ans= dis;
                  break;
            }
            for(auto i:adj[node]){
                  if(!vis[i]){
                        vis[i]=1;
                        q.push({i, dis+1});
                        parent[i]=node;
                  }
            }
      }
      
      
      if(ans==-1){
            cout<<"IMPOSSIBLE\n";
      }else{
            cout<<ans<<"\n";
            function<void(int)> fn = [&](int val){
                  if(val == -1) return;
                  fn(parent[val]);  
                  cout << val << " "; 
            };
            fn(n);
      }
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            solve();
      }
      return 0;
}