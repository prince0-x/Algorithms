#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

void add_selft(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

int main(){
    int N = 1000001;
    int dp[N][2] = {0};
    dp[0][0] = dp[0][1] = 1;

    for(int i = 0; i < N-1; i++){
        add_selft(dp[i+1][0], 2 * dp[i][0] % mod);
        add_selft(dp[i+1][1], dp[i][0]);
        add_selft(dp[i+1][0], dp[i][1]);
        add_selft(dp[i+1][1], 4LL * dp[i][1] % mod);
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int answer = (dp[n-1][0] + dp[n-1][1]) % mod;
        cout << answer << "\n";
    }
    return 0;
}
