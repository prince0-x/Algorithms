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
vi vis;
void solve(){
      int n, m;
      cin>>n>>m;
      adj.resize(n+1);
      vis.resize(n+1,  0);
      for(int i=0; i<m;i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }    
      int cnt=0;
      vi ans;  
      for(int i=1;i<=n;i++){
            if(!vis[i]){
                  cnt++;
                  queue<int>q;
                  vis[i]=1;
                  ans.push_back(i);
                  q.push(i);
                  while (!q.empty())
                  {
                        int v = q.front();
                        q.pop();
                        for(auto u: adj[v]){
                              if(!vis[u]){
                                    vis[u]=1;
                                    q.push(u);
                              }
                        }
                  }
            } 
      }
      cout<<((cnt==0)?0:cnt-1)<<endl;
      for(int i=0;i<ans.size()-1; i++){
            cout<<ans[i]<<" "<<ans[i+1]<<"\n";
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