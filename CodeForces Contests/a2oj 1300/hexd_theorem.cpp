#include<bits/stdc++.h>
using namespace std;
int main(){
      int n ;
      cin>>n;
      if(n==0){
            cout<<"0 0 0\n";
      }else if(n==1){
            cout<<"0 0 1\n";
      }else if(n==2){
            cout<<"0 1 1\n";
      }else if(n==3){
            cout<<"1 1 1\n";
      }
      else{
            vector<int> fib;
      int a = 0, b = 1;
       while (a <= 1000000000) {
        fib.push_back(a);
        int c = a + b;
        a = b;
        b = c;
       }
       int ind =lower_bound(fib.begin(), fib.end(), n)-fib.begin();
       cout<<fib[ind-4]<<" "<<fib[ind-3]<<" "<<fib[ind-1]<<"\n";
      }
      return 0;
}