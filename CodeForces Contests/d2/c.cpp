#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long s = 0; 
    long long p = 0;   
    for (int i = 0; i < n; i += 2) {
        long long c = arr[i];
        long long x;
        if (i == 0) {
            if (i + 1 < n)
                x = min(arr[i], arr[i + 1]);
            else
                x = arr[i];
        } else {
            long long l = arr[i - 1] - p;
            if (i + 1 < n) {
                long long m = min(arr[i], arr[i + 1]);
                x = min(m, l);
            } else {
                x = min(arr[i], l);
            }
        }
        s+=c-x;
        p =x;
    }
    cout <<s<<"\n";
}

int main() {
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}