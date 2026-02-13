#include<bits/stdc++.h>
using namespace std;

void sieve(int m, vector<bool>&prime){
      for(int i=2;i*i<=m;i++){
            if(prime[i]){
                  for(int j=i*i; j<=m;j+=i){
                        prime[j]=false;
                  }
            } 
      }
}
int main(){
      int n,m;cin>>n>>m;
      vector<bool>prime(m+1, true);
      prime[0]=prime[1]=false;
      sieve(m, prime);
      for(int i=n+1;i<=m;i++){
            if(prime[i]){
                  cout<<(i==m?"YES\n":"NO\n");
                  return 0;
            }
      }
      cout<<"NO\n";
      return 0;
}