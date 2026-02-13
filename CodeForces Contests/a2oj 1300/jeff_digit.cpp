#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, five=0, zero =0;
      cin>>n;
       for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val==5)five++;
        else zero++;
    }
    if (five>=9 && zero>0){
      string ans=string((five/9)*9, '5')+string(zero,'0');
      cout<<ans<<"\n";
    }else if(zero==0){
      cout<<-1<<endl;
    }
    else cout << 0 << "\n";
      return 0;
}