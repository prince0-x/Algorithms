#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
      int n;
      cin>>n;
      // TLE
      // vector<int>arr(n+1);
      // for(int i=1;i<=n;i++){
      //       cin>>arr[i];
      // }
      // int q;
      // cin>>q;
      // int left =0, right=0;
      // while(q--){
      //       int val;cin>>val;
      //       int countl=0, countr=0;
      //       for(int i=1;i<=n;i++){
      //             if(arr[i]==val){
      //                   left+=countl+1;
      //                   break;
      //             }
      //             countl++;
      //       }
      //       for(int i=n;i>=1;i--){
      //             if(arr[i]==val){
      //                   right+=countr+1;
      //                   break;
      //             }
      //             countr++;
      //       }
      // }
      // cout<<left<<" "<<right<<"\n";


      // optimised
      unordered_map<int, int>minm, maxm;
      for(int i=1;i<=n;i++){
            int val;cin>>val;
            minm[val]= minm.count(val)? min(i, minm[val]):i;
            maxm[val]= maxm.count(val)? max(i, maxm[val]):i;
      }
      int q;
      cin>>q;
      ll left = 0, right=0;
      while(q--){
            int val;
            cin>>val;
            left+=minm[val];
            right+=n+1-maxm[val];
      }
      cout<<left<<" "<<right<<endl;
      return 0;
}