#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, k, m;
long long ans=0;
vector<int> adj[N];
vector<int> siz(N, 0), countArr(N), vis(N, 0);;

void dfs(int u, int p) {
      siz[u]=1;
      for (int v : adj[u]) {
        if(p!=v  && !vis[v]){
            dfs(v, u);
            siz[u]+=siz[v];
        }
      }
}
int find_centr(int u, int p, int total){
      for (int v : adj[u]) {
            if (!vis[v] && v!=p && siz[v] > total/2) return find_centr(v, u, total);
      }
    return u;
}
void calc_coutarr(int u, int p, int d, bool c) {
    if (d > k) return;
    if (c) ans += countArr[k-d];
    else countArr[d]++;
    m = max(m, d);

    for (int v : adj[u]) {
        if ( v != p && !vis[v]) {
            calc_coutarr(v, u, d+1, c);
        }
    }
}
void decompose(int u){
      dfs(u, -1);
      int c = find_centr(u,-1,siz[u]);
      vis[c] = 1;
      countArr[0] = 1;
      m=0;
      for(auto v:adj[c]){
            if(!vis[v]){
                  calc_coutarr(v, c, 1, true);
                  calc_coutarr(v, c, 1, false);
            }
      }
      for (int i = 0; i <= m; i++) countArr[i] = 0;
      for (int v : adj[c]) {
            if (!vis[v]) decompose(v);
      }
}




int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n>>k;
   
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decompose(1);
    cout<<ans<<endl;

}
