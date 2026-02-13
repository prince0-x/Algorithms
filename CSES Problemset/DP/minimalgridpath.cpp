#include <bits/stdc++.h>
using namespace std;



int main() {
  cin.tie(0); // these lines make difference
  ios_base::sync_with_stdio(0);  // these lines make difference
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    vector<vector<int>>hash(n+1, vector<int>(n+1, n+1));
    for(int diag = 2*n-2; diag>=0; diag--){
      vector<pair<int, int>>v;
      for(int row =0; row<n; row++){
        int col = diag - row;
        if(0<= col && col< n){
          v.emplace_back(row, col);
        }
      }
      int k = (int)v.size();
      vector<pair<int, int>>order(k);
      for(int i=0;i<k;i++){
        auto [row, col] = v[i];
        int state = (grid[row][col]-'a')*(n+2)+min(hash[row+1][col], hash[row][col+1]);
        order[i]={state, row};
      }
      sort(order.begin(), order.end());
      int nxt =0;
      for(int i=0; i<(int)order.size(); i++){
        if(i==0 || order[i].first != order[i-1].first){
          nxt++;
        }
        int row=order[i].second;
        int col = diag-row;
        hash[row][col]=nxt;
      }
    }

    int row =0, col =0;
    cout<<grid[row][col];
    while(row<n-1 || col<n-1){
      if(hash[row+1][col]<hash[row][col+1]){
        row++;
      }else{
        col++;
      }
      cout<<grid[row][col];
    }
    cout<<"\n";
    return 0;
}
