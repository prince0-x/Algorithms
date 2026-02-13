#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cando(double num, vector<int>&a, int cnt){
      int sum=0;
      for(auto &i:a){
            sum+=int(i/num);
      }
      return sum>=cnt;
}

void solve(){
      ll n, m;
      cin>>n>>m;
      vector<int>a(n);
      for(auto &i:a)cin>>i;
      double low=0.0, high=1e9, ans=0.0;
      while(high-low>1e-7){
            double mid=(low+high)/2.0;
            if(cando(mid, a, m)){
                  ans=mid;
                  low=mid;
            }else{
                  high = mid;
            }
      }
      cout<<fixed<<setprecision(1)<<ans<<"\n";
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



