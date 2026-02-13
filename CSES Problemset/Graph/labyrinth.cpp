#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, m;
cin >> n >> m;
vector<string> grid(n);
for(int i=0;i<n;i++) cin >> grid[i];

vector<vector<int>> vis(n, vector<int>(m, 0));
vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}}; // U,D,L,R
vector<char> dirChar = {'U','D','L','R'};

pair<int,int> start, end;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='A') start={i,j};
        if(grid[i][j]=='B') end={i,j};
    }
}

queue<pair<int,int>> q;
q.push(start);
vis[start.first][start.second]=1;
bool found = false;

while(!q.empty() && !found){
    auto [r,c] = q.front(); q.pop();
    for(int k=0;k<4;k++){
        int nr = r + directions[k].first;
        int nc = c + directions[k].second;
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]!='#'){
            vis[nr][nc]=1;
            parent[nr][nc] = {r,c};
            q.push({nr,nc});
            if(grid[nr][nc]=='B'){
                found = true;
                break;
            }
        }
    }
}



if(found){
      string ans="";
      pair<int,int> cur = end;
      while(cur != start){
            auto p = parent[cur.first][cur.second];
            if(cur.first == p.first+1) ans += 'D';
            else if(cur.first == p.first-1) ans += 'U';
            else if(cur.second == p.second+1) ans += 'R';
            else ans += 'L';
            cur = p;
      }
      cout<<"YES\n";
      cout<<ans.size()<<"\n";
      reverse(ans.begin(), ans.end());
      cout << ans << endl;
}else{
      cout<<"NO\n";
}

return 0;
}