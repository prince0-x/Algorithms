#include <bits/stdc++.h>
using namespace std;
void solv() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    a.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            a.push_back(i + 1);
        }
    }
    a.push_back(n + 1);
    bool flag = true;
    for (int i = 0; i < a.size() - 1; ++i) {
        if (a[i + 1] - a[i] - 1 == 1){ 
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
//     make permutation
    vector<int> p(n + 1);
    for (size_t i = 0; i < a.size() - 1; ++i) {
        int u = a[i];
        int v = a[i + 1];
        if (v <= n) {
            p[v] = v;
        }
        int left = u + 1;
        int right = v - 1;
        if (left > right) { 
            continue;
        }
        p[right] = left;
        for (int j = left; j < right; ++j) {
            p[j] = j + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
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