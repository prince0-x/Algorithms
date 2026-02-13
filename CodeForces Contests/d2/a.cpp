// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--) {
//         ll n, a, b;
//         cin >> n >> a >> b;

//       if((n-max(a, b))%2==0 && n>=max(a,b)){
//             if(b>=a){cout<<"YES\n";}
//             else{
//                   if((a%2==0 && b%2==0) || (a%2==1 && b%2==1)){
//                         cout<<"YES\n";
//                   }else{
//                         cout<<"NO\n";
//                   }
//             }
//       }else{
//                   cout<<"NO\n";
//             }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll gcd_(ll a, ll m) {
    ll x, y;
    extended_gcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i){
            cin >>a[i];
        }

        ll x =k+1;
        ll p = -1;
        for (ll d = 2; d * d <= x; ++d) {
            if (x % d == 0) {
                p = d;
                break;
            }
        }
        if (p == -1) p = x;
        ll u = (k % p + p) % p;
        ll val = gcd_(u, p);
        for (int i = 0; i < n; ++i) {
            ll s = (a[i] % p + p) % p;
            ll w = (p - s) % p;
            ll m = ((__int128) w * val) % p;
            a[i] += m * k;
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << "\n";
    }

    return 0;
}