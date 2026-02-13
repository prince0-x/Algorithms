#include<bits/stdc++.h>
using namespace std;
void solve(int disc, int from_d, int to_d, int aux_d){
      if(disc==0)return;
      solve(disc-1, from_d, aux_d, to_d);
      cout<<from_d<<" "<<to_d<<"\n";
      solve(disc-1, aux_d, to_d, from_d);
      
}
int main(){
      int n;cin>>n;
      cout<<(1<<n)-1<<endl;
      solve(n, 1, 3, 2);
      return 0;
}