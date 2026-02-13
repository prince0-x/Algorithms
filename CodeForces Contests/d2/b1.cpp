#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void solv() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    long long total = 0;
    int j = 0;
    for (int i = 0; i < k; ++i) {
        int v_siz = b[i];
        if (j + v_siz > n) {
            break;
        }
        if (v_siz == 1) {
            j++;
        } else {
            total += pref[j + v_siz - 1] - pref[j];
            j += v_siz;
        }
    }
    if (j < n) {
        total += pref[n] - pref[j];
    }
    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solv();
    }
    return 0;
}