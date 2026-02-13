#include <bits/stdc++.h>
using namespace std;
void solve(){
      int n;
      cin>>n;
      vector<int>a(n);
      for(int i=0;i<n;i++){
            cin>>a[i];
      }
      int ans=-1, cnt=0;
      for(auto x:a){
            if(x>=ans){
                  ans=x;
                  cnt++;
            }
      }
      cout<<n-cnt<<endl;
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}