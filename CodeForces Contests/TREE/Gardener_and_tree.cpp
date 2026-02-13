#include<bits/stdc++.h>
using namespace std;
void solve(){
      int n, k;
      cin >> n >> k;
      
      vector<vector<int>>adj(n + 1);
      vector<int>indegree(n + 1);

      for(int i=1;i<n;i++){
            int x, y;
            cin >> x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            indegree[x]++;
            indegree[y]++;
      }

      queue<int>q;

      for(int i=1;i<=n;i++){
            if(indegree[i]==1){
                  q.push(i);
                  indegree[i]=0;
            }
      }

      int timer =0;
      while(!q.empty()){
            if(timer == k){
                  break;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
                  int node = q.front();
                  q.pop();
                  for(auto nbr:adj[node]){
                        indegree[nbr]--;
                        if(indegree[nbr]==1){
                              q.push(nbr);
                              indegree[nbr]--;
                        }
                  }
            }
            timer++;
      }


      int ans= q.size();
      
      for(int i=1;i<=n;i++ ){
            if(indegree[i]>0)ans++;
      }
      cout<<ans<<endl;
}
int main(){
      int t;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}