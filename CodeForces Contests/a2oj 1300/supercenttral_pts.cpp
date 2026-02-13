#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      vector<vector<int>>pts;
      
      for(int i=0;i<n;i++){
            int x, y;
            cin>> x>>y;
            pts.push_back({x, y});
      }
      int ans =0;
      for(auto pt :pts){
            bool left=0, right=0, up=0, down =0;
            for(int i=0;i<n;i++){
                  if(pt[0]==pts[i][0] && pt[1]>pts[i][1])down = true;
                  if(pt[0]==pts[i][0] && pt[1]<pts[i][1])up = true;
            }
            for(int i=0;i<n;i++){
                  if(pt[1]==pts[i][1] && pt[0]>pts[i][0])right  = true;
                  if(pt[1]==pts[i][1] && pt[0]<pts[i][0])left = true;
            }
            ans+=(left && right && up && down);
      }
      cout << ans << "\n";
      return 0;
}