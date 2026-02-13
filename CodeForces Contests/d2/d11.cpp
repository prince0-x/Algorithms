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
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}

void solv(){
      int n;
      cin>>n;
      vector<int>a(n+1),b(n+1);
      for(int i=1;i<=n;i++){
        cin>>b[i];
      }
      for(int i=1;i<=n;i++){
        a[i]=1;
        for(int j=1;j<i;j++){
            if(b[j]<=b[i]){
                a[i]++;
            }
        }
        for(int j=i+1;j<=n;j++){
            if(b[j]<b[i]){
                a[i]++;
            }
        }
      }

      vvvi dp(2, vvi(n+1, vi(n+1, 0)));
      dp[0][0][0]=1;

      int curr=0;
      for(int i=1;i<=n;i++){
        int x = a[i];
        curr^=1;
        for(int j=0;j<=n;j++){
            for(int q=0;q<=n;q++){
                dp[curr][j][q] = dp[curr^ 1][j][q];
            }
        }
        for(int j=0;j<=n;j++){
            for(int q=0;q<=j;q++){
                if(dp[curr^1][j][q]==0)continue;
                if(j > x and x > q){
                    addself(dp[curr][j][x],dp[curr^1][j][q]);
                }
                else if(x>j){
                    addself(dp[curr][x][q],dp[curr^1][j][q]);
                }
            }
        }
      }
      int ans=0;
      for(int j=0;j<=n;j++){
            for(int q=0;q<=n;q++){
                addself(ans,dp[curr][j][q]);
            }
      }
      cout<<ans<<"\n";

}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solv();
      }
      return 0;
}