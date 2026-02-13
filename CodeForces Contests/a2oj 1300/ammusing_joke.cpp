#include<bits/stdc++.h>
using namespace std;
int main(){
      string s1, s2, s3;
      cin>>s1>>s2>>s3;
      unordered_map<char, int>m1, m2;
      for(auto ch:s1){
            m1[ch]++;
      }
      for(auto ch:s2){
            m1[ch]++;
      }
      for(auto ch:s3){
            m1[ch]--;
            if(m1[ch]==0){
                  m1.erase(ch);
            }
      }
      
      cout<<(m1.size()==0?"YES\n":"NO\n");
      return 0;
}