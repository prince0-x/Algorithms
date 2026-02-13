#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&arr){for (auto &i:arr)cout<<i<<" \n"[i == arr.back()];}
void solve(){
      int n, a, b;
      cin>>n>>a>>b;
      if(a+b > n){
            cout<<"NO\n";
            return;
      }
      vector<int>p1, p2(n);
      // store player2 as sorted one then change in player 1 accordingly
      for(int i=1;i<=n;i++){
            p2[i-1]=i;
      }
      // print(p2);

      // now focus only on player1
      //  a- match won by player 1
      // b match lose by player 1
      // n-(a+b) total tied match for player1
      int j=0;
      for(int i=b+1; i<=a+b; i++){
            p1.push_back(i);
            if(p2[j]>=p1[j]){
                  cout<<"NO\n";
                  return;
            }
            j++;
      }
      for(int i=1; i<=b; i++){
            p1.push_back(i);
            if(p2[j]<=p1[j]){
                  cout<<"NO\n";
                  return;
            }
            j++;
      }
      for(int i=a+b+1; i<=n;i++){
            p1.push_back(i);
            if(p2[j]!=p1[j]){
                  cout<<"NO\n";
                  return;
            }
            j++;
      }
      
      cout<<"YES\n";
      print(p1);
      print(p2);
      
}
int main(){
      int t;
      cin>>t;
      while(t--){
            solve();
      }
      return 0;
}