#include <bits/stdc++.h>
using namespace std;

void solve(){
      string s;
      cin>>s;
      for(int i=0; i<(int)s.size(); i++){
            int data = (int)(s[i]-'0');
            if(i==0 && data==9)continue;
            s[i]= (char)('0'+ min(data, 9-data));
      }
      cout <<s<<endl;
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            solve();
      }
      return 0;
}