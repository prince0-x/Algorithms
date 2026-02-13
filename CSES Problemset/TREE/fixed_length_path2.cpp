#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAXN 200005
using namespace std;

vector<int>tree[MAXN];
int n, k1, k2;
ll answer =0;

int getSuffixValue(int index, deque<int>&suff){
      if(index < 0) return suff[0];
      if(index >= suff.size()) return 0;
      return suff[index];
}
void mergeSuffArr(deque<int>&suffA, deque<int>&suffB){
      if(suffA.size() < suffB.size()){
            swap(suffA, suffB);
      }
      for(int i=0;i<suffB.size(); i++){
            answer += 1LL * (getSuffixValue(i, suffB) - getSuffixValue(i + 1, suffB)) *(getSuffixValue(k1 - i, suffA) - getSuffixValue(k2 - i + 1,suffA));
      }
      for(int i=0;i<suffB.size(); i++){
            suffA[i]+=suffB[i];
      }
}
deque<int>suffChild(int node, int parent){
      deque<int>suffixParent{1};
      for(auto child: tree[node]){
            if(child != parent){
                  deque<int>suffixCh= suffChild(child, node);
                  suffixCh.push_front(suffixCh.front());
                  mergeSuffArr(suffixParent, suffixCh);

            }
      }
      return suffixParent;
}




int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      cin>> n>>k1 >>k2;
      for(int i=1;i<n; i++){
            int u, v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
      }
      suffChild(1, -1);
      cout<<answer<<endl;
      return 0;
}
