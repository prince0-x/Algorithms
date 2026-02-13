#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
      int n;
      cin>>n;
      vector<ll>arr(n);
      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      ll total = accumulate(arr.begin(), arr.end(), 0LL);
      ll minDiff = LLONG_MAX;
      for(int mask=0; mask<(1<<n); mask++){
            ll sum1 =0;
            for(int i=0; i<n;i++){
                  if(mask&(1<<i)){
                        sum1+=arr[i];
                  }
            }
            minDiff= min(minDiff, llabs(total-2*sum1));
      }
      cout<<minDiff<<endl;
      return 0;
}