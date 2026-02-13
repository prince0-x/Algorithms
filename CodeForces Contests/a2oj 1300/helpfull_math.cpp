#include<bits/stdc++.h>
using namespace std;
int main(){
      string s1, s2="";
      cin>>s1;
      for(auto ch:s1){
            if(ch!='+')s2+=ch;
      }
      sort(s2.begin(), s2.end());
      s1="";
      for(auto ch:s2){
            s1 += ch;
            s1 += '+';
      }
      s1.pop_back();
      cout<<s1<<"\n";
}