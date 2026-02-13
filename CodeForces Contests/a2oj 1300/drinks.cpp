#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      double ans=0;
      for(int i=0,x; i<n;i++){
            cin>>x;
            ans +=x;
      }
      cout<<fixed<<setprecision(12)<<double(ans/(1.0*n))<<"\n";
      return 0;
}