#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Count frequency of each number
    map<long long, long long> freq;
    for(auto x : a) freq[x]++;

    // Use max heap: {value, count}
    priority_queue<pair<long long, long long>> pq;
    for(auto &[value, count] : freq) {
        pq.push({value, count});
    }

    long long alice = 0, bob = 0;
    bool aliceTurn = true;

    while(!pq.empty()) {
        auto [value, count] = pq.top(); pq.pop();

        long long points = count;
        if(aliceTurn) alice += points;
        else bob += points;

        // Decrement value
        if(value - 1 > 0) {
            pq.push({value - 1, count});
        }

        aliceTurn = !aliceTurn;
    }

    cout << alice << " " << bob << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}
