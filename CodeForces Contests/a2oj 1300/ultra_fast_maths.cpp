#include<bits/stdc++.h>
using namespace std;
int main(){
      string s1, s2, s3;
      cin>>s1>>s2;
      s3 = "";
      for(int i=0;i<s1.size();i++){
            s3+=(s1[i]==s2[i])?"0":"1";
      }
      cout<<s3<<endl;
      return 0;
}