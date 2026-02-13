#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, x, y;
    cin >> n >> x >> y;

    if (n == 0){
        cout<<0<<"\n";
        return 0;
    }
    long long f =min(x,y); 
    long long low=f,high= f+max(x,y)*n;

    while (low <high){
        long long mid = low+(high-low)/2;
        long long produced =1+(mid-f)/x + (mid-f)/y;
        if (produced >=n){
            high = mid;
        }else{
            low = mid + 1;
        }   
    }
    cout << low << "\n";
    return 0;
}
