#include<bits/stdc++.h>
#define int long long
using namespace std ;
int32_t main(){
      int n,k;
      cin>>n>>k;
      int cur=1, ans = 0;
      for(int i=1;i<=k;i++){
            int val;cin>>val;
            if(val<cur){
                  ans+=(n-cur)+val;
            }else{
                  ans+=val-cur;
            }
            cur=val;
      }
      cout<<ans<<"\n";
      return 0;
}