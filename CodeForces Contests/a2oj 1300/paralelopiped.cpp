#include<bits/stdc++.h>
using namespace std;
int main(){
      int a, b, c;
      cin>>a>>b>>c;
      float A = sqrt(1.0*a*b)/sqrt(1.0*c);
      float B = sqrt(1.0*b*c)/sqrt(1.0*a);
      float C = sqrt(1.0*a*c)/sqrt(1.0*b);
      cout<<4*(A+B+C)<<endl;
}