#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
      int n, k;
      cin>>n>>k;
      int ind = (ceil(n*1.0/2.0));
      // cout<<ind<<endl;
      if(k<=ind){
            cout<<1+(k-1)*2<<endl;
      }else{
            cout<<2+(k-ind-1)*2<<endl;
      }
}