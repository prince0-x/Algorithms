#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mod 1000000007

void addself(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

int n;
const int NMAX = 3000;
int bit_lin[NMAX+5][NMAX+5], bit_col[NMAX+5][NMAX+5];

void update_lin(int lin, int pos, int val){
    pos++;
    for(int i = pos; i <= n+1; i += (i & -i)){
        addself(bit_lin[lin][i], val);
    }
}

void update_col(int col, int pos, int val){
    pos++;
    for(int i = pos; i <= n+1; i += (i & -i)){
        addself(bit_col[col][i], val);
    }
}

int query_lin(int lin, int pos){
    pos++;
    int rr = 0;
    for(int i = pos; i > 0; i -= (i & -i)){
        addself(rr, bit_lin[lin][i]);
    }
    return rr;
}

int query_col(int col, int pos){
    pos++;
    int rr = 0;
    for(int i = pos; i > 0; i -= (i & -i)){
        addself(rr, bit_col[col][i]);
    }
    return rr;
}

void solv(){
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> b[i];

    // Convert to equivalent permutation
    for(int i=1;i<=n;i++){
        a[i] = 1;
        for(int j=1;j<i;j++){
            if(b[j] <= b[i]) a[i]++;
        }
        for(int j=i+1;j<=n;j++){
            if(b[j] < b[i]) a[i]++;
        }
    }

    // reset BIT arrays
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            bit_lin[i][j] = bit_col[i][j] = 0;
        }
    }

    // base case
    update_lin(0, 0, 1);
    update_col(0, 0, 1);

    for(int i=1;i<=n;i++){
        vector<pair<int, pi>> buffs;
        int x = a[i];

        // case when ai = mp
        for(int j = x+1; j <= n; j++){
            int lin = j, col = x;
            int buff = query_lin(j, x-1);
            buffs.pb({buff, {lin, col}});
        }

        // case when ai = m
        for(int q = 0; q < x; q++){
            int lin = x, col = q;
            int buff = query_col(q, x-1);
            buffs.pb({buff, {lin, col}});
        }

        for(auto &it : buffs){
            update_lin(it.second.first, it.second.second, it.first);
            update_col(it.second.second, it.second.first, it.first);
        }
    }

    int ans = 0;
    for(int lin=0; lin<=n; lin++){
        addself(ans, query_lin(lin, n));
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t=1;
    cin >> t;
    while(t--){
        solv();
    }
    return 0;
}
