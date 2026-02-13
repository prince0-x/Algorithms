#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, q;
      cin >> n >> q;
      vector<vector<int>>up(__lg(n)+1, vector<int>(n+1, -1));
      for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            up[0][i]=x;
      }
      for(int k=1;k < __lg(n)+1;k++){
            for(int i=1; i<=n;i++){
                  if(up[k-1][i]!=-1){
                        up[k][i] = up[k-1][up[k-1][i]];
                  }else{
                        up[k][i]=-1;
                  }
            }
      }
      while(q--){
            int node, k;
            cin>>node>>k;
            for (int bit = 0; bit < __lg(n)+1; bit++) {
            if (k & (1 << bit)) {
                node = up[bit][node];
                if (node == -1) break;
            }
        }
        cout << node << "\n";
      }
      return 0;
}