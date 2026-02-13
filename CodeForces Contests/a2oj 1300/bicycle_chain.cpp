#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    unordered_map<int,int> freq; 
    int maxi = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] % a[i] == 0) { 
                int val = b[j] / a[i];
                freq[val]++;
                maxi = max(maxi, val);
            }
        }
    }

    cout << freq[maxi] << "\n";
    return 0;
}
