#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n;
vector<int> adj[N];
vector<int>dcolor(N), siz(N, 0), bigc(N, -1);

void dfs(int u, int p) {
      siz[u]=1;
      int maxc=0;
      for (int v : adj[u]) {
        if(p!=v){
            dfs(v, u);
            siz[u]+=siz[v];
            if(siz[v]>maxc){
                  maxc=siz[v];
                  bigc[u]=v;
            }
        }
    }
}
int dfs2(int u, int p){
      for (int v : adj[u]) {
            if (v == p) continue;
            if (siz[v] > n / 2) {
                  return dfs2(v, u);
            }
      }
    return u;
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
   
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout<<dfs2(1,0)<<endl;

}
