#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      int n, k;
      cin>>n>>k;
      vi a(n);
      for(int i=0;i<n;i++){
            cin>>a[i];  
      }
      // case 1
      for(auto i:a){
            if(i==k){
                  cout<<0<<"\n";
                  return;
            }
      }
      // case 2
      if(k==4){
            int ans=INT_MAX;
            for(auto i:a){
                  if(i%k==0){
                        cout<<0<<"\n";
                        return;
                  }else{
                        ans=min(ans, abs((i%k)-k));
                  }
            }
            int even=0;
            for(auto i:a){
                  if(i%2==0){
                       even++;
                  }
            }
            if(n>=2){
                  ans=min(ans, max(0, 2-even));
            }
            cout<<ans<<endl;
            //case 3
      }else{
            int ans=INT_MAX;
            for(auto i:a){
                  if(i%k==0){
                        cout<<0<<"\n";
                        return;
                  }else{
                        ans=min(ans, abs((i%k)-k));
                  }
            }
            cout<<ans<<"\n";
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