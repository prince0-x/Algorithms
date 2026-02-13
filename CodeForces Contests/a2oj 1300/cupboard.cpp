#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, ans1=0, ans2=0;
      cin>>n;
      for(int i=0;i<n;i++){
            int x, y;
            cin>>x>>y;
            ans1+=(x==1);
            ans2+=(y==1);
      }
      cout<<min(ans1, n-ans1)+min(ans2, n-ans2)<<"\n";
      return 0;
}