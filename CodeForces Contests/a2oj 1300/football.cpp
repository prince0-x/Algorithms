#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      unordered_map<string, int>mp;
      for(int i=0;i<n;i++){
            string s;
            cin>>s;
            mp[s]++;
      }
      string ans;
      int maxi=-1;
      for(auto [k, v]:mp){
            if(v>maxi){
                  ans=k;
                   maxi = v;
            }
      }
      cout<<ans<<endl;
}