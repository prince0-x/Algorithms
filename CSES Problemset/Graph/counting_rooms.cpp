#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
      int n, m, ans=0;
      cin>>n>>m;
      vector<string>grid(n);
      vector<vector<int>>vis(n, vector<int>(m, 0));
      vector<vector<int>>directions={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
      auto issafe= [&](int a, int b){
            return a<n && b<m && a>=0 && b>=0;
      };

      
      for(int i=0;i<n;i++)cin>>grid[i];

      auto bfs=[&](int x ,int y){
            queue<pair<int, int>>q;
            q.push({x, y});
            vis[x][y]=1;
            while(!q.empty()){
                  auto [r, c]=q.front();
                  q.pop();
                  for(auto dir:directions){
                        int nr = r+dir[0], nc = c+dir[1];
                        if(issafe(nr, nc) && !vis[nr][nc] && grid[nr][nc]=='.'){
                              vis[nr][nc]=1;
                              q.push({nr, nc});
                        }
                  }
            }
      };
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(!vis[i][j] && grid[i][j]=='.'){
                        ans++;
                        bfs(i, j);
                  }
            }
      }
      cout<<ans<<endl;
      return 0;
}