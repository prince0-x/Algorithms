#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, m;
      cin>>n>>m;
      int ansi=-1, ans = 0;
      for(int i=1;i<=n;i++){
            int val;
            cin >>val;
            if(ceil((1.0*val)/(1.0*m)) >= ans){
                  ans= int(ceil((1.0*val)/(1.0*m)));
                  ansi = i;
            }
      }
      cout<<(ansi)<<"\n";
      return 0;
}