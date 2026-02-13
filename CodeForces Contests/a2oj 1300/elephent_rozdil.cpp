#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, mini=-1, minval=INT_MAX, cnt=0;
      cin>>n;
       for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val < minval) {
            minval = val;
            mini = i;
            cnt = 1;
        } else if (val == minval) {
            cnt++;
        }
    }
    if (cnt > 1) cout << "Still Rozdil\n";
    else cout << mini+1 << "\n";
      return 0;
}