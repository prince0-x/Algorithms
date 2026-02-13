#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while (t--) {
        int n, q;cin >> n >> q;
        string opr;
        cin >> opr;
        for (int i = 0; i < q; i++) {
            long long x, ans=0;
            cin>>x;
            int cntb = count(opr.begin(), opr.end(), 'B');
            if (!cntb) {
                  cout << x << endl;
                  continue;
            }
            int idx = 0;
            while (x >0){
                char op=opr[idx];
                if (op=='B') x/=2;
                else if (op == 'A') x -= 1;
                ans++;
                idx++;
                if (idx == n) idx = 0;  
            }
            cout<<ans<<endl;
        }
    }
}
