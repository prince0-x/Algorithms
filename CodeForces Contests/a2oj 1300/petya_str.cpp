#include<bits/stdc++.h>
using namespace std ;
int main(){
      string s1, s2;
      cin>>s1>>s2;
      for(auto&ch:s1){
            ch = tolower(ch);
      }
      for(auto&ch:s2){
            ch = tolower(ch);
      }
      if(s1>s2){
            cout<<1<<"\n";
      }else if(s1<s2){
            cout<<-1<<"\n";
      }else{
            cout<<0<<"\n";
      }
      return 0;
}