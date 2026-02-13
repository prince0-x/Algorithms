#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>dp;
vector<int> ans, s, t;

void solve(){
      dp.resize(n+1, vector<int>(m+1));
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(s[i-1]==t[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                  }else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                  }
            }
      }
      int i= n, j = m;
      while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                  ans.push_back(s[i-1]);
                  i--;
                  j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                  i--;
            }else{
                  j--;
            }
      }
}

void printEditOperations() {
    int i = s.size();
    int j = t.size();

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
            cout << "Match: " << s[i - 1] << "\n";
            i--;
            j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            cout << "Replace '" << s[i - 1] << "' with '" << t[j - 1] << "'\n";
            i--;
            j--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            cout << "Insert '" << t[j - 1] << "'\n";
            j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            cout << "Delete '" << s[i - 1] << "'\n";
            i--;
        }
    }
}

int main(){
      cin>>n>>m;
      s.resize(n);
      t.resize(m);
      for(int i=0;i<n;i++){
            cin>>s[i];
      }
      for(int i=0;i<m;i++){
            cin>>t[i];
      }
      solve();
      reverse(ans.begin(), ans.end());
      cout<<ans.size()<<"\n";
      for(auto &i:ans){
            cout<<i<<" ";
      }
      cout<<"\n";
      return 0;
}