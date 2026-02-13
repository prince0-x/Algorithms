#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pi pair<int, int>
#define vpi vector<pi>

void solve(){
      int n;ll k;
      cin>> n>>k;
      vll a(n+1,0), pref(n+1, 0);
      for(int i=0,x;i<n; i++){
        cin>>x;
        a[x]++;
      }
      for(int i=1;i<=n; i++){
        pref[i]+=pref[i-1]+a[i];
      }
      
      for(int d=n; d>=1; d--){
        ll limit=min((ll)n, (ll)4*d-1);
        ll total = pref[limit];
        ll curr=0;
        if((ll)d<=n){
            curr+=a[d];
        }
        if((ll)2*d <= n){
            curr+=a[2*d];
        }
        if((ll)3*d <=n){
            curr+=a[3*d];
        }
        ll cost = total - curr;
        if(cost<=k){
            cout<<d<<endl;
            return ;
        }
      }
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