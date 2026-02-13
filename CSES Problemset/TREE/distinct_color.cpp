#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n;
vector<int> adj[N];
set<int>colors[N];
vector<int>dcolor(N);

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if(colors[u].size() < colors[v].size()){
            swap(colors[u], colors[v]);
        }
        for(int i:colors[v]){
            colors[u].insert(i);
        }
    }
    dcolor[u]=colors[u].size();
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++){
       int color;
       cin >>color; 
       colors[i].insert(color);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << dcolor[i] << " ";
    cout << "\n";
}
