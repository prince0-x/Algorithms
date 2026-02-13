#include <bits/stdc++.h>
using namespace std;

void help(long long l, long long r, map<long long, long long>& mp){
    if (l > r){
        return;
    }
    if (l == r){
        mp[l] = l;
        return;
    }
    long long k = (r > 0) ? floor(log2(r)) : -1;
    if (k == -1){ 
        mp[l] = l;
        return;
    }
    long long p2k = 1LL << k;
    if (l >= p2k){
        map<long long, long long> sub_mp;
        help(l - p2k, r - p2k, sub_mp);
        for (auto const& [key, val] : sub_mp){
            mp[key + p2k] = val + p2k;
        }
    } else {
        long long m = (p2k << 1) - 1;
        long long L = max(l, m - r);
        long long R = min(r, m - l);
        if (L <= R){
            for (long long i = L; i <= R; ++i){
                mp[i] = m - i;
            }
        }
        help(l, L - 1, mp);
        help(R + 1, r, mp);
    }
}
void solv(){
    long long l, r;
    cin >> l.> r;
    int n = r - l + 1;
    map<long long, long long>mp;
    help(l, r, mp);
    vector<long long> a(n);
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        long long temp1 = l + i;
        long long temp2 = mp[temp1];
        a[i] = temp2;
        ans += temp1 | temp2;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i){
        cout << a[i] <<" ";
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--){
        solv();
    }
    return 0;
}