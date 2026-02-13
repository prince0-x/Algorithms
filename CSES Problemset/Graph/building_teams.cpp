#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
int n, m;
vvi adj;
vi parent, colors;
bool dfs(int node, int color){
      colors[node]= color;
      for(auto nbr: adj[node]){
            if(colors[nbr]==0){
                  if(dfs(nbr, 3-color)==false){
                  return false;
            }
            }else if(colors[nbr]==color){
                  return false;
            }
      }
      return true;
}
void solve(){
      cin>>n>>m;
      adj.resize(n+1);
      colors.resize(n+1,  0);
      for(int i=0; i<m;i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      for(int i=1;i<=n;i++){
            if(colors[i]==0){
                  bool ispossible=dfs(i,1);
                  if(!ispossible){
                        cout<<"IMPOSSIBLE\n";
                        return;
                  }
            }
      }

      for(int i=1;i<=n;i++){
            cout<<colors[i]<<" ";
      }
      cout<<"\n";

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