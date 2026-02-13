#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;cin>>n;
      vector<int>arr(n);
      for(auto&x:arr)cin>>x;
      int bst=arr[0], wrst=arr[0], ans=0;
      for(int i=1;i<arr.size(); i++){
            if(bst<arr[i]){
                  bst = arr[i];
                  ans++;
            }else if(wrst>arr[i]){
                  wrst = arr[i];
                  ans++;
            }
      }
      cout<<ans<<"\n";
      return 0;
}