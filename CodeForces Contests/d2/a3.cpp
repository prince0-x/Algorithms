#include <bits/stdc++.h>
#define int long long
using namespace std;
void solv(){
      int n;
      cin>>n;
      vector<int>a(n);
      for (int i = 0; i < n; i++){
            cin >> a[i];
      }
      map<int,int>mp;
      for (int x : a){
            mp[x]++;
      }
      int maxi = 0;
      for (auto &p : mp){
            maxi = max(maxi, p.second);
      }
      int ans = 0;
      for (int f = 1; f <= maxi; f++) {
            int cnt = 0;
            for (auto &p : mp) {
                  if (p.second >= f) cnt++;
            }
            ans = max(ans, f * cnt);
      }
      cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solv();
    }
    return 0;
}
