#include<bits/stdc++.h>
using namespace std;
void solv(){
      int n;
      cin>>n;
      for(int i=n;i>=1;i--)cout<<i<<" ";
      cout<<n<<" ";
      for(int i=1;i<n;i++)cout<<i<<" ";
      cout<<"\n";
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int t=1;
      cin>>t;
      while(t--){
            solv();
      }
      return 0;
}