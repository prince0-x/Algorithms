#include<bits/stdc++.h>
using namespace std;
struct pt{
      double x=0,y=0;
};
int n;
double calcarea(vector<pt>&points){
      double area=0.0;
      for(int i=0;i<n;i++){
            pt p1=points[i], p2=points[(i+1)%n];
            area+=(p1.x*p2.y)-(p2.x*p1.y);
      }
      return abs(area)*0.5;
}
int main(){
      cin>>n;
      vector<pt>points(n);
      for(int i=0;i<n;i++){
            cin>>points[i].x>>points[i].y;
      }
      double perimeter=0.0, min_edg=numeric_limits<double>::max();
      for(int i=0;i<n;i++){
            pt p1=points[i], p2=points[(i+1)%n];
            double dist = abs(p1.x-p2.x)+abs(p2.y-p1.y);
            perimeter+=dist;
            min_edg=min(min_edg, dist);
      }
      double area=calcarea(points);
      double hlim = (min_edg-0.1)/2.0, maxvol=0.0;

      if(hlim >= 0.1){
            for(double h=0.1; h<= hlim+1e-9;h+=0.1){
                  double basearea=area-(perimeter*h)+(4.0*h*h);
                  double vol = basearea*h;
                  maxvol=max(vol,maxvol);
            }
      }
      cout<<fixed<<setprecision(2)<<maxvol<<endl;
      return 0;
}