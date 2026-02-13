#include <bits/stdc++.h>
using namespace std;
#define vi vector<long long>
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vi odds, evens;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if (x & 1) odds.pb(x);
        else evens.pb(x);
    }
    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());
    int o = odds.size();
    int e = evens.size();
    vi pref_e(e + 1, 0);
    for (int i =1; i <=e; i++)pref_e[i] = pref_e[i - 1] + evens[i - 1];
    if (o == 0){
        for (int k =0; k <n; k++)cout << "0 ";
        cout << "\n";
        return;
    }
    ll best_odd = odds[0];
    for (int k =1; k <=n; k++){
        int take_evens = min(k - 1, e);
        int waste_odds = (k - 1) - take_evens;
        if (waste_odds % 2 != 0) {
            take_evens--;
            waste_odds++;
        }
        if (take_evens >=0 && (1 + waste_odds) <=o) {
            cout <<best_odd + pref_e[take_evens]<< " ";
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--){
      solve();
    }
    return 0;
}