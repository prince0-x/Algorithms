#include<bits/stdc++.h>
#define ll long long 
using namespace std;

struct Edge{
      int v;
      ll capacity;
      int rev;
};

class Maxfl{
      public:
      int n;
      vector<vector<Edge>>adj;
      vector<int>level, ptr;

      Maxfl(int n){
            this->n= n;
            adj.resize(n);
            level.resize(n);
            ptr.resize(n);
      }

      void addEdge(int u, int v, ll cap){
            Edge a = {v, cap, (int)adj[v].size()};
            Edge b = {u, 0, (int)adj[u].size()};

            adj[u].push_back(a);
            adj[v].push_back(b);
      }


      bool bfs(int s, int t){
            fill(level.begin(), level.end(), -1);
            queue<int>q;
            q.push(s);
            level[s]=0;

            while(!q.empty()){
                  int u = q.front();
                  q.pop();

                  for(auto &e:adj[u]){
                        if(e.capacity >0 && level[e.v] ==-1){
                              level[e.v] =level[u] + 1;
                              q.push(e.v);
                        }
                  }
            }
            return level[t] != -1;
      }
      

      int dfs(int u, int t, ll flow){
            if(flow ==0 ) return 0;
            if(u== t) return flow;

            for(auto & cid= ptr[u] ; cid < adj[u].size(); cid++){
                  Edge & e = adj[u][cid];
                  if(e.capacity >0 && level[e.v] == level[u]+1){
                        ll pushed = dfs(e.v, t, min(flow, e.capacity));

                        if(pushed > 0){
                              e.capacity -= pushed;
                              adj[e.v][e.rev].capacity +=pushed;
                              return pushed;
                        }
                  }
            }
            return 0;
      }

      ll dinic(int s, int t){
            ll flow =0;
            
            while(bfs(s, t)){
                  fill(ptr.begin(), ptr.end(), 0);

                  while(ll pushed = dfs(s, t, LLONG_MAX)){
                        flow+= pushed;
                  }
            }
            return flow;
      }
};


int main(){
      int n, m;
      cin>>n>>m;
      Maxfl mf(n);
      for(int i=0;i< m; i++){
            int u, v, c;
            cin>>u>>v>>c;
            mf.addEdge(u, v, c);
      }
      int s, t;
      cin>>s>>t;
      cout<<mf.dinic(s, t);
      return 0;
}