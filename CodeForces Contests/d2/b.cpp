#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool find_(ll n, ll a, ll b, ll x, ll left, ll right) {
    ll left1 = x;
    ll right1 = x + a - 1;
    ll left2 = n - x - a + 2;
    ll right2 = n - x + 1;
    if(left1 > left2) {
        swap(left1, left2);
        swap(right1, right2);
    }
    if(right1 < left2) {
        if(!(left1 >= left && right1 <= right && left2 >= left && right2 <= right)) 
            return true;
        else 
            return false;
    } else {
        bool ok = true;
        if(left1 < left2 - 1) {
            if(!(left1 >= left && left2 - 1 <= right)) ok = false;
        }
        if(right1 + 1 < right2) {
            if(!(right1 + 1 >= left && right2 <= right)) ok = false;
        }
        return ok;
    }
}
void solve(){
      ll n, a, b;
      cin >> n >> a >> b;
      if((n - b) % 2 != 0) {
            cout << "NO\n";
            return;
      }
      ll y = (n - b + 2) / 2;
      ll left = y;
      ll right = y + b - 1;

      if((n - a) % 2 == 0) {
            cout << "YES\n";
            return;
      }
      set<ll> st;
      st.insert(1);
      st.insert(max(1LL, n - a + 1));
      vector<ll> arr;
      arr.push_back(left);
      arr.push_back(right);
      arr.push_back(left - (a - 1));
      arr.push_back(right - (a - 1));
      arr.push_back(n - left + 1);
      arr.push_back(n - right + 1);
      arr.push_back(n - left + 2);
      arr.push_back(n - right + 2);
      arr.push_back((n - a + 2) / 2);
      arr.push_back((n - a + 3) / 2);
      for(auto z : arr) {
            for(int d=-2; d<=2; d++) {
                  st.insert(z + d);
            }
      }

      bool flag = false;
      ll mini = 1, maxi = n - a + 1;
      for(auto x : st) {
            if(x < mini || x > maxi) continue;
            if(find_(n, a, b, x, left, right)) {
                  flag = true;
                  break;
            }
      }
      cout << (flag ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}