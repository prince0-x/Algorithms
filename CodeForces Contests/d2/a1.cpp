#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
void solv() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0;
    int r = n - 1;
    for (int k = 1; k <= n; ++k) {
            if (a[l] == k) {
                  l++; 
            } else if (a[r] == k) {
                  r--;
            } else {
                  cout << "NO\n";
                  return;
            }
      }
    cout << "YES\n";
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