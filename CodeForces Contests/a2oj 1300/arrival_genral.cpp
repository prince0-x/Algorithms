#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, minpos=-1, maxpos=INT_MAX, mini = INT_MAX, maxi = INT_MIN;
      cin>>n;
      for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x<=mini){
                  minpos= x==mini?max(minpos, i):i;
                  mini = x;
            }
            if(x>=maxi){
                  
                  maxpos= x==maxi?min(maxpos, i):i;
                  maxi = x;
            }
      }
      if(maxpos>minpos){
            cout<<n+maxpos-minpos-2<<endl;
      }else{
            cout<<n+maxpos-minpos-1<<endl;
      }
      return 0;
}