#include<bits/stdc++.h>
using namespace std;
string toBinary(int num, int n) {
      string s;
      for (int i = n - 1; i >= 0; --i) {
            s += ((num >> i) & 1) ? '1' : '0';
      }
      return s;
}
void solve(int n){
      for(int i=0; i<(1<<n);i++){
            cout<<toBinary(i^(i>>1), n)<<endl;
      }
}
int main(){
      int n;
      cin>>n;
      solve(n);
      return 0;
}