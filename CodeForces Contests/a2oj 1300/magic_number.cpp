#include<bits/stdc++.h>
using namespace std;
int main(){
      int cnt =0;
      bool flag= true, nondig_flag=true;
      string s;
      cin>>s;
      char prev=' ';
      if(s[0]=='4'){
            cout<<"NO\n";
            return 0;
      }
      
      for(auto ch:s){
            if(ch != '1' && ch != '4'){
                  
                  nondig_flag = false;
                  break;
            }
            if(ch==prev && ch == '4'){
                  prev = ch;
                  cnt++;
                  if(cnt>2){
                        flag= false;
                        break;
                  }
            }else{
                  cnt=1;
                  prev = ch;
            }
      }

      if(flag && nondig_flag){
            cout<<"YES\n";
      }else{
            cout<<"NO\n";
      }

      return 0;
}