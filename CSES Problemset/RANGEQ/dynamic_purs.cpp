#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, q;
vector<int> bit;

void add(int idx, int delta){
    for(; idx <= n; idx += (idx & -idx)){
        bit[idx] += delta;
    }
}

int find_(int idx){
    int ans = 0;
    for(; idx > 0; idx -= (idx & -idx)){
        ans += bit[idx];
    }
    return ans;
}

int query(int l, int r){
    return find_(r) - find_(l-1);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    bit.resize(n+2, 0);

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;
        add(i, val);
    }

    for(int i=0; i<q; i++){
        int typ;
        cin >> typ;
        if(typ == 1){
            int ind, nval;
            cin >> ind >> nval;
            int oldVal = query(ind, ind);
            int delta = nval - oldVal;
            add(ind, delta);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }
    return 0;
}
