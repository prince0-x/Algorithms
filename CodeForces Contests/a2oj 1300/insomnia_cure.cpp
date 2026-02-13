#include<bits/stdc++.h>
using namespace std;
int lcm_calc(int a, int b){
      return (a/__gcd(a, b))*b;
}
int main(){
      int a, b, c, d, x;
      cin>>a>>b>>c>>d>>x;
      int ans=0;
      vector<int>nums={a, b, c, d};
      for(int mask=1;mask<(1<<4);mask++){
            int cur_lcm=1, bits=0;
            for(int i=0;i<4;i++){
                  if(mask &(1<<i)){
                        cur_lcm= lcm_calc(cur_lcm,nums[i]);
                        bits++;
                  }
            }
            int divisible = x / cur_lcm;
            if (bits % 2 == 1)
                  ans += divisible;
            else
                  ans -= divisible;
      }
      cout<<ans<<"\n";
      return 0;
}