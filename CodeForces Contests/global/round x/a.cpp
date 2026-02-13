#include<bits/stdc++.h>
using namespace std;
void solv(){
      int a, b;
      cin>>a>>b;
      if (a < b) {
            cout << 2 << '\n';
      } else if (a == b) {
            cout << -1 << '\n';
      } else {
            if (b == 1 || a - b == 1) cout << -1 << '\n';
            else cout << 3 << '\n';
      }
}
int main(){
      int t=1;
      cin>>t;
      while(t--){
            solv();
      }
      return 0;
}