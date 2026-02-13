#include<bits/stdc++.h>
using namespace std;
int main(){
      string s;
      cin>>s;
      for(auto ch:s){
            if(ch =='H' || ch =='Q' || ch =='9'){
                  cout<<"YES\n";
                  return 0;
            }
      }
      cout<<"NO\n";
      return 0;
}