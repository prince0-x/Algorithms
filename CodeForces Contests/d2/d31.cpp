#include<bits/stdc++.h>
using namespace std;
void help(int l, int r,vector<int>&a) {
    if (l > r) {
        return;
    }
    int lg = (r > 0) ? floor(log2(r)) : -1;
    if (lg == -1) {
        a[l] = l;
        return;
    }
    int m = (1 << (lg + 1)) - 1;
    int pivot = m - r;
    for (int i = pivot; i <= r; ++i) {
        a[i] = m - i;
    }
    help(l, pivot - 1, a);
}
void solv() {
    int l, r;
    cin >> l>>r;
    int n = r - l + 1;
    vector<int>a(r + 1);
    help(l, r, a);
    long long ans = 0;
    vector<int> b(n);
    for (int i = 0; i < n; ++i){
        int temp = l + i;
        b[i] = a[temp];
        ans += (long long)temp | b[i];
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i){
         cout << b[i]<<" ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solv();
    }
    return 0;
}

