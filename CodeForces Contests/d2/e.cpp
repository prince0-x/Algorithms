#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

const int K = 18; // For Sparse Table, since 2^18 > 2e5

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> pref_xor(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref_xor[i + 1] = pref_xor[i] ^ a[i];
    }

    // Precompute next_dup[i] = smallest j > i where pref_xor[j] == pref_xor[i]
    vector<int> next_dup(n + 1, n + 1);
    map<int, int> last_pos;
    for (int i = n; i >= 0; --i) {
        if (last_pos.count(pref_xor[i])) {
            next_dup[i] = last_pos[pref_xor[i]];
        }
        last_pos[pref_xor[i]] = i;
    }

    // Build Sparse Table for Range Maximum Query on next_dup
    vector<vector<int>> st(n + 1, vector<int>(K));
    for (int i = 0; i <= n; i++) {
        st[i][0] = next_dup[i];
    }
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n + 1; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto query_max = [&](int l, int r) {
        if (l > r) return 0;
        int j = log2(r - l + 1);
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    };

    for (int k = 0; k < q; ++k) {
        int l, r;
        cin >> l >> r;

        // Condition 1: Total XOR sum of subarray a[l-1...r-1] must be 0
        bool xor_sum_ok = (pref_xor[r] == pref_xor[l - 1]);

        // Condition 2: All prefix XORs pref_xor[l-1...r-1] must be distinct
        // This is true if the next duplicate for any element in [l-1, r-1]
        // falls outside of this range.
        bool distinct_ok = (query_max(l - 1, r - 1) > r);
        
        // In the special case where all elements in the subarray are 0 initially,
        // it can be transformed to 0,1,2... as long as length > 1
        bool all_zero = true;
        if (!xor_sum_ok) {
            all_zero = false;
        } else {
             for(int i = l-1; i < r; ++i) {
                 if (a[i] != 0) {
                     all_zero = false;
                     break;
                 }
             }
        }
       

        if (all_zero || (xor_sum_ok && distinct_ok)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}