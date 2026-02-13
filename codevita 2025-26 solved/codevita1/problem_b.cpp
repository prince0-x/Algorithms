#include <bits/stdc++.h>
using namespace std;

string r(){
    string s;
    getline(cin,s);
    return s;
}

void nxt(const vector<int>& a,queue<vector<int>>& q,map<vector<int>,int>& mp,int c){
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            vector<int> cut,rem;
            for(int x=0;x<n;x++){
                if(x>=i&&x<=j)cut.push_back(a[x]);
                else rem.push_back(a[x]);
            }
            for(int k=0;k<=(int)rem.size();k++){
                vector<int> b=rem;
                b.insert(b.begin()+k,cut.begin(),cut.end());
                if(mp.find(b)==mp.end()){
                    mp[b]=c+1;
                    q.push(b);
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    string t;
    getline(cin,t);
    vector<string> a(n),b(n);
    map<string,int> m;
    getline(cin,t);
    for(int i=0;i<n;i++)a[i]=r();
    getline(cin,t);
    for(int i=0;i<n;i++){
        b[i]=r();
        m[b[i]]=i;
    }
    vector<int> s(n),g(n);
    for(int i=0;i<n;i++){
        s[i]=m[a[i]];
        g[i]=i;
    }
    if(s==g){
        cout<<0<<endl;
        return 0;
    }
    queue<vector<int>> q1,q2;
    map<vector<int>,int> d1,d2;
    q1.push(s);
    d1[s]=0;
    q2.push(g);
    d2[g]=0;
    while(!q1.empty()&&!q2.empty()){
        int c1=d1[q1.front()];
        vector<int> v1=q1.front();
        q1.pop();
        if(d2.count(v1)){
            cout<<c1+d2[v1]<<endl;
            return 0;
        }
        if(c1>=4)continue;
        nxt(v1,q1,d1,c1);
        int c2=d2[q2.front()];
        vector<int> v2=q2.front();
        q2.pop();
        if(d1.count(v2)){
            cout<<c2+d1[v2]<<endl;
            return 0;
        }
        if(c2>=4)continue;
        nxt(v2,q2,d2,c2);
    }
    return 0;
}
