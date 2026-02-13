#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      int ans =0, curr=0;
      for(int i=0;i<n;i++){
            int x, y;
            cin>>x>>y;
            curr+=(y-x);
            ans= max(ans, curr);
      }
      cout<<ans<<"\n";
      return 0;
}