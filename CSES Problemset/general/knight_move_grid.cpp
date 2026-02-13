#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
      int n;
      cin>>n;
      auto issafe=[&](int a, int b){
            return a>=0 && b>=0 && b<n &&a<n;
      };
      vector<vector<int>>grid(n, vector<int>(n, 0)), vis(n, vector<int>(n, 0));
      vector<vector<int>>directions={{1, 2},{-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
      queue<tuple<int, int, int>>q;//x, y, steps
      q.push({0, 0, 0});
      vis[0][0] = true;
      grid[0][0]=0;
      while(!q.empty()){
            auto [x, y ,steps]= q.front();
            q.pop();
            for(auto dir:directions){
                  int nx = x+dir[0];
                  int ny = y+dir[1];
                  if(issafe(nx, ny) && !vis[nx][ny]){
                        vis[nx][ny]=1;
                        grid[nx][ny]=steps+1;
                        q.push({nx, ny, steps+1});
                  }
            }
      }
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  cout<<grid[i][j]<<" ";
            }
            cout<<endl;
      }
}