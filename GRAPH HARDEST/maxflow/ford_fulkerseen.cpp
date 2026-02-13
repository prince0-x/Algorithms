#include<bits/stdc++.h>
using namespace std;
struct Edge{
      int v, capacity, rev;
};
class MaxFl{
      public: 
      int n;
      vector<vector<Edge>>adj;

      MaxFl(int n){
            this->n= n;
            adj.resize(n);
      }

      void AddEdge(int u, int v, int cap){
            Edge a= {v, cap, (int)adj[v].size()};
            Edge b= {u, 0, (int)adj[u].size()};
            adj[u].push_back(a);
            adj[v].push_back(b);
      }
      
      int dfs(int u, int t, int flow, vector<bool>& visited){
            if(u== t) return flow;

            visited[u]= true;

            for(auto &e: adj[u]){
                  if(!visited[e.v] && e.capacity >0){
                        int pushed = dfs(e.v, t, min(flow, e.capacity), visited);

                        if(pushed >0){
                              e.capacity -= pushed;
                              adj[e.v][e.rev].capacity +=pushed;
                              return pushed;
                        }
                  }
            }
            return 0;
      }


      int fordfulkerson(int s, int t){
            int maxflow = 0;
            while(true){
                  vector<bool> visited(n, false);
                  int flow = dfs(s, t, INT_MAX, visited);
                  
                  if(flow ==0) break;
                  maxflow += flow;
            }
            return maxflow;
      }
};
int main(){
      int n, m;
      cin>>n>>m;
      MaxFl mf(n);
      for(int i=0;i< m; i++){
            int u, v, c;
            cin>>u>>v>>c;
            mf.AddEdge(u, v, c);
      }
      int s, t;
      cin>>s>>t;
      cout<<mf.fordfulkerson(s, t);
      return 0;
}