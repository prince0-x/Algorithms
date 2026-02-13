#include<bits/stdc++.h>
using namespace std;
vector<int>parent, rank_;
int find_(int u){
      if(parent[u] != u){
            return parent[u]= find_(parent[u]);
      }
      return parent[u];
}
bool union_(int u, int v){
      int rootu = find_(u);
      int rootv= find_(v);
      if(rootu == rootv){
            return false;
      }
      if(rank_[rootu] > rank_[rootv]){
            parent[rootv]=rootu;
      }else if(rank_[rootu]<rank_[rootv]){
            parent[rootu] = rootv;
      }else{
            parent[rootv]=rootu;
            rank_[rootu]++;
      }
      return true;
}
int main(){
      int n, m;
      cin>>n>>m;
      
      auto cmp = [](const tuple<int,int,int>& t1, const tuple<int,int,int>& t2) {
            return get<0>(t1) <= get<0>(t2); 
      };

      priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            decltype(cmp)
      > pq(cmp);

      for(int i=0;i<n-1;i++){
            int x, y, w;
            cin>>x>>y>>w;
            pq.push({w, x, y});
      }

      parent.resize(n+1);
      rank_.resize(n+1, 1);
      for(int i=0;i<=n;i++){
            parent[i]=i;
      }

      bool flag= true;
      for(int i=0;i<m;i++){
            int x, y;
            cin>>x>>y;       // problem here
           if(!union_(x, y)){
            flag = false;
            }
      }

      int ans=0;
      if(flag){
            while(!pq.empty()){
                  auto [w, x, y]=pq.top();
                  pq.pop();
                  if(union_(x, y)){
                        ans+=w;
                  }
            }
      }

      if(flag){
            cout<<ans<<"\n";
      }else{
            cout<<-1<<"\n";
      }

      return 0;
}