#include <bits/stdc++.h>
using namespace std;

int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size() << "\n";
}
