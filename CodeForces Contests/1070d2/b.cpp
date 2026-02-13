#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      int n;
      string s1;

      cin>>n>>s1;
      string s=s1+s1;
      int cnt=0, ans=0;
      for(auto c:s){
            if(c=='0'){
                  cnt++;
            }else{
                  ans= max(ans, cnt);
                  cnt=0;
            }
      }
      cout<<ans<<endl;
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}