#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    int n;
	    cin>>n;
	    cin>>s;
	    int flag=0, cnt=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='0'){
	            flag=1;
	        }
	        if(flag && s[i]=='1') cnt++;
	    }
	    cout<<cnt<<endl;
	}
}
