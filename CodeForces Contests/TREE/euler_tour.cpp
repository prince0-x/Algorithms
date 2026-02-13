void dfs(int node, int parent){
      tin[node]=timer;
      timer++;

      up[node][0]=parent;
      for(int i=1;i<=L;i++){
            if(up[node][i-1]==-1){
                  up[node][i]=-1;
            }else{
                  up[node][i]=up[up[node][i-1]][i-1];
            }
      }
      for(auto child: adj[node]){
            if(child != parent){
                  dfs(child, node);
            }
      }
      tout[node]=timer;
      timer++;
}

bool isEnsester(int u, int v){
      return tin[v] >= tin[u] && tout[v]<= tout[u];
}