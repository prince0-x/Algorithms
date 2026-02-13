#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;cin>>n;
      vector<int>arr(n);
      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      int f=-1, s=-1, diff=INT_MAX;
      for(int i=0;i<n+1;i++){
            if(diff > abs(arr[i%n]-arr[(i+1)%n])){
                  diff = abs(arr[i%n]-arr[(i+1)%n]);
                  f=i+1;
                  s= (i+2);
            }
      }
      cout<<f<<" "<<(s > n ? 1 : s)<<"\n";
      return 0;
}